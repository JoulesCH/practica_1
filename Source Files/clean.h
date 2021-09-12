#pragma once
// Built in headers
#include <stdlib.h>
#include <stdio.h>
// Local headers
#include "models.h"
#include "utils.h"

void Clean(struct texto * Texto, int * lettersCount){
    
    char upper[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                        'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    char lower[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i','o', 'p',
                    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                    'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    for(int i = 0; *((Texto->ptr) + i*sizeof(char)) != '\0'; i++){
        
        // Replace uppercases
        for(int k =0; upper[k] != '\0'; k++){
            if ( *((Texto->ptr) + i*sizeof(char)) == upper[k]  ){
                *((Texto->ptr) + i*sizeof(char)) = lower[k];
            }
        }

        // Remove special characters
        if( *((Texto->ptr) + i*sizeof(char)) < 97 || *((Texto->ptr) + i*sizeof(char)) > 122 ){
            if(*((Texto->ptr) + i*sizeof(char)) == '\n' || *((Texto->ptr) + i*sizeof(char)) == 10){
                *((Texto->ptr) + i*sizeof(char)) = 32;
            }
            else if( *((Texto->ptr) + i*sizeof(char)) == ' ' || (*((Texto->ptr) + i*sizeof(char))>=160 && *((Texto->ptr) + i*sizeof(char)) <= 163) || *((Texto->ptr) + i*sizeof(char)) == 130){
                ;
            } else{
                Remove(Texto, i);
                *lettersCount = *lettersCount -1;
                i--;
            }
        }    
    }
}