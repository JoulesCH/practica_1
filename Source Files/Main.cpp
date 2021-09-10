// Built in headers
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// Local headers
#include "readfile.h"
#include "models.h"
// Constants
#define MAX_SIZE_FILE_NAME 256

int main(int argc, char * argv[]){
    // Declaration of variables
    struct texto Texto = {NULL, 0,0};
    
    // Get the file name
    char *inputFile = (char*) malloc(MAX_SIZE_FILE_NAME*sizeof(char));
    char *outputFile = (char*) malloc(MAX_SIZE_FILE_NAME*sizeof(char));
    strcpy(outputFile, "OUTPUT_");

    if(argc == 1){
        printf("Ingresa el nombre del archivo a leer: ");
        fgets(inputFile, MAX_SIZE_FILE_NAME, stdin);
        strcat(outputFile, inputFile);
    } else if(argc == 2){
        inputFile = argv[1];
        strcat(outputFile, inputFile);
    } else if(argc == 3){
        inputFile = argv[1];
        outputFile = argv[2];
    }
    // Read the file
    Texto = Read(Texto, inputFile);
    // Confirmar que el archivo no esta vacio
    printf("SALIDA: %s", Texto.ptr);
    // Limpiar el texto (caracteres especiales)
    // Contar las palabras
    // Ordenar la estructura de mayor a menor
    // Dar formato
    // Ouput del archivo

    return 0;
}