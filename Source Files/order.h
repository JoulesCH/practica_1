// Ordenar la estructura Cuentas de mayor a menor frecuencia
#pragma once
// BUILT-IN HEADERS
#include <stdio.h>
#include <stdlib.h>
// LOCAL HEADERS
#include "models.h"
#include "utils.h" // Contiene las operaciones de cada estructura 

void Order(Cuentas * cuentas){
    /*
    Rutina que Ordena la estructura Cuentas de mayor a menor frecuencia
    
    ARGUMENTOS
    __________
    cuentas:Cuentas*- Estructura donde se almacenan las palabras del texto
    */

    // Se inicializa una estructura Cuenta que sirve como auxiliar para hacer el cambio
    Cuenta aux = {NULL, 0, 0, 0};

    // Se utiliza Bubble Sort para hacer el ordenamiento
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