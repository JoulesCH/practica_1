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
    // Se utiliza Bubble Sort para hacer el ordenamiento c.r. a las frecuencias 
    for(int i =0; i<(cuentas->tam); i++){
        for (int j = 0; j < (cuentas->tam)-i-1; j++){
            if(GetCuenta(*cuentas, j).count < GetCuenta(*cuentas, j+1).count ){
                aux = GetCuenta(*cuentas, j);
                *((cuentas -> ptr) + j*sizeof(Cuenta)) = *((cuentas -> ptr) + (j+1)*sizeof(Cuenta)); 
                *((cuentas -> ptr) + (j+1)*sizeof(Cuenta)) = aux;
                aux = {NULL, 0, 0, 0};
            }

        }
    }
    // Se utiliza Bubble Sort para hacer el ordenamiento alfabetico 
    for(int i=0; i<(cuentas->tam); i++){
        for(int j=0; j<(cuentas->tam)-1-i; j++){
            if(strcmp(GetCuenta(*cuentas, j).ptr, GetCuenta(*cuentas, j+1).ptr) > 0 && GetCuenta(*cuentas, j).count == GetCuenta(*cuentas, j+1).count ){
                aux = GetCuenta(*cuentas, j);
                *((cuentas -> ptr) + j*sizeof(Cuenta)) = *((cuentas -> ptr) + (j+1)*sizeof(Cuenta)); 
                *((cuentas -> ptr) + (j+1)*sizeof(Cuenta)) = aux;
                aux = {NULL, 0, 0, 0};
            }
        }
    }

    
}