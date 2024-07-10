# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/mac/ble/ble-l2cap.c $(ROOT)/os/net/packetbuf.c

# Harness to utilize, omit the extension!
H_ENTRY = ilc

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset get_channel_for_addr.0:2

# Extra header defintiions to be passed during compilation
H_DEF = 

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../../Makefile.include
