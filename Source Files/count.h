// Calcula la frecuencia de las palabras 
#pragma once
// BUILT-IN HEADERS
#include <stdio.h>
#include <stdlib.h>
// LOCAL HEADERS
#include "models.h"
#include "utils.h" // Contiene las operaciones de cada estructura 

void Count( Words words, Cuentas *cuentas){
    /*
    Rutina que cuenta la frecuencia de las palabras
    
    ARGUMENTOS
    __________
    words:Words - Estructura donde se almacenan las palabras del texto
    cuentas:Cuentas* - Estructura donde se almacenaran las palabras con su frecuencia
    */

    // cuenta representa la frecuencia de las plabras, bandera vale 0 si una palabra es igual a otra
    int cuenta, bandera;

    // Estructura auxiliar pa hacerle pushBack a la estructura cuentas
    Cuenta cuenta_ar={NULL, 0,0,0};

    // Se empiezan a contar las palabras que hay en words
    for(int i=0; i<words.tam; i++){
        cuenta = 0;
        for(int j=i; j<words.tam; j++){
            bandera = 0;
            if(GetWords(words, i).tam == GetWords(words, j).tam){
                for(int k=0; k<GetWords(words, i).tam; k++){
                    if(GetChar( GetWords(words, i), k) != GetChar( GetWords(words, j), k)){
                        bandera = 1; // las palabras no son iguales
                        break;
                    }
                }
                if(bandera == 0){
                    if(cuenta != 0){
                        RemoveWords(&words, j); // Se elimina la palabra para no contarla de nuevo
                    }
                    cuenta++; // Se aumenta la frecuencia de la palabra
                }
            }
        }
        // Hacer push back de la palabra y su frecuencia a cuentas
        cuenta_ar.cap =  GetWords(words, i).cap;
        cuenta_ar.tam =  GetWords(words, i).tam;
        cuenta_ar.ptr =  GetWords(words, i).ptr;
        cuenta_ar.count =  cuenta;
        Push_Back_Cuentas(cuentas, cuenta_ar);
        // Se reiniciar la estructura auxiliar
        cuenta_ar={NULL, 0,0,0};
    }
}