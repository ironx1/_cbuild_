//
// Created by akaan on 10.05.2023.
//

#include <cbuild_argumentTree.h>
#include <stdlib.h>
#include <string.h>
Node *initNode(char *argument, funPtr fun){
    if(argument == NULL) return NULL;
    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL) return NULL;
    strcpy_s(node->arg, 30, argument);
    node->fun = fun;
    node->left = node->right = NULL;
    return node;
}
Node *addNode(Node *r, char *argument, funPtr fun){
    if(r == NULL) return initNode(argument, fun);
    else if(strcmp(argument, r->arg)>0) r->right = addNode(r->right, argument, fun);
    else if(strcmp(argument, r->arg)<0) r->left = addNode(r->left, argument, fun);
    return r;
}

void findNode(Node *r, char *arg, int argc, char *argv[]){
    if(r == NULL) return;
    if(!strcmp(r->arg, arg)){
        r->fun(argv, argc);
    }
    else if(strcmp(arg, r->arg)>0) findNode(r->right, arg, argc, argv);
    else findNode(r->left, arg, argc, argv);
}

void clearNodes(Node *root){
    if(root == NULL) return;
    clearNodes(root->left);
    clearNodes(root->right);
    free(root);
}