// escribir el archivo
#pragma once
// BUILT-IN HEADERS
#include <stdio.h>
#include <stdlib.h>

// LOCAL HEADERS
#include "models.h"
#include "utils.h" // Contiene las operaciones de cada estructura 

void Write(Cuentas cuentas, char * outputFile){
    /*
    Rutina que escribe el archivo del diccionario
    
    ARGUMENTOS
    __________
    cuentas:Cuentas - Estructura donde se almacenan las palabras con su frecuencia
    outputFIle:char* - Nombre del archivo de salida
    */

    // se inicializan las variables
    FILE * fp;
    int espacios = 30, k = 0;
    fp = fopen(outputFile, "w+");
    // se crean los encabezados (titulos) del archivo
    fprintf(fp, "Palabra");
    for(int j=0; j<espacios-7;j++ ){
        fprintf(fp, " ");
    }
    fprintf(fp, "No. de incidencias");

    // se empieza a llenar el archivo usando fprintf
    for(int i=0; i< cuentas.tam; i++){
        k++;
        if(*GetCuenta(cuentas, i).ptr != 0){ // si el caracter no es un espacio
            if(k>99)
                fprintf(fp,"\n%d. %s ", k,GetCuenta(cuentas, i).ptr );
            else if(k>9 )
                fprintf(fp,"\n %d. %s ", k,GetCuenta(cuentas, i).ptr );
            else
                fprintf(fp,"\n  %d. %s ", k,GetCuenta(cuentas, i).ptr );
            
            for(int j=0; j<espacios-GetCuenta(cuentas, i).tam;j++ ){ // espacios relativos al tamanio de la palabra
                fprintf(fp, " ");
            }
            
            fprintf(fp, "%d", GetCuenta(cuentas, i).count );
        }
        
    }
    fclose(fp);

    // Creacion del archivo json

    FILE * json;
    json = fopen("output.json", "w+");
    fprintf(json, "{");
    for(int i=0; i< cuentas.tam; i++)
        if(*GetCuenta(cuentas, i).ptr != 0){
            fprintf(json,"\n\t%c%s%c: %d", 34, GetCuenta(cuentas, i).ptr, 34, GetCuenta(cuentas, i).count );
            if (i!= cuentas.tam-1)
                fprintf(json, ",");
        }
    fprintf(json, "\n}");
    fclose(json);
}

