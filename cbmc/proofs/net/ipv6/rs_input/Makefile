# Defines the root of the project.
# Be aware of how many directories deep you go!
#ROOT = ../../../../../..
ROOT = /home/owen/Documents/projects/surf/forks/contiki-ng

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/ipv6/uip-nd6.c $(ROOT)/os/net/ipv6/uipbuf.c

# Harness to utilize, omit the extension!
H_ENTRY = rsi

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset  rs_input.8:10

# Extra header defintiions to be passed during compilation
H_DEF = -D"UIP_CONF_ROUTER=1" -D"UIP_CONF_ND6_SEND_RA=1"

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../../Makefile.include
