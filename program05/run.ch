#!/bin/bash

avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
avr-gcc -mmcu=atmega328p led.o -o led
avr-objcopy -O ihex -R .eeprom led led.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACMO -b 115200 -U flash:w:led.hex

gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx
