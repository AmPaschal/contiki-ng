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
and we hook into the default contiki-ng build framework.
We simply add some targets, change the compilers, and offer some configuration flags for CBMC.
A plus of this arrangement is no alterations to the contiki are required!
Thus, one can not only utilize the build system to build and run the proofs,
but the system can also be used to build contiki-ng conventionally.

We provide two targets:

- `bcmbc` - Simply builds the harness and project using CBMC compilers
- `rcbmc` - Invokes CBMC with the configured arguments on the output binaries (depends on `bcbmc`)

To invoke this build system, navigate to the proof directory you wish to build,
and run `make`. In most cases, the default target is `rcbmc`, so you can provide no arguments if this is what you want.
The resulting binaries and object files will be placed under the `build` directory.
To clean up build files (recommended to do so after each change),
simply invoke the `clean` or `distclean` targets.

To integrate a new proof harness in an already existing directory,
simply add your filename to the `CONTIKI-PROJECT` variable, omitting the extension and space separated.

To create a new proof directory, simply copy the `Makefile.template` to this directory as `Makefile`,
add your files to the `CONTIKI-PROJECT` variable, and if you break the structure be sure to update the
variables pointing to the root path, and the include statements.

## Writing Harnesses

This system requires a few thing from your harnesses.
For one, your harness MUST include `dummy_proc.h`.
This file defines a dummy process that does nothing, 
which if omitted will result in a linking error.
CBMC will not consider this process, so this is here as a stub to get everything compiled.
If your harness is testing this functionality, simply omit the header and do what you like!
Otherwise, your process and the dummy process may conflict and cause trouble.

Second, your harness file MUST include a function with the following definition:

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
- Alter CBMC flags (not just use defaults)
- Maybe implement cbmc-report viewer instead of just printing output (targets would be cool)
