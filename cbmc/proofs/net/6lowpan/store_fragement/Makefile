# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/ipv6/sicslowpan.c $(ROOT)/os/net/packetbuf.c

# Number of fragement buffers
NUM_BUFF = 4

# Size of fragement buffer
BUFF_SIZE = 50

# Harness to utilize, omit the extension!
H_ENTRY = sf

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset store_fragment.0:$(NUM_BUFF)

# Extra header defintiions to be passed during compilation
# SICSLOWPAN_CONF_FRAGMENT_BUFFERS - Small to prevent excess memory usage
# SICSLOWPAN_CONF_FRAGMENT_SIZE - Small data size to prevetn excess memory usage
H_DEF = -D'SICSLOWPAN_CONF_FRAGMENT_BUFFERS=$(NUM_BUFF)' -D'SICSLOWPAN_CONF_FRAGMENT_SIZE=$(BUFF_SIZE)'

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../../Makefile.include
