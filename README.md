# ProgrammingTechnologies

* export JAVA_HOME=/usr/lib/jvm/java-7-oracle/
* export PATH="$PATH:/usr/lib/jvm/java-7-oracle/bin:/home/aldeberan/bin:/home/aldebaran/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
* export LD_LIBRARY_PATH=$JAVA_HOME/jre/lib/amd64:$JAVA_HOME/jre/lib/amd64/server



//avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
//avr-gcc -mmcu=atmega328p led.o -o led
//avr-objcopy -O ihex -R .eeprom led led.hex
//sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:led.hex
