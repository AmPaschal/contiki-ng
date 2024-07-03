# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/app-layer/mqtt/mqtt.c

# Harness to utilize, omit the extension!
H_ENTRY = ppv

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = -D'UIP_CONF_BUFFER_SIZE=10' -D'MQTT_TCP_OUTPUT_BUFF_SIZE=512' -D'MQTT_TCP_INPUT_BUFF_SIZE=512' -D'MQTT_INPUT_BUFF_SIZE=512'

# Extra CBMC includes to be passed during compilation
H_INC = -I$(ROOT)/os/net/ipv6/

# Include our special build file
include ../../../Makefile.include
