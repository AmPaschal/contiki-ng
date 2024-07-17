"""
Generates patches for relevant files

This script will automatically generate patches for the
source files that are linked in.
It will utilize git and will generate these files based upon
deviations from the committed version of the file.

The user MUST specify the type of patch this script will be generating:

- Req - Patches that are required for the harness to run, always get applied
- CVE - Patches for reintroducing the vulnerability, optional
- Vul - Patches for removing newfound vulnerable behavior, optional

This script should be ran once the necessary changes have been made,
and again the user MUST specify the patch type when running.
Users must also specify a makefile to consider,
which will be used to find and generate patches for the makefile.
We will also use this directory to store and organize patches.
"""

from typing import Dict

import argparse
import subprocess
import re

from pathlib import Path

# Parent directory to place patches in
PARENT_DIR = "patch"

# Directory to place required paths
REQ_DIR = "required"

# Directory to place CVE related patches
CVE_DIR = "cves"

# Directory to place vulnerability related patches
VUL_DIR = "vulns"

# Name of makefile
MAKEN = "Makefile"

# Path extension to utilize
EXTENSION = ".patch"

# Ints used for internal operation mapping:
APPLY = 0
REVERT = 1
RESET = 2

# Line separator to utilize
SEP = "+=====================================================+"

##
# Regex
##

ASSIGNMENT = re.compile(r"^\s*(\S*\w\S*)\s*=\s*(.*)$")


def parent_dir() -> Path:
    """
    Returns path to parent directory.

    We MUST be in a git repo for this to work correctly.

    Returns:
        Path: Path to parent directory
    """

    return Path(subprocess.run("git rev-parse --show-toplevel", capture_output=True, shell=True).stdout.rstrip().decode())


def required_dir(path: Path) -> Path:
    """
    Determines path to required patch dir,
    given parent directory.

    Args:
        path (Path): Parent path

    Returns:
        Path: Path to required patch dir
    """

    return path / Path(PARENT_DIR) / Path(REQ_DIR)


def cve_dir(path: Path) -> Path:
    """
    Determines path to CVE patch dir,
    given parent directory.

    Args:
        path (Path): Parent path

    Returns:
        Path: Path to CVE patch dir
    """

    return path / Path(PARENT_DIR) / Path(CVE_DIR)


def vuln_dir(path: Path) -> Path:
    """
    Determines path to vulnerability patch dir,
    given parent directory.

    Args:
        path (Path): Parent path

    Returns:
        Path: Path to vulnerability patch dir
    """

    return path / Path(PARENT_DIR) / Path(VUL_DIR)


def create_patch(file: Path) -> str:
    """
    Creates a patch of the given file.

    We generate a patch file based upon the changes
    from the working tree.
    We return the contents of this diff as a string,
    which can then be saved or utilized wherever.

    Args:
        file (Path): Path to file to generate diff for

    Returns:
        str: File diff
    """
    
    # Call git and capture output:

    out = subprocess.run(f"git diff --patch {file}", capture_output=True, shell=True)

    # Return process output:

    return out.stdout.decode()


def apply_patch(file: Path) -> str:
    """
    Applies the patch in the given file.

    We ask git to consider and apply a path at the given path.
    The patch file path should be absolute,
    and the file MUST be of type .patch,
    otherwise this function will ignore it.

    Args:
        file (Path): Path to patch file

    Returns:
        str: Git output
    """

    # Get path to original file:

    fpath = extract_filename_patch(file)

    # Call git and apply patch:

    out = subprocess.run(f"patch --no-backup-if-mismatch -f -r /dev/null -p1 -i {file} {fpath}", capture_output=True, shell=True)

    return out.stdout.decode()


def revert_patch(file: Path) -> str:
    """
    Reverts the patch in the given file.

    We ask git to consider and revert a patch at the given path.
    The path file path should be absolute,
    and the file MUST be of type .patch,
    otherwise this function will ignore it.

    Args:
        file (Path): Path to patch file

    Returns:
        str: Git output
    """

    # Get path to original file:

    fpath = parent_dir() / extract_filename_patch(file)

    # Call git and apply patch:

    out = subprocess.run(f"patch --no-backup-if-mismatch -f -R -r /dev/null -p1 -i {file} {fpath}", capture_output=True, shell=True)

    return out.stdout.decode()


def reset_file(file: Path) -> str:
    """
    Resets the given file to the latest working commit,
    reverting all changes done.

    We ask git to 'restore' the file,
    which will preform a hard reset and revert the file
    back to it's last committed state.

    This function can be very destructive!

    Args:
        file (Path): Path to file to reset

    Returns:
        str: Git output
    """

    # Call git and reset file:

    out = subprocess.run(f"git restore {file}", capture_output=True, shell=True)

    return out.stdout.decode()


def recur_patch(path: Path, oper: int) -> list[Path]:
    """
    Does something to all patches in the given directory.

    We search the directory for all files
    that have the necessary extension.
    We do this search recursively.

    Users must supply an operation to preform,
    and they should do so using the operation constants.
    
    Args:
        path (Path): Directory to search in
        oper (int): Operation to preform

    Returns:
        list[Path]: List of paths considered
    """

    plist: list[Path] = []

    # Iterate over contents of required directory:

    for patch in path.rglob(f"*.{EXTENSION}"):

        # Add path to final list:

        plist.append(patch)

        if oper == APPLY:

            # Apply required patch:

            apply_patch(patch)

        if oper == REVERT:

            # Revert required patch:

            revert_patch(patch)


def extract_filenames_make(path: Path) -> list[Path]:
    """
    Extracts a list of patchable files from the makefile.

    We look for the section that links in source files,
    and pull the file names from there.
    We also try to determine the root directory,
    which we will use to reconstruct and make paths that are absolute.

    Args:
        path (Path): Path to parent directory

    Returns:
        list[Path]: List of files to work with
    """

    root: Path = None
    files: list[str] = []

    final_files: list[Path] = []

    # Get makefile file handle:

    with open(path / Path(MAKEN), "r") as file:

        # Find relevant lines:

        for line in file.readlines():

            # Determine if this line defines link files:

            if line.startswith("LINK"):

                # We have our line, extract the content

                cont = ASSIGNMENT.match(line)[2]

                # Save contents, split by whitespace:

                files = cont.split(" ")

                continue

            # Determine if this line defines root:

            if line.startswith("ROOT"):

                # We have our line, extract the content:

                root = Path(ASSIGNMENT.match(line)[2])
    
    # Determine if we have enough info to continue:

    if root and files:

        # Iterate over paths:

        for path in files:

            # Determine total path:

            tpath = Path(path.replace("$(ROOT)/", ''))

            # Make absolute and add to list:

            final_files.append(parent_dir() / tpath)

    # Return found files:

    return final_files


def extract_filename_patch(path: Path) -> Path:
    """
    Extracts the target filename from a patch file.

    Given a patch file,
    this function will return the path to the file that is being manipulated.

    Args:
        path (Path): Path to patch file

    Returns:
        Path: Path to file being manipulated
    """

    with open(path, "r") as file:

        # Read until we hit the first modifier:

        for line in file.readlines():

            # Determine if we hit modifier '---':

            if line.startswith("---"):

                # Found target, construct path:

                return (parent_dir() / Path(line.split("--- a/")[1].rstrip())).absolute()


def create_ptable(path: Path) -> Dict[Path, Path]:
    """
    We create a table matching files to patches.

    We iterate over the provided patch directory,
    extract the file being patched, and map it to a patch file.

    This table is used to verify patches are available
    for the given files, and is used elsewhere to preform the patch operation.

    Args:
        path (Path): Path to patch directory

    Returns:
        Dict[Path, Path]: Dictionary matching files to patches
    """

    pdict: Dict[Path, Path] = {}

    # Iterate over patch files:

    for file in path.rglob(f"*.{EXTENSION[1:]}"):

        # Extract the file info:

        pfile = extract_filename_patch(file)

        # Add to dict:

        pdict[pfile] = file

    # Return table:

    return pdict


def print_pinfo(oper: str, rpatch: Dict[Path, Path], cpatch: Dict[Path, Path], vpatch: Dict[Path, Path]):
    """
    Prints info on the patches to be applied

    Args:
        oper (str): Operation to preform
        rtable (Dict[Path, Path]): Dictionary of required patches
        ctable (Dict[Path, Path]): Dictionary of CVE patches
        vtable (Dict[Path, Path]): Dictionary of vulnerability patches
    """

    print("+=====================================================+")
    print(f" --== [ Patch {oper} ] ==--")

    print(f"{oper}ing [{len(rpatch)}] required patches...")

    for p in rpatch:

        print(f"=-= {p} - {rpatch[p]}")

    if args.cve:

        print(f"{oper}ing [{len(cpatch)}] CVE patches:")

        for p in cpatch:

            print(f"=-= {p} - {cpatch[p]}")

    if args.vuln:

        print(f"{oper}ing [{len(vpatch)}] vulnerability patches:")

        for p in vpatch:

            print(f"=-= {p} - {vpatch[p]}")


def print_rinfo(files: list[Path]):
    """
    Prints info on the files being reset.

    Args:
        files (list[Path]): Files to reset
    """

    print(f" --== [ File Info ] ==--")
    print(f"Considering [{len(files)}] files...")

    for f in files:

        print(f"=-= {f}")


if __name__ == "__main__":

    # Ran as script

    parser = argparse.ArgumentParser(description="CBMC Patch Applier",
                                     epilog="something...")
    
    # Define required parent directory:

    parser.add_argument('path', help='Path to directory containing proof and makefile', default=Path(__file__), nargs='?')

    ##
    # Operation to preform - apply, revert, reset, create
    ##

    oper = parser.add_mutually_exclusive_group(required=True)

    oper.add_argument("-a", "--apply", help="Applies any relevant patches", action='store_true')
    oper.add_argument("-rv", "--revert", help="Reverts any relevant patches", action='store_true')
    oper.add_argument("-rs", "--reset", help="Resets any relevant patches", action='store_true')
    oper.add_argument("-c", "--create", help="Creates patches based upon target files", action="store_true")
    oper.add_argument("-i", "--info", help="Just shows info on available patches", action="store_true")

    ##
    # Files to utilize
    # By default, we pull files from the makefile
    ##

    files = parser.add_argument_group("File Options", "Arguments for choosing files to operate on")

    files.add_argument("-nm", "--no-extract", help="Disables makefile file extraction or proof file extraction", action="store_true")
    files.add_argument("-af", "--add-file", help="Adds a file to consider", action='append', default=[])
    files.add_argument("-rf", "--remove-file", help="Removes a file from consideration", action='append', default=[])

    ##
    # Type of patch to work with - required, CVE, vulnerability
    # Required is implied and will always be applied UNLESS we are creating patches.
    ##

    parser.add_argument("-cv", "--cve", help="Works with CVE related patches", action='store_true')
    parser.add_argument("-vb", "--vuln", help="Works with vulnerability related packets", action='store_true')

    args = parser.parse_args()

    # Get parent path:

    ppath = args.path

    # Construct patch tables:

    rpatch = create_ptable(required_dir(ppath))
    cpatch = create_ptable(cve_dir(ppath))
    vpatch = create_ptable(vuln_dir(ppath))

    # Extract files from makefile, add good files:

    rmfiles: list[Path] = []
    mfiles: list[Path] = args.add_file

    if not args.no_extract:

        mfiles += extract_filenames_make(ppath)

    # Make all files absolute:

    for num, file in enumerate(mfiles):

        mfiles[num] = Path(file).resolve()

        if not mfiles[num].exists():

            print("! Error !")
            print(f"File [{file}] does not exist!")

            exit()

    for file in args.remove_file:

        rpath = Path(file).resolve()

        if not rpath.exists():

            print("! Error !")
            print(f"File [{rpath}] does not exist!")

            exit()

        rmfiles.append(rpath)

    # Iterate over bad files:

    for bfile in rmfiles:

        # Determine if file exists:

        if not bfile.exists():

            print(" ! Error !")
            print(f"Makefile [{bfile}] does not exist!")

            exit()

        # Remove file from patch tables:

        rpatch.pop(bfile, None)
        cpatch.pop(bfile, None)
        vpatch.pop(bfile, None)

        # Remove file from makefile list:

        mfiles.remove(bfile)

    print(SEP)

    print_rinfo(mfiles)

    # Determine list of patches to consider:

    plist: list[Dict[Path, Path]] = [rpatch]

    if args.cve:

        # Add CVE related patches:

        plist.append(cpatch)

    if args.vuln:

        # Add vulnerability related patches:

        plist.append(vpatch)

    ##
    # Determine which operation we are preforming
    ##

    if args.info:

        # We just want to show patch info

        print_pinfo("Info", rpatch, cpatch, vpatch)

    if args.apply:

        # We want to apply files, print out some info:

        print_pinfo("Apply", rpatch, cpatch, vpatch)

        # Iterate over all patches:

        for pval in plist:

            for num, patch in enumerate(pval):

                # Apply patch:

                print(f"++ [{num+1}/{len(pval)}]: {patch} - {pval[patch]}")

                print(apply_patch(pval[patch]))

    if args.revert:

        # We want to revert files, print out some info:

        print_pinfo("Revert", rpatch, cpatch, vpatch)

        # Iterate over required patches in reverse:

        for pval in plist:

            for num, patch in enumerate(reversed(pval)):

                # Revert patch:

                print(f"-- [{num+1}/{len(pval)}]: {patch} - {pval[patch]}")

                print(revert_patch(pval[patch]))

    if args.reset:

        # We want to reset files, no patches included:

        print_rinfo(mfiles)

        # Iterate over files:

        for num, f in enumerate(mfiles):

            # Reset the file:

            print(f"// [{num+1}/{len(mfiles)}]: {f}")

            reset_file(f)

    if args.create:

        print(SEP)

        # We want to create patches
        # Raise an error if multiple values are provided

        if args.cve and args.vuln:

            print("! Bad Arguments !")
            print("When creating patches, can't specify CVE and vulnerability")

            exit()

        # Determine path to save to:

        spath: Path = required_dir(ppath)

        if args.cve:

            print("Creating CVE patches...")

            spath = cve_dir(ppath)

        elif args.vuln:

            print("Creating vulnerability patches...")

            spath = vuln_dir(ppath)

        else:

            print("Creating required patches...")

        # Create the directory:

        spath.mkdir(parents=True, exist_ok=True)

        # Generate patches for each file:

        for num, file in enumerate(mfiles):

            # Open up file to write:

            tpath = str(spath / file.name) + ".patch"

            print(f"> Creating patch [{num+1}/{len(mfiles)}] - {tpath}")

            # Get patch content:

            pout = create_patch(file)

            if not pout:

                print("  > Ignoring empty patch...")

                continue

            with open(tpath, "w") as fileh:

                # Write patch content:

                fileh.write(pout)
