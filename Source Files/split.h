// Divide el texto en palabras
#pragma once

// LOCAL HEADERS
#include "models.h"
#include "utils.h" // Contiene las operaciones de cada estructura 
// BUILT-IN HEADERS
#include <stdio.h>
#include <stdlib.h>

void Split(struct texto Texto, Words * words, int lettersCount){
        /*
        Rutina que divide el texto en palabras
        
        ARGUMENTOS
        __________
        Texto:struct texto - Estructura donde se almacenan los caracteres del texto
        words:Words* - Estructura donde se almacenaran las palabras 
        lettersCOunt: int - COntiene el numero de caracteres deñ texto
        */

        // Se inicializan las variables que permiten acotar los caracteres de una palabra,el tamanio de la palabra y el numero de palabras
        int wordSize = -1, inicio , final = -1, wordCount = 0;
        Word word={NULL,0,0};
        // Se recorre sobre los caracteres del texto 
        for(int i = 0; i <= lettersCount; i++){
                wordSize ++; 
                if(*(Texto.ptr + i*sizeof(char)) == ' '  || i == lettersCount ){ // si se llega a un espacio entonces hubo una palabra antes
                        // Se acotan los caracteres de la palabra y se aparta memoria
                        inicio = final+1;
                        final = i;
                        word.cap = wordSize+1;
                        word.ptr = (char*)malloc((wordSize+1)*sizeof(char)); // +1 para agregar el caracter nulo

                        // Se aniaden los caracteres a la estructura auxiliar
                        for(int j = inicio; j<final; j++){
                                Push_Back_Word(&word,*(Texto.ptr + j*sizeof(char)) );
                        }
                        Push_Back_Word(&word, '\0' ); // al final se le agrega un caracter nulo

                        // Se agrega la estructura auxiliar a words
                        Push_Back_Words(words, word);

                        // se reinicia la estructura auxiliar, se asigna -1 a wordSize  y se aumenta la cuenta de palabras
                        word={NULL,0,0};
                        wordSize = -1;
                        wordCount++;
                }               
        }

}

