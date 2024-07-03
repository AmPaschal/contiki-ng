# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/ipv6/uip6.c $(ROOT)/os/net/ipv6/uipbuf.c $(ROOT)/cbmc/include/drivers/cbmc_routing.c
#$(ROOT)/os/net/routing/nullrouting/nullrouting.c
OBJ_BITS = 13

# ROUTE_DRIVER = NETSTACK_CONF_ROUTING=cbmcrouting_driver

# Harness to utilize, omit the extension!
H_ENTRY = uipp

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --havoc-undefined-functions --unwind 1 --unwindset uip_process.24:10 --unwindset uip_process.32:9 --unwindset uipbuf_get_last_header.0:10 --unwindset ext_hdr_options_process.6:10 --unwindset uip_process.39:10 --unwindset uip_process.40:21 --unwindset uip_process.43:11 --unwindset uip_process.45:20 --unwindset uip_process.45:5 --unwindset uip_process.49:5 --unwindset uip_process.50:5 --unwindset uip_process.51:5 --unwindset uip_process.52:5 --unwindset uip_process.53:5 --unwindset uip_init.0:21 --unwindset uip_init.1:11 --unwindset uip_init.2:9
#--havoc-undefined-functions
# Extra header defintiions to be passed during compilation
H_DEF = -D'UIP_CONF_BUFFER_SIZE=200' -D'UIP_CONF_TCP=1' -D'NETSTACK_CONF_ROUTING=cbmcrouting_driver'

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../../../Makefile.include
