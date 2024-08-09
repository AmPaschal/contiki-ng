# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/ipv6/sicslowpan.c

# Number of fragement buffers
NUM_BUFF = 4

# Size of fragement buffer
BUFF_SIZE = 50

# Size of UIP buffer
UIP_BUFF_SIZE = 100

# Harness to utilize, omit the extension!
H_ENTRY = cf2u

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset copy_frags2uip.2:$(NUM_BUFF) --unwindset clear_fragments.0:$(NUM_BUFF)

# Extra header defintiions to be passed during compilation
H_DEF = 

# Extra CBMC includes to be passed during compilation
H_INC = -D'SICSLOWPAN_CONF_FRAGMENT_BUFFERS=$(NUM_BUFF)' -D'SICSLOWPAN_CONF_FRAGMENT_SIZE=$(BUFF_SIZE)' -D'UIP_CONF_BUFFER_SIZE=$(UIP_BUFF_SIZE)'

# Include our special build file
include ../../../Makefile.include
