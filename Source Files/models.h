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

typedef struct cuenta{
    char * ptr;
    int tam;
    int cap;
    int count;
}Cuenta;

typedef struct cuentas{
    Cuenta * ptr;
    int tam;
    int cap;
}Cuentas;