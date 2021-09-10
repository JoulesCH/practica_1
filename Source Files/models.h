#pragma once
struct texto{
    char* ptr; 
    int tam;
    int cap;
};

struct words{
        char* str;
        struct words* next;
        int tam;
};