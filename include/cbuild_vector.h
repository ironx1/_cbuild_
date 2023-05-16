//
// Created by akaan on 16.05.2023.
//

#ifndef CBUILD_CBUILD_VECTOR_H
#define CBUILD_CBUILD_VECTOR_H
#include <stdint.h>
typedef struct vector Vector;

struct vector{
    char **array;
    uint8_t i, length;
    void (*push)(Vector *, char *str);
    void (*dtor)(Vector*);
};

Vector *init_Vector();

#endif //CBUILD_CBUILD_VECTOR_H
