#pragma once
// BUILT-IN HEADERS
#include <stdio.h>
#include <stdlib.h>
// LOCAL HEADERS
#include "models.h"
#include "utils.h" // Contiene las operaciones de cada estructura 

struct texto Read(struct texto Texto, char * fileName, int *tamanio){
    /*
    Funcion que lee el archivo 
    
    ARGUMENTOS
    __________
    Texto:struct texto - Estructura donde se almacenan los caracteres del texto
    fileNAme:char* - Nombre del archivo a leer
    tamanio:int* - No de caracteres que se leeran

    REGRESA
    _________
    Texto:struct texto - Estructura con los caracteres del texto almacenados
    */

    // Se lee el archivo, si no existe manda un EXIT_FAILURE
    char ch;
    FILE *fp;
    fp = fopen(fileName, "r"); 

    if (fp == NULL)
    {
        printf("No existe ese archivo\n");
        exit(EXIT_FAILURE);
    }
    // se empieza a leer caracter por carcter haciendo pushback a Texto e incrementando el tamanio
    *tamanio = 0;
    while((ch = fgetc(fp)) != EOF){
        Texto = Push_Back(Texto, ch);
        *tamanio = *tamanio+ 1;
    }
    // al final se agrega un caracter nulo para indicar que es el ultimo
    Texto = Push_Back(Texto, '\0');
    fclose(fp);
    return Texto; 
}


