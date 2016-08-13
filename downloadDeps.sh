#!/bin/bash
#
# This script is meant to go fetch the most recent versions of various libraries that
#   ManuvrOS has been written against. None of this is strictly required for a basic build,
#   but most real-world applications will want at least one of them.

# Make the lib directory...
mkdir lib

# JSON support via jansson...
rm -rf lib/jansson
git clone https://github.com/akheron/jansson.git lib/jansson

# FreeRTOS...
rm -rf lib/FreeRTOS_Arduino
git clone https://github.com/greiman/FreeRTOS-Arduino lib/FreeRTOS_Arduino

# MQTT, if desired.
# Note that we do special-handling here to make the build-process smoother...
rm -rf lib/paho.mqtt.embedded-c
git clone https://github.com/eclipse/paho.mqtt.embedded-c.git lib/paho.mqtt.embedded-c
cp lib/paho.mqtt.embedded-c/MQTTPacket/src/* lib/paho.mqtt.embedded-c/

# TinyCBOR...
# Note that we do special-handling here to make the build-process smoother...
rm -rf lib/tinycbor
git clone https://github.com/01org/tinycbor.git lib/tinycbor
mkdir -p lib/tinycbor/include
cp lib/tinycbor/src/*.h lib/tinycbor/include

# Avro. Again, we will shuffle things a bit to make inclusion uniform.
# Note that Avro requires jansson for JSON support.
rm -rf lib/avro
git clone https://github.com/apache/avro.git lib/avro
ln -s `pwd`/lib/avro/lang/c/src/ lib/avro/include

# mbedTLS...
rm -rf lib/mbedtls
git clone https://github.com/ARMmbed/mbedtls.git lib/mbedtls

# Telehash
rm -rf lib/telehash-c
git clone https://github.com/telehash/telehash-c.git lib/telehash-c

# Arduino libraries...

# Teensy loader...

# Teensyduino libraries...

# Return...
cd ..
