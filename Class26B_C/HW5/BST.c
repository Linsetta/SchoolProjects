#include "BST.h"

/****************************************************************************
**
** BUILDING A RANDOM BINARY SEARCH TREE
**
********************************************************

  Buid a random BST - to test the basic BST operations:
  - traverse // recursive
  - insert   // iterative and recursive
  - search   // iterative and recursive
  - delete
****************************************************************************/

/****************************************************************
   INORDER
   Print a BST in Left-Root-Right sequence.
*/
void printTreeInOrder(BST_NODE *root, FILE* fptr) {
   if(root) {
      printTreeInOrder(root->left, fptr);
      fprintf(fptr, "\n  %-20s  ", root->data);
      queue_traverse_forw(root->line_numbers, fptr);
      printTreeInOrder(root->right, fptr);
   }
}

/****************************************************************
   Build a random BST of integer numbers within the range
   0 to MAX - 1
*/
BST_NODE *buildBinaryTree( int n )
{
    BST_NODE *root = NULL;
    char data[100];
    int line_number;

    while(n){
        sprintf(data, "identifier-%d", rand( ) % BST_MAX);
        line_number = rand() % 100;
        if(bst_insert(&root, data, line_number)) // not a duplicate!
            n--;
   }
   return root;
}

/****************************************************************
   ITERATIVE Insert
*/
int bst_insert( BST_NODE **root, char* data, int line_number )
{
    BST_NODE **ptr_root = root;

    while(*ptr_root){
        if (strcmp(data, (*ptr_root)->data) > 0)
            ptr_root = &(*ptr_root)->right;
        else if (strcmp(data, (*ptr_root)->data) < 0)
            ptr_root = &(*ptr_root)->left;
        else
        {
            int duplicate = queue_insert((*ptr_root)->line_numbers, line_number);
            if (duplicate) {
                printf("Line number already in the tree node queue!\n");
                return 0; // duplicate
            }
            return 1; // data inserted
        }
    }
    if(!(*ptr_root = (BST_NODE *) malloc (sizeof(BST_NODE))))
        printf( "Fatal malloc error!\n" ), exit(1);
    int data_length = strlen(data);
    (*ptr_root)->data  = (char*)malloc(data_length + 1);
    strcpy((*ptr_root)->data, data);
    (*ptr_root)->left  = (*ptr_root)->right = NULL;
    (*ptr_root)->line_numbers = init_queue();
    queue_insert((*ptr_root)->line_numbers, line_number);
    return 1; // data inserted
}

/****************************************************************
   ITERATIVE Search
*/
BST_NODE *bst_find(BST_NODE *root, char* target)
{
   BST_NODE *mover = root;

   while (mover)
   {
       if (strcmp(target, mover->data) < 0)
           mover = mover->left;
       else
           if (strcmp(target, mover->data) > 0)
               mover = mover->right;
           else
               return mover;
   }
   return NULL;
}

void free_bst(BST_NODE** root) {
    if ((*root)->left) {
        free_bst(&((*root)->left));
    }
    if ((*root)->right) {
        free_bst(&((*root)->right));
    }
    free((*root)->data);
    free_queue(&((*root)->line_numbers));
    free(*root);
    *root = NULL;
}
