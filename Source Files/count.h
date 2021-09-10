#pragma once
// Built in headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include "models.h"
#include "utils.h"

struct words* Count(struct words* Words){
    struct words* iter;
    int i = 0;
    for (iter = Words; NULL != iter; iter = iter->next) {
        printf("%s\n", iter->str);
        i++;    
    }
    printf("El numero de palabras es %d\n\n", i);
    return Words;
}