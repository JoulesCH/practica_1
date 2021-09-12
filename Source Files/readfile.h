#pragma once
// Built in headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include "models.h"
#include "utils.h"

struct texto Read(struct texto Texto, char * fileName, int *tamanio){
    char ch;
    FILE *fp;
    fp = fopen(fileName, "r"); 

    if (fp == NULL)
    {
        printf("No existe ese archivo\n");
        exit(EXIT_FAILURE);
    }
    *tamanio = 0;
    while((ch = fgetc(fp)) != EOF){
        Texto = Push_Back(Texto, ch);
        *tamanio = *tamanio+ 1;
    }
    Texto = Push_Back(Texto, '\0');
    fclose(fp);
    return Texto; 
}


