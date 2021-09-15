// BUILT-IN HEADERS
#include <stdlib.h> // para malloc
#include <string.h> // unicamente para strcat
#include <stdio.h> 
#include <wchar.h> // para usar caracteres especiales
#include <locale.h>

// LOCAL HEADERS
#include "models.h" // definicion de estructuras usadas
#include "readfile.h" // leer el archivo
#include "clean.h" // limpiar caracteres especiales
#include "split.h"  // dividir el texto en plabras
#include "count.h" // contar las plabras
#include "order.h" // ordenar de mayor a menor frecuencia
#include "writefile.h" // escribir el archivo

#define MAX_SIZE_FILE_NAME 256

int main(int argc, char * argv[]){ // Se pide argv para recibir los nombres de entrada y salida de los archivos
    
    // Configurar el uso de acentos
    setlocale(LC_ALL, "");

    // Inicializacion de la estructura que contiene el texto
    struct texto Text = {NULL, 0,100};
    Text.ptr = (char*) malloc(100*sizeof(char));
    int lettersCount; // Contendra el numero de letras en el archivo


    // Inicializacion de los nombres del archivo de entrada y de salida
    char *inputFile = (char*) malloc(MAX_SIZE_FILE_NAME*sizeof(char));
    char *outputFile = (char*) malloc(MAX_SIZE_FILE_NAME*sizeof(char));
    strcpy(outputFile, "OUTPUT_");
    
    if(argc == 1){ //Si el usuario no ingresa ningun argumento, se le solicita el nombre de archivo a leer
        printf("Ingresa el nombre del archivo a leer: ");
        fgets(inputFile, MAX_SIZE_FILE_NAME, stdin);
        inputFile[strlen(inputFile)-1]='\0';
        // Se crea el nombre de archivo de salida, con el formato OUTPUT_nombreDelArchivoALeer.txt
        strcat(outputFile, inputFile);
    } else if(argc == 2){ // Si el usuario ingresa un argumento, se toma como el nombre de archivo a leer
        inputFile = argv[1];
        // Se crea el nombre de archivo de salida, con el formato OUTPUT_nombreDelArchivoALeer.txt
        strcat(outputFile, inputFile);
    } else if(argc == 3){ 
        // Si el usuario ingresa dos argumentos, se toma el primero como el nombre de archivo a leer
        // y el segundo como el nombre de archivo de salida
        inputFile = argv[1];
        outputFile = argv[2];
    }

    // Se lee el archivo y se almacena en la estructura Text
    Text = Read(Text, inputFile, &lettersCount);
    // Se revisa que el archivo no este en blanco
    if(Text.ptr == NULL){
        printf("Archivo vacio");
        return 0;
    }
    
    // limpiar caracteres especiales
    Clean(&Text, &lettersCount);

    // Se inicializa la estructura que contendra las palabras
    Words words ={NULL, 0, lettersCount} ; 
    words.ptr  = (Word * ) malloc(lettersCount*sizeof(Word));
    // se divide el texto en palabras y se libera Text.ptr
    Split(Text, &words, lettersCount); 
    free(Text.ptr);
    
    // Se inicializa la estructura que contendran las palabras con su frecuencia
    Cuentas cuentas ={NULL, 0, lettersCount*10} ; 
    cuentas.ptr  = (Cuenta * ) malloc(lettersCount*10*sizeof(Cuenta));
    
    // se cuentas las palabras y se libera words.ptr
    Count(words, &cuentas);
    free(words.ptr);
    
    // se ordena de mayor a menor frecuencia
    Order(&cuentas);

    // se crea el archivo de salida, escribiendolo y liberando cuentas.ptr
    Write(cuentas, outputFile);
    free(cuentas.ptr);

    return 0;
}