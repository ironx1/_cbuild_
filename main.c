//
// Created by akaan on 16.05.2023.
//

#include <cbuild.h>
Node *argTree = NULL;

char *commands[] = {"-b", "-exe"};
funCBuild funList[] = {cbuild_buildObjects, cbuild_buildExecutable};

int main(int argc, char *argv[]){

    for (int i = 0; i <2; ++i) {
        argTree = addNode(argTree, commands[i], funList[i]);
    }
    cbuild_init(argc, argv);
    clearNodes(argTree);
    vector->dtor(vector);
    return 0;
}