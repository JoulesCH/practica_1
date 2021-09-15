// LIMPIEZA DEL TEXTO DE CARACTERES ESPECIALES
#pragma once
// BUILT-IN HEADERS
#include <stdlib.h>
#include <stdio.h>
// LOCAL HEADERS
#include "models.h"
#include "utils.h" // Contiene las operaciones de cada estructura 

void Clean(struct texto * Texto, int * lettersCount){
    /*
    Rutina que limpia los caracteres especiales
    
    ARGUMENTOS
    __________
    Texto:struct texto - Estructura que contiene los caracteres del texto
    lettersCount:int* - No. de caracteres en el archivo leido (se modifica cada vez que se elimina un caracter especial)
    */
    
    // Se crean arreglos paralelos para cambiar mayusculas por minusculas
    char upper[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                        'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    char lower[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i','o', 'p',
                    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                    'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    for(int i = 0; *((Texto->ptr) + i*sizeof(char)) != '\0'; i++){
        
        // Se remplazan las mayusculas por las minusculas
        for(int k =0; upper[k] != '\0'; k++){
            if ( *((Texto->ptr) + i*sizeof(char)) == upper[k]  ){
                *((Texto->ptr) + i*sizeof(char)) = lower[k];
            }
        }

        // Se quitan caracteres especiales (comas, comillas, puntos,saltos de linea, etc.)
        if( *((Texto->ptr) + i*sizeof(char)) < 97 || *((Texto->ptr) + i*sizeof(char)) > 122 ){
            if(*((Texto->ptr) + i*sizeof(char)) == '\n' || *((Texto->ptr) + i*sizeof(char)) == 10){
                *((Texto->ptr) + i*sizeof(char)) = 32; // se reemplazan los saltos de linea por espacios
            }
            else if( *((Texto->ptr) + i*sizeof(char)) == ' ' || (*((Texto->ptr) + i*sizeof(char))>=160 && *((Texto->ptr) + i*sizeof(char)) <= 163) || *((Texto->ptr) + i*sizeof(char)) == 130){
                ;
            } else{
                Remove(Texto, i);
                *lettersCount = *lettersCount -1;
                i--;
            }
        }
        // Se tratan de quitar los dobles espacios
        if( *((Texto->ptr) + (i+1)*sizeof(char)) == 32 && *((Texto->ptr) + i*sizeof(char)) == 32 ){
            Remove(Texto, i);
            *lettersCount = *lettersCount -1;
            i--;
        }

    }
}