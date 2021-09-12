#pragma once

// Local headers
#include "models.h"
#include "utils.h"
// Built in headers
#include <stdio.h>
#include <stdlib.h>

void Split(struct texto Texto, Words * words, int lettersCount){
        int wordSize = -1, inicio , final = -1, wordCount = 0, k = 0;
        Word word={NULL,0,0};
        for(int i = 0; i <= lettersCount; i++){
                wordSize ++;
                if(*(Texto.ptr + i*sizeof(char)) == ' '  || i == lettersCount ){
                        inicio = final+1;
                        final = i;
                        word.cap = wordSize+1;
                        word.ptr = (char*)malloc((wordSize+1)*sizeof(char));
                        k = 0;
                        //printf("\n");
                        for(int j = inicio; j<final; j++){
                                Push_Back_Word(&word,*(Texto.ptr + j*sizeof(char)) );
                        //        printf("%c-", *(Texto.ptr + j*sizeof(char)));
                        }
                        Push_Back_Word(&word, '\0' );
                        //printf("\nAgregando la palabra %s", word.ptr);
                        Push_Back_Words(words, word);

                        word={NULL,0,0};
                        wordSize = -1;
                        wordCount++;
                }
                //printf("\n%d-%c, ", *(Texto.ptr + i*sizeof(char)), *(Texto.ptr + i*sizeof(char)));                
        }

}

