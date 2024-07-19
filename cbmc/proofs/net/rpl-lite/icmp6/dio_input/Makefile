# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/routing/rpl-lite/rpl-icmp6.c $(ROOT)/os/net/ipv6/uipbuf.c

# More bits due to complexity
OBJ_BITS = 9

# Harness to utilize, omit the extension!
H_ENTRY = dio

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset dio_input.8:5

# Extra header defintiions to be passed during compilation
H_DEF = 

# Extra CBMC includes to be passed during compilation
H_INC = -I$(ROOT)/os/net/ipv6/

# Include our special build file
include ../../../../Makefile.include
