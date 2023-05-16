//
// Created by akaan on 10.05.2023.
//

#ifndef CBUILD_CBUILD_H
#define CBUILD_CBUILD_H
#include <cbuild_utils.h>

typedef void (*funCBuild)(char *argv[], int argc);

void cbuild_buildObjects(char *argv[], int argc);
void cbuild_buildExecutable(char *argv[], int argc);
#endif //CBUILD_CBUILD_H
