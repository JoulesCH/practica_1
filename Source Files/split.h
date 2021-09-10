#pragma once
// Built in headers
#include <stdlib.h>
#include <stdio.h>
// Local headers
#include "models.h"
#include "utils.h"

struct words* create_words(char* word) {
        struct words* newWords = (struct words*) malloc(100*sizeof(struct words));
        if (NULL != newWords){
                newWords->str = word;
                newWords->tam = 0;
                newWords->next = NULL;
        }
        return newWords;
}

struct words* add_word(struct words* Words, char* word) {
        struct words* newWords = create_words(word);
        if (NULL != newWords) {
                newWords->next = Words;
               
        }
        return newWords;
}

struct words* Split(struct texto Texto){
        char *ch = (char*) malloc(sizeof(char));
        *ch = '\0';
        struct words* textWords = create_words(ch);
        int i = 0;
        
        struct texto word = {NULL, 0,0};

        while (1){
                *ch = Get(Texto, i);
                if(*ch == '\0'){
                        textWords = add_word(textWords, word.ptr);
                        break;
                } else if(*ch == ' ' or *ch =='\n'){
                        
                        textWords = add_word(textWords, word.ptr);
                        word = {NULL, 0,0};
                }else{
                        word = Push_Back(word, *ch);
                }
                i++;
        }
        
        return textWords;
}

