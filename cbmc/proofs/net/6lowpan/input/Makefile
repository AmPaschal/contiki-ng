# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/ipv6/sicslowpan.c $(ROOT)/os/net/packetbuf.c $(ROOT)/os/net/ipv6/uipbuf.c $(ROOT)/os/net/linkaddr.c

# Need to increace object bits due to complexity
OBJ_BITS = 10

# Number of fragement buffers
NUM_BUFF = 2

# Size of fragement buffer
BUFF_SIZE = 10

# Values plus 1 for loop unwinding

NUMM_BUFF_1 = $(shell expr $(NUM_BUFF) + 1)
BUFF_SIZE_1 = $(shell expr $(BUFF_SIZE) + 1)

# Harness to utilize, omit the extension!
H_ENTRY = input

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset add_fragment.0:3 --unwindset add_fragment.2:3 --unwindset clear_fragments.0:$(NUM_BUFF_1) --unwindset copy_frags2uip.2:$(NUM_BUFF_1) --unwindset store_fragment.0:$(NUM_BUFF_1) --unwindset timeout_fragments.0:3

# Extra header defintiions to be passed during compilation
H_DEF = -D'SICSLOWPAN_CONF_FRAGMENT_BUFFERS=$(NUM_BUFF)' -D'SICSLOWPAN_CONF_FRAGMENT_SIZE=$(BUFF_SIZE)' -D'UIP_CONF_BUFFER_SIZE=200'

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../../Makefile.include
