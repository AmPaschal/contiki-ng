# CBMC Proofs

This directory contains various CBMC proofs for Contiki-NG verification.
Simply navigate to a proof directory, run `make`, and watch the magic happen!

## Structure

This repo has a file structure that should be respected.
The directory this readme file is in can be considered the proof root.
THe next layer is the Contiki-NG module being tested (net, storage, sys, etc.),
the next is the file being tested, and each file represents a function from each file to be tested. 

For example, if one wants to test the `packetbuf_copyfrom` function, the path would look like:

```
net/packetbuf/packetbuf_copyfrom_harness.c
```

Of course, you do not have to respect this format (the build system can be configured to match any structure),
but it is HIGHLY recommended to do so!

## Build System

These harnesses utilize the make build system, 
and we provide a custom buildsystem specifically for CBMC.
We simply compile and link the provided files (producing a goto binary),
preform some cleaning on the goto binary, and then generate a report to be viewed.
This system does not alter the contiki-ng build system or files in any way!

We provide some targets:

- `cbmc` - Invokes CBMC on the final goto binary and preforms validation, producing a XML report
- `property` - Determines some properties of the goto binary, producing a XML report
- `coverage` - Determines code coverage of the goto binary, producing a XML report
- `report` - Creates an HTML report using the info created in the above targets
- `clean` - Removes the build directory
- `veryclean` - Removes the build directory and the report directory

The target you probably want in `report`, and this should be the default target.
All targets above will compile and link the necessary files.
The final report will be placed in `report/`.
The HTML version will be in `report/html/` and the JSON version will be in `report/json/`.
You probably want to open the index file in `report/html/index.html`.

To invoke this build system, navigate to the proof directory you wish to build,
and run `make`. In most cases, the default target is `report`, so you can provide no arguments if this is what you want.
The resulting binaries and object files will be placed under the `build` directory.
Any linked in sources will be placed under `build/gotos/`, all generated reports (XML and program output)
will be placed under `build/reports/`.
Finally, the linked, cleaned, and resulting binaries will be placed int he root of `build/`.
To clean up build files (recommended to do so after each change),
simply invoke the `clean` or `veryclean` targets.

To create a new proof directory, simply copy the `Makefile.template` to this directory as `Makefile`,
specify your harness in the `HARNESS` variable, define your link files in `LINK`, update the `ROOT` variable
if you alter the structure.

## Writing Harnesses

This system requires a few things from your harnesses.
Your harness file MUST include a function with the following definition:

```C
void harness()
```

This is where your harness code will go, and CBMC is configured to invoke this function for testing.

## Invoking CBMC

If you do not want make to invoke CBMC for you,
then you can do so manually like so:

```
cbmc --function harness [PATH]
```

Where `[PATH]` is the path to the output binary.

## TODO

Here are some TODO things for making the build system a bit more configurable:

- User-defined CBMC entry point
