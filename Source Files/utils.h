// Se contienen las operaciones de cada estructura (push back, get, remove, etc.)
#pragma once
// BUILT-IN HEADERS
#include <stdlib.h>
// LOCAL HEADERS
#include "models.h"

void Extender_ar(struct texto * arr){
    struct texto ar = *arr;
    char *p = (char*) malloc((ar.cap*10)* sizeof(char));
    
    for(int n=0; n<ar.cap;n++){
        *(p+n*sizeof(char)) = *(ar.ptr + n *sizeof(char));
    }

    ar.ptr = p;
    ar.cap = 10*ar.cap;

    *arr = ar;

}

void Contraer_ar(struct texto * arr){
    struct texto ar = *arr;
    char *p = (char*) malloc((ar.cap/2)* sizeof(char));
    
    for(int n=0; n<ar.tam;n++){
        *(p+n*sizeof(char)) = *(ar.ptr + n *sizeof(char));
    }

    ar.ptr = p;
    ar.cap = ar.cap/2;

    *arr = ar;

}

struct texto Push_Back(struct texto ar, char info){
    //Verificar si hay 
    if(ar.tam == ar.cap){
        Extender_ar(&ar);
    }
    *(ar.ptr + ar.tam * sizeof(char)) = info;
    ar.tam++;
    return ar;
    
}
void Extender_ar_word(Word * ar){
    char *p = (char*) malloc(((ar->cap)*10)* sizeof(char));
    
    for(int n=0; n<(ar->cap);n++){
        *(p+n*sizeof(char)) = *((ar->ptr) + n *sizeof(char));
    }

    (ar->ptr) = p;
    (ar->cap)= 10*(ar->cap);

}

void Push_Back_Word(Word * ar, char info){
    //Verificar si hay 
    if((ar->tam) == (ar->cap)){
        Extender_ar_word(ar);
    }
    *((ar->ptr) + (ar->tam) * sizeof(char)) = info;
    (ar->tam)++;
}
char GetChar(Word ar, int pos){
    return *((ar.ptr) + pos * sizeof(char));
}

void Extender_ar_words(Words * ar){
    Word *p = (Word*) malloc(((ar->cap)*10)* sizeof(Word));
    
    for(int n=0; n<(ar->cap);n++){
        *(p+n*sizeof(Word)) = *((ar->ptr) + n *sizeof(Word));
    }

    (ar->ptr) = p;
    (ar->cap)= 10*(ar->cap);

}

void Push_Back_Words(Words * ar, Word info){
    //Verificar si hay 
    if((ar->tam) == (ar->cap)){
        Extender_ar_words(ar);
    }
    *((ar->ptr) + (ar->tam) * sizeof(Word)) = info;
    (ar->tam)++;
}
Word GetWords(Words ar, int pos){
    return *((ar.ptr) + pos * sizeof(Word));
}
void ContraerWords(Words * arr){
    Words ar = *arr;
    Word *p = (Word*) malloc((ar.cap/2)* sizeof(Word));
    
    for(int n=0; n<ar.tam;n++){
        *(p+n*sizeof(Word)) = *(ar.ptr + n *sizeof(Word));
    }

    ar.ptr = p;
    ar.cap = ar.cap/2;

    *arr = ar;

}
void RemoveWords(Words *  ar, int pos){
    for(int n=pos; n< (ar -> tam) ;n++){
        *((ar->ptr) + n * sizeof(Word)) = *((ar->ptr) + (n+1) * sizeof(Word));
    }

    (ar->tam)--;
    //if((ar->tam) < (ar->cap)/2){
    //    ContraerWords(ar);
    //}
}
Cuenta GetCuenta(Cuentas ar, int pos){
    return *((ar.ptr) + pos * sizeof(Cuenta));
}
void Extender_ar_cuentas(Cuentas * ar){
    Cuenta *p = (Cuenta*) malloc(((ar->cap)*10)* sizeof(Cuenta));
    
    for(int n=0; n<(ar->cap);n++){
        *(p+n*sizeof(Cuenta)) = *((ar->ptr) + n *sizeof(Cuenta));
    }

    (ar->ptr) = p;
    (ar->cap)= 10*(ar->cap);

}
void InsertCuentas(Cuentas * ar, Cuenta info, int pos){
    *((ar->ptr)+ pos * sizeof(char)) = info;
}
void Push_Back_Cuentas(Cuentas * ar, Cuenta info){
    //Verificar si hay 
    if((ar->tam) == (ar->cap)){
        Extender_ar_cuentas(ar);
    }
    *((ar->ptr) + (ar->tam) * sizeof(Cuenta)) = info;
    (ar->tam)++;
}

struct texto Pop_Back(struct texto ar){
    
    ar.tam--;
    *(ar.ptr + ar.tam * sizeof(char)) = ' ';
    //Verificar si sobra mucho espacio
    if(ar.tam < ar.cap/2){
        Contraer_ar(&ar);
    }
    return ar;
    
}

struct texto Push_Front(struct texto ar, char info){
    if(ar.tam == ar.cap){
        Extender_ar(&ar);
    }
    for(int n=ar.tam; n> 0 ;n--){
        *(ar.ptr + n * sizeof(char)) = *(ar.ptr + (n-1) * sizeof(char));
    }

    *ar.ptr = info;
    ar.tam++;
    return ar;

}
struct texto Pop_Front(struct texto ar){

    for(int n=0; n< ar.tam ;n++){
        *(ar.ptr + n * sizeof(char)) = *(ar.ptr + (n+1) * sizeof(char));
    }
    ar.tam--;
    //ar.ptr = ar.ptr + sizeof(char);
    

    if(ar.tam < ar.cap/2){
        Contraer_ar(&ar);
    }
    return ar;
}

void Insert(struct texto * ar, char info, int pos){
    if((ar -> tam) == (ar->cap)){
        Extender_ar(ar);
    }

    for(int n=(ar -> tam); n> pos ;n--){
        *((ar->ptr) + n * sizeof(char)) = *((ar->ptr) + (n-1) * sizeof(char));
    }

    *((ar->ptr)+ pos * sizeof(char)) = info;
    (ar -> tam) ++;

}
void Remove(struct texto *  ar, int pos){
    for(int n=pos; n< (ar -> tam) ;n++){
        *((ar->ptr) + n * sizeof(char)) = *((ar->ptr) + (n+1) * sizeof(char));
    }

    (ar->tam)--;
    //if((ar->tam) < (ar->cap)/2){
    //    Contraer_ar(ar);
    //}
}
struct texto Set(struct texto ar, char info, int pos){
        *(ar.ptr + pos* sizeof(char)) = info;
    return ar;
}
char Get(struct texto ar, int pos){
    return *(ar.ptr + pos*sizeof(char));
}