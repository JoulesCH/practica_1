#pragma once
struct texto{
    char* ptr; 
    int tam;
    int cap;
};

typedef struct word{
    char * ptr;
    int tam;
    int cap;
}Word;

typedef struct words{
        Word * ptr;
        int tam;
        int cap;
}Words;