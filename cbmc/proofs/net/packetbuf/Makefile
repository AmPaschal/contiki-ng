# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../..

# Harness file you wish to build
HARNESS = packetbuf_copyfrom_harness.c

# Defines file to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/packetbuf.c

# Include our special CBMC build file
include ../../Makefile.include
