#pragma once
// Built in headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include "models.h"
#include "utils.h"

struct texto Read(struct texto Texto, char * fileName){
    char ch;
    FILE *fp;

    fp = fopen(fileName, "r"); 

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF)
        Texto = Push_Back(Texto, ch);

    fclose(fp);
    return Texto; 
}


