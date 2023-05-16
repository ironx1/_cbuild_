//
// Created by akaan on 10.05.2023.
//

#ifndef CBUILD_CBUILD_ARGUMENTTREE_H
#define CBUILD_CBUILD_ARGUMENTTREE_H
typedef void (*funPtr)(char *argv[], int argc);
typedef struct node Node;

struct node{
    char arg[25];
    funPtr fun;
    Node *left, *right;
};
Node *initNode(char *argument, funPtr fun);
Node *addNode(Node *r, char *argument, funPtr fun);
void findNode(Node *r, char *arg, int argc, char *argv[]);
void clearNodes(Node *root);
#endif //CBUILD_CBUILD_ARGUMENTTREE_H
