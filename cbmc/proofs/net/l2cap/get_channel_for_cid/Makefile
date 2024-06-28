# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/mac/ble/ble-l2cap.c $(ROOT)/os/net/packetbuf.c $(ROOT)/os/net/linkaddr.c

# Harness to utilize, omit the extension!
H_ENTRY = gcc

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = 

# Extra CBMC includes to be passed during compilation
H_INC = -I..

# Include our special build file
include ../../../Makefile.include
