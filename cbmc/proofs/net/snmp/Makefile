# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../..

PREFIX = $(ROOT)/os/net/app-layer/snmp

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(PREFIX)/snmp-engine.c $(PREFIX)/snmp-message.c $(PREFIX)/snmp-ber.c

# Harness to utilize, omit the extension!
H_ENTRY = snmp_engine

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static

# Extra header defintiions to be passed during compilation
H_DEF = -DFREERTOS_TCP_ENABLE_VERIFICATION

# Extra CBMC includes to be passed during compilation
H_INC = 

# Include our special build file
include ../../Makefile.include
