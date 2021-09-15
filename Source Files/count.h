#pragma once
// Built in headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include "models.h"
#include "utils.h"

void Count( Words words, Cuentas *cuentas){
    int cuenta, bandera;
    Cuenta cuenta_ar={NULL, 0,0,0};
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
                    if(cuenta != 0){
                        RemoveWords(&words, j);
                    }
                    cuenta++;
                }
            }
        }
        printf(" ");
        //cuenta_ar.ptr = (char *) malloc(GetWords(words, i).tam*sizeof(char));
        cuenta_ar.cap =  GetWords(words, i).cap;
        cuenta_ar.tam =  GetWords(words, i).tam;
        cuenta_ar.ptr =  GetWords(words, i).ptr;
        cuenta_ar.count =  cuenta;
        Push_Back_Cuentas(cuentas, cuenta_ar);
        cuenta_ar={NULL, 0,0,0};
    }
}