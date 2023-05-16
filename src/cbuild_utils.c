//
// Created by akaan on 10.05.2023.
//
#include <string.h>
#include <stdint.h>
#include <cbuild_utils.h>
#include <direct.h>
Vector *vector = NULL;
void cbuild_init(int argc, char **argv){
    if(argv == NULL) return;
    _mkdir("BUILD");
    if (vector == NULL){
        vector = init_Vector();
    }

    for (int i = 1; i < argc; ++i) {
        if((argv[i])[0] == '-') continue;
        char *str = strrchr(argv[i], '\\');
        if(str == NULL) (vector)->push(vector, argv[i]);
        else (vector)->push(vector, ++str);
    }

    for (int i = 1; i < argc; ++i) {
        if((argv[i])[0] == '-'){
            findNode(argTree, argv[i], argc, argv);
        }
    }
}




