#ifndef READ_C__H
#define READ_C__H

#include "BST.h"

#define MAX_C_IDENTIFIER_LENGTH 1024

typedef struct read_c_struct {
    FILE*     fptr;
    BST_NODE* identifiers;
    int       line_number;
    int       eof;
} READ_C;

BST_NODE* read_c_identifiers(char* filename);

#endif // READ_C__H
