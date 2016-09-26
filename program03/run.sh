#!/bin/bash

javac Sample03.java

gcc Sample03.c -L/usr/lib/jvm/java-7-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-7-oracle/include/ -I/usr/lib/jvm/java-7-oracle/include/linux/ -L/usr/bin/java -ljvm -o pruebaJVM
