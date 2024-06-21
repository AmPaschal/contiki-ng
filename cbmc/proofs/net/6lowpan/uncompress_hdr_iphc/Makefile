# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/ipv6/sicslowpan.c $(ROOT)/os/net/packetbuf.c $(ROOT)/os/net/ipv6/uip-ds6.c

# Harness to utilize, omit the extension!
H_ENTRY = uhi

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset addr_context_lookup_by_number.0:2 --unwindset uncompress_hdr_iphc.20:2

# Extra header defintiions to be passed during compilation
H_DEF = 

# Extra CBMC includes to be passed during compilation
H_INC = 

# Need to increace object bits due to complexity...
OBJ_BITS = 10

# Include our special build file
include ../../../Makefile.include
