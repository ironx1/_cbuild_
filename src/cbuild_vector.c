//
// Created by akaan on 16.05.2023.
//

#include "../include/cbuild_vector.h"
#include <stdlib.h>

void vector_pushBack(Vector *vector, char *str){
    if(vector == NULL) return;
    if(vector->array == NULL){
        vector->array = malloc(sizeof(char*)*(++vector->length));
        if(vector->array == NULL) return;
        vector->array[vector->i++] = str;
        return;
    }
    vector->array = realloc(vector->array, sizeof(char*)*(++vector->length));
    vector->array[vector->i++] = str;
}

void vector_dtor(Vector *vector){
    if(vector != NULL){
        if(vector->array != NULL) free(vector->array);
        free(vector);
    }
}

Vector *init_Vector(){
    Vector *vector = malloc(sizeof(Vector));
    if(vector != NULL){
        vector->array = NULL;
        vector->i = vector->length = 0;
        vector->dtor = vector_dtor;
        vector->push = vector_pushBack;
        return vector;
    }
    return NULL;
}
