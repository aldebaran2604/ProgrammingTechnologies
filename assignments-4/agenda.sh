#!/bin/bash

echo Bienvenido a la MegaAgenda
fin=N
while [ $fin = no ] || [ $fin = N ] || [ $fin = n ] || [ $fin = NO ]
do
echo Introduce una Opci&#243;n
echo 1 - Agregar una entrada
echo 2 - Buscar
echo 3 - Borrar una entrada por ID
echo 4 - Modificar una entrada
echo 5 - Informaci&#243;n
echo 6 - Mostrar todas las entradas
echo 7 - Salir
read op

case $op in
1)clear
    echo Nombre:
    read nom
    echo Apellidos:
    read ape
    echo Edad
    read edad
    echo Ciudad
    read ci
    if [ -f agenda.txt ]
    then
        id=0
        while read linea
        do
        i2=`echo $linea | cut -f 5 -d:`
        if [ $i2 -le $id ]
        then
            let id=$i2+1
        fi
    done<agenda.txt
    else
    id=0
    fi
    echo $nom:$ape:$edad:$ci:$id>>agenda.txt
    ;;
2)clear
    echo Buscar por:
    echo 1 - Nombre
    echo 2 - Apellido
    echo 3 - Edad
    echo 4 - Ciudad
    echo 5 - ID
    read busc
    case $busc in

    1|2|3|4|5)
        echo Buscar:
        read pal
        while read linea
        do
            campo=`echo $linea | cut -f $busc -d :`
            if [ $campo == $pal ]
            then
                echo Nombre:`echo $linea | cut -f 1 -d :`
                echo Apellidos:`echo $linea | cut -f 2 -d :`
                echo Edad:`echo $linea | cut -f 3 -d :`
                echo Ciudad:`echo $linea | cut -f 4 -d :`
                echo ID:`echo $linea | cut -f 5 -d :`
                echo " "
            fi
        done<agenda.txt
    ;;
    *)echo OPCION INVALIDA
    ;;
    esac
;;
3)clear
    echo Introduce ID de la entrada a borrar
    read i2
    while read linea
    do
        campo=`echo $linea | cut -f 5 -d :`
        if [ $campo == $i2 ]
        then
            echo Entrada borrada
        else
            echo $linea >> agenda2.txt
        fi
    done<agenda.txt
    rm -rf agenda.txt > /dev/null
    mv agenda2.txt agenda.txt > /dev/null
;;
4)clear
    echo Introduce ID de la entrada a Modificar
    read i2
    while read linea
    do
        campo=`echo $linea | cut -f 5 -d :`
        if [ $campo == $i2 ]
        then
            nomv=`echo $linea | cut -f 1 -d :`
            apev=`echo $linea | cut -f 2 -d :`
            edadv=`echo $linea | cut -f 3 -d :`
            civ=`echo $linea | cut -f 4 -d :`
            idv=`echo $linea | cut -f 5 -d :`
        else
            echo $linea >> agenda2.txt
        fi
    done<agenda.txt
    rm -rf agenda.txt > /dev/null
    mv agenda2.txt agenda.txt > /dev/null
    echo Nombre:$nomv:
    read nom
    if [ -z $nom ]
    then
        nom=$nomv
    fi
    echo Apellidos:$apev:
    read ape
    if [ -z $ape ]
    then
        ape=$apev
    fi
    echo Edad:$edadv
    read edad
    if [ -z $edad ]
    then
        edad=$edadv
    fi
    echo Ciudad:$ci:
    read ci
    if [ -z $ci ]
    then
        ci=$civ
    fi
    echo $nom:$ape:$edad:$ci:$idv >> agenda.txt
;;
5)clear
    echo INFORMACION
    echo La base de datos contiene `cat agenda.txt | wc -l` lineas y tiene una trama&#241;o de `ls -sh -c1 | grep agenda.txt | cut -f 1 -d " "`
;;
6)echo Todas las entradas:
    while read linea
    do
        echo Nombre:`echo $linea | cut -f 1 -d :`
        echo Apellidos:`echo $linea | cut -f 2 -d :`
        echo Edad:`echo $linea | cut -f 3 -d :`
        echo Ciudad:`echo $linea | cut -f 4 -d :`
        echo ID:`echo $linea | cut -f 5 -d :`
        echo " "
    done<agenda.txt
;;
7)
    echo Deseas salir?
    read fin
;;
esac
done
