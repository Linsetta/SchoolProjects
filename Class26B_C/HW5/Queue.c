#include "Queue.h"


/***************************************************
    Initialization of a circularly doubly-linked
    list with one sentinel node
*/
QUEUE_NODE *init_queue(void)
{
    QUEUE_NODE *queue;

    // allocate the sentinel node
    queue = (QUEUE_NODE *) malloc(sizeof (QUEUE_NODE));
    if (!queue)
    {
        printf("Error in init_queue!\n");
        exit(1);
    }
    queue->data = DUMMY_QUEUE_VALUE;
    queue->forw = queue;
    queue->back = queue;

    return queue;
}

/***************************************************
    Insert a node in a sorted circularly
    doubly-linked list with one sentinel node
        return 1 - if duplicate
        return 0 - otherwise
*/
int queue_insert(QUEUE_NODE *list, int data)
{
    QUEUE_NODE *curr = list->forw;
    QUEUE_NODE *prev = list;
    QUEUE_NODE *pnew;
    int         duplicate = 1;

    // search
    while (data > curr->data)
    {
        prev = curr;
        curr = curr->forw;
    }

    if (data != curr->data)
    {
        duplicate = 0; // not a duplicate
        pnew = (QUEUE_NODE *) malloc(sizeof (QUEUE_NODE));
        if (!pnew)
        {
            printf("Fatal memory allocation error in insert!\n");
            exit(3);
        }
        pnew->data = data;
        pnew->forw = curr;
        pnew->back = prev;
        prev->forw = pnew;
        curr->back = pnew;
    }
    return duplicate;
}

/***************************************************
    Traverses forward a circularly doubly-linked
    list with one sentinel node to print out the
    contents of each node
*/
void queue_traverse_forw(QUEUE_NODE *queue, FILE* fptr)
{
    queue = queue->forw; // skip the dummy node
    while (queue->data != DUMMY_QUEUE_VALUE)
    {
        fprintf(fptr, "%3d ", queue->data);
        queue = queue->forw;
    }
    return;
}

/***************************************************
    Traverses backward a circularly doubly-linked
    list with one sentinel node to print out the
    contents of each node
*/
void queue_traverse_back(QUEUE_NODE *queue, FILE* fptr)
{
    queue = queue->back; // skip the dummy node
    while (queue->data != DUMMY_QUEUE_VALUE)
    {
        fprintf(fptr, "%d ", queue->data);
        queue = queue->back;
    }
    return;
}

void free_queue(QUEUE_NODE** queue) {
    *queue = (*queue)->forw; // skip the dummy node
    while ((*queue)->data != DUMMY_QUEUE_VALUE)
    {
        QUEUE_NODE* prev = *queue;
        *queue = (*queue)->forw;
        free(prev);
    }
    free(*queue);
    *queue = NULL;
}
