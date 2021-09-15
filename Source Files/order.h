// Built in headers
#include <stdio.h>
#include <stdlib.h>

#include "models.h"
#include "utils.h"

void Order(Cuentas * cuentas){
    Cuenta aux = {NULL, 0, 0, 0};
    for(int i =0; i<(cuentas->tam)-1; i++){
        for (int j = 0; j < (cuentas->tam)-i-1; j++){
            if(GetCuenta(*cuentas, j).count < GetCuenta(*cuentas, j+1).count ){
                aux = GetCuenta(*cuentas, j);
                *((cuentas -> ptr) + j*sizeof(Cuenta)) = *((cuentas -> ptr) + (j+1)*sizeof(Cuenta)); 
                *((cuentas -> ptr) + (j+1)*sizeof(Cuenta)) = aux;
                aux = {NULL, 0, 0, 0};
            }

        }
    }
}