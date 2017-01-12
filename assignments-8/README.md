(batch "/home/aldebaran/ProgrammingTechnologies/assignments-8/diagnostico.clp")

* export JAVA_HOME=/usr/lib/jvm/java-8-oracle/
* export PATH="$PATH:/usr/lib/jvm/java-8-oracle/bin:/home/aldeberan/bin:/home/aldebaran/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
* export LD_LIBRARY_PATH=$JAVA_HOME/jre/lib/amd64:$JAVA_HOME/jre/lib/amd64/server

gcc Sample2.c -L/usr/lib/jvm/java-8-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-8-oracle/include/ -I/usr/lib/jvm/java-8-oracle/include/linux/ -L/usr/bin/java -ljvm -o SampleJVM

gcc jni-test.c -L/usr/lib/jvm/java-8-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-8-oracle/include/ -I/usr/lib/jvm/java-8-oracle/include/linux/ -L/usr/bin/java -ljvm -o SampleNewJVM

gcc SampleRete.c -L/usr/lib/jvm/java-8-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-8-oracle/include/ -I/usr/lib/jvm/java-8-oracle/include/linux/ -L/usr/bin/java -ljvm -o SampleReteJVM

gcc assignment2.c -L/usr/lib/jvm/java-8-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-8-oracle/include/ -I/usr/lib/jvm/java-8-oracle/include/linux/ -L/usr/bin/java -ljvm -o assignment2

* export JAVA_HOME=/usr/lib/jvm/java-7-oracle/
* export PATH="$PATH:/usr/lib/jvm/java-7-oracle/bin:/home/aldeberan/bin:/home/aldebaran/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
* export LD_LIBRARY_PATH=$JAVA_HOME/jre/lib/amd64:$JAVA_HOME/jre/lib/amd64/server

gcc Sample2.c -L/usr/lib/jvm/java-7-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-7-oracle/include/ -I/usr/lib/jvm/java-7-oracle/include/linux/ -L/usr/bin/java -ljvm -o SampleJVM

gcc jni-test.c -L/usr/lib/jvm/java-7-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-7-oracle/include/ -I/usr/lib/jvm/java-7-oracle/include/linux/ -L/usr/bin/java -ljvm -o SampleNewJVM

gcc SampleRete.c -L/usr/lib/jvm/java-7-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-7-oracle/include/ -I/usr/lib/jvm/java-7-oracle/include/linux/ -L/usr/bin/java -ljvm -o SampleReteJVM

gcc assignment2.c -L/usr/lib/jvm/java-7-oracle/jre/lib/amd64/server -I/usr/lib/jvm/java-7-oracle/include/ -I/usr/lib/jvm/java-7-oracle/include/linux/ -L/usr/bin/java -ljvm -o assignment2


jar xfv jess.jar desempaquetar jess para poder utilizar la clase Rete

javac -d . -classpath .:jess.jar MainClass.java

java -classpath .:jess.jar MainClass [ assert1, assert2, assert3 ]