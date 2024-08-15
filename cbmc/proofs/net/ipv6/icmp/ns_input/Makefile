# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../../..

OBJ_BITS = 9

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/ipv6/uip-nd6.c $(ROOT)/os/net/ipv6/uipbuf.c $(ROOT)/os/net/ipv6/uip-ds6.c
#$(ROOT)/os/net/ipv6/uip-ds6-nbr.c $(ROOT)/os/net/ipv6/uip-packetqueue.c $(ROOT)/os/net/nbr-table.c
# Harness to utilize, omit the extension!
H_ENTRY = nsi

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --havoc-undefined-functions --unwindset ns_input.12:50 --signed-overflow-check --unsigned-overflow-check

# Extra header defintiions to be passed during compilation
H_DEF = -D"UIP_CONF_ND6_SEND_NA=1" -D"UIP_CONF_ND6_SEND_NA=1"

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../../../Makefile.include
