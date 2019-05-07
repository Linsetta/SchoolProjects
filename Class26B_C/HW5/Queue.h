#ifndef QUEUE__H
#define QUEUE__H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define DUMMY_QUEUE_VALUE INT_MAX

typedef struct queue_node QUEUE_NODE;
struct queue_node
{
    int data;
    QUEUE_NODE *forw;
    QUEUE_NODE *back;
};

QUEUE_NODE *init_queue(void);
int queue_insert(QUEUE_NODE *queue, int data);
void queue_traverse_forw(QUEUE_NODE *queue, FILE* fptr);
void queue_traverse_back(QUEUE_NODE *queue, FILE* fptr);
void free_queue(QUEUE_NODE** queue);

#endif // QUEUE__H
