#pragma once
// Built in headers
#include <stdlib.h>
#include <stdio.h>
// Local headers
#include "models.h"
#include "utils.h"

void Split(struct texto Texto, Words * words){
        int wordSize = 0, inicio , final = -1;
        char ch;
        for(int i = 0; *(Texto.ptr + i*sizeof(char)) != '\0'; i++){
                if(*(Texto.ptr + i*sizeof(char)) == ' '){
                        inicio = final+1;
                        final = i;
                        printf("\n");
                        for(int j = inicio; j<final; j++){
                                printf("%c", *(Texto.ptr + j*sizeof(char)));
                        }
                }
                
        }
       
}

