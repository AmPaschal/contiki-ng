# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/routing/rpl-classic/rpl-ext-header.c $(ROOT)/os/net/ipv6/uipbuf.c
#$(ROOT)/os/net/ipv6/uipbuf.c $(ROOT)/os/net/routing/rpl-classic/rpl.c

# Harness to utilize, omit the extension!
H_ENTRY = srhu

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --unwind 1 --nondet-static --signed-overflow-check --unwindset uipbuf_search_header.0:10
#--nondet-static
#--unwindset uipbuf_search_header.0:500
# Extra header defintiions to be passed during compilation
H_DEF = -D'RPL_CONF_WITH_NON_STORING=1' -D'UIP_CONF_BUFFER_SIZE=100'

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../../../Makefile.include
