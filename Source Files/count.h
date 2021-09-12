#pragma once
// Built in headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include "models.h"
#include "utils.h"

void Count( Words words){
    int cuenta, bandera;
    for(int i=0; i<words.tam; i++){
        cuenta = 0;
        for(int j=i; j<words.tam; j++){
            bandera = 0;
            if(GetWords(words, i).tam == GetWords(words, j).tam){
                for(int k=0; k<GetWords(words, i).tam; k++){
                    if(GetChar( GetWords(words, i), k) != GetChar( GetWords(words, j), k)){
                        bandera = 1;
                        break;
                    }
                }
                if(bandera == 0){
                    if(cuenta != 0)
                        RemoveWords(&words, j);
                    cuenta++;
                }
            }
        }
        printf(" \n%s, cuenta: %d", GetWords(words, i).ptr, cuenta );
    }
}