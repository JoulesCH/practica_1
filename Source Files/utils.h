#pragma once
// Built in headers
#include <stdlib.h>
// Local headers
#include "models.h"

void Extender_ar(struct texto * arr){
    struct texto ar = *arr;
    char *p = (char*) malloc((ar.cap*2)* sizeof(char));
    
    for(int n=0; n<ar.cap;n++){
        *(p+n*sizeof(char)) = *(ar.ptr + n *sizeof(char));
    }

    ar.ptr = p;
    ar.cap = 2*ar.cap;

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
    if((ar->tam) < (ar->cap)/2){
        Contraer_ar(ar);
    }
}
struct texto Set(struct texto ar, char info, int pos){
        *(ar.ptr + pos* sizeof(char)) = info;
    return ar;
}
char Get(struct texto ar, int pos){
    return *(ar.ptr + pos*sizeof(char));
}