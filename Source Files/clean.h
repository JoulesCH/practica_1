#pragma once
// Built in headers
#include <stdlib.h>
#include <stdio.h>
// Local headers
#include "models.h"
#include "utils.h"

void Clean(struct texto * Texto){
    char caracteres_especiales[] = {'.', ',','(',  ')', '^',
                                    '!', ';', ':', '"', '@',
                                    '%', '&', '*', '+', '-', '/',
                                    '<', '>', '=', '?', '_', 
                                    '[', ']', '{', '}', '\\', '|',
                                    '0', '1', '2', '3', '4', '5',
                                    '6', '7', '8', '9'};

    for(int i = 0; *((Texto->ptr) + i*sizeof(char)) != '\0'; i++){
        for(int j = 0; caracteres_especiales[j] != '\0'; j++){
            if ( *((Texto->ptr) + i*sizeof(char)) == caracteres_especiales[j]  ){
                    Remove(Texto, i);
            }
        }    
    }
}