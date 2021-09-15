// DEFINICION DE ESTRUCTURAS USADAS EN EL AGORITMO
#pragma once

// Estructura que contiene los caracteres del texto
struct texto{
    char* ptr; 
    int tam;
    int cap;
};

// Estructuras que contienen las palabras del texto
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

// Estructuras que contienen las palabras del texto con su frecuencia (count)
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