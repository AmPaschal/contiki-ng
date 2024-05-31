# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../..

# Harness file you wish to build
HARNESS = snmp_engine_harness.c

PREFIX = $(ROOT)/os/net/app-layer/snmp

# Defines file to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(PREFIX)/snmp-engine.c $(PREFIX)/snmp-message.c $(PREFIX)/snmp-ber.c

# Include our special CBMC build file
include ../../Makefile.include
