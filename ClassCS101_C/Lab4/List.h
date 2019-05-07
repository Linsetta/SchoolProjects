/**
 * Nina Demenchukova
 * ndemench
 * CMPS 101
 * Algorithms and Abstract Data Types
 * Programming Assignment 4
 */

#ifndef LIST__H
#define LIST__H

#include <stdio.h>

typedef struct ListStruct* List;

List newList     (void);
void freeList    (List* pL);
int  length      (List L);
int  index       (List L);
int  front       (List L);
int  back        (List L);
int  get         (List L);
int  equals      (List A, List B);
void clear       (List L);
void moveFront   (List L);
void moveBack    (List L);
void movePrev    (List L);
void moveNext    (List L);
void prepend     (List L, int data);
void append      (List L, int data);
void insertBefore(List L, int data);
void insertAfter (List L, int data);
void deleteFront (List L);
void deleteBack  (List L);
void delete      (List L);
List copyList    (List L);
List concatList  (List A, List B);
void printList   (FILE* out, List L);

#endif // LIST__H
