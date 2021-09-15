#pragma once
// Built in headers
#include <stdio.h>
#include <stdlib.h>

#include "models.h"
#include "utils.h"

void Write(Cuentas cuentas, char * outputFile){
    FILE * fp;
    int espacios = 30, k = 0;
    fp = fopen(outputFile, "w+");
    fprintf(fp, "Palabra");
    for(int j=0; j<espacios-7;j++ ){
        fprintf(fp, " ");
    }
    fprintf(fp, "No. de incidencias");
    for(int i=0; i< cuentas.tam; i++){
        k++;
        if(k>99)
            fprintf(fp,"\n%d. %s ", k,GetCuenta(cuentas, i).ptr );
        else if(k>9 )
            fprintf(fp,"\n %d. %s ", k,GetCuenta(cuentas, i).ptr );
        else
            fprintf(fp,"\n  %d. %s ", k,GetCuenta(cuentas, i).ptr );
        for(int j=0; j<espacios-GetCuenta(cuentas, i).tam;j++ ){
            fprintf(fp, " ");
        }
        
        fprintf(fp, "%d", GetCuenta(cuentas, i).count );
    }
    fclose(fp);
}