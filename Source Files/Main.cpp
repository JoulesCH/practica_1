// Built in headers
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
// Local headers
#include "readfile.h"
#include "models.h"
#include "count.h"
#include "split.h"
#include "clean.h"
// Constants
#define MAX_SIZE_FILE_NAME 256

int main(int argc, char * argv[]){
    // Using accents
    setlocale(LC_ALL, "");
    // Declaration of variables
    struct texto Text = {NULL, 0,100};
    Text.ptr = (char*) malloc(100*sizeof(char));

    int lettersCount;
    // Get the file name
    char *inputFile = (char*) malloc(MAX_SIZE_FILE_NAME*sizeof(char));
    char *outputFile = (char*) malloc(MAX_SIZE_FILE_NAME*sizeof(char));
    strcpy(outputFile, "OUTPUT_");
    
    if(argc == 1){
        printf("Ingresa el nombre del archivo a leer: ");
        fgets(inputFile, MAX_SIZE_FILE_NAME, stdin);
        inputFile[strlen(inputFile)-1]='\0';    
        strcat(outputFile, inputFile);
    } else if(argc == 2){
        inputFile = argv[1];
        strcat(outputFile, inputFile);
    } else if(argc == 3){
        inputFile = argv[1];
        outputFile = argv[2];
    }
    // Read the file
    Text = Read(Text, inputFile, &lettersCount);
    // Check if the file is blank
    if(Text.ptr == NULL)
        printf("Archivo vacio");
    //Clean text
    Clean(&Text, &lettersCount);

    // Split the text into struct array of char[]
    Words words ={NULL, 0, lettersCount} ; 
    words.ptr  = (Word * ) malloc(lettersCount*sizeof(Word));

    Split(Text, &words, lettersCount); 
    
    // Count the words
    Count(words);
    // Order the string array
    // Formating
    // Ouput file
    free(Text.ptr);
    free(words.ptr);

    return 0;
}