#ifndef BST__H
#define BST__H

#include "Queue.h"

#define BST_MAX 50

typedef struct bstNodeTag{
    char* data;
    struct bstNodeTag *left;
    struct bstNodeTag *right;
    QUEUE_NODE* line_numbers;
} BST_NODE;

void printTreeInOrder( BST_NODE *root, FILE* fptr );
BST_NODE *buildBinaryTree( int n );
int bst_insert( BST_NODE **root, char* data, int line_number );
BST_NODE *bst_find(BST_NODE *root, char* target);
void free_bst(BST_NODE** root);

#endif // BST__H
