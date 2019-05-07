/**
 * Nina Demenchukova
 * ndemench
 * CMPS 101
 * Algorithms and Abstract Data Types
 * Programming Assignment 4
 */

#include "List.h"
#include <stdlib.h>

struct NodeStruct {
  int                data;
  struct NodeStruct* prev;
  struct NodeStruct* next;
};

typedef struct NodeStruct* Node;

Node newNode(int data) {
  Node N = (Node)malloc(sizeof(struct NodeStruct)); // cast void* to Node
  N->data    = data;
  N->prev    = NULL;
  N->next    = NULL;
  return N;
}	

void freeNode(Node* pN) {
  free(*pN);
  *pN = NULL;
}

struct ListStruct {
  Node front;
  Node back;
  Node cursor;
  int  cursorIndex;
};

List newList() {
  List L = (List)malloc(sizeof(struct ListStruct)); // cast void* to List
  L->front       = NULL;
  L->back        = NULL;
  L->cursor      = NULL;
  L->cursorIndex = -1;
  return L;
}

void freeList(List* pL) {
  clear(*pL);
  free(*pL);
  *pL = NULL;
}

int length(List L) {
  int  count = 0;
  Node iter  = L->front;
  while (iter != NULL) {
    count ++;
    iter = iter->next;
  }
  return count;
}

int index(List L) {
  if (L->cursor != NULL) {
    return L->cursorIndex;
  }
  return -1;
}

int front(List L) {
  if (length(L)<=0) {
    printf("List Error: front() called on empty List\n");
    exit(1);
  }
  return L->front->data;
}

int back(List L) {
  if (length(L)<=0) {
    printf("List Error: back() called on empty List\n");
    exit(1);
  }
  return L->back->data;
}

int get(List L) {
  if (length(L)<=0) {
    printf("List Error: get() called on empty List\n");
    exit(1);
  }
  if (index(L)<0) {
    printf("List Error: get() called with cursor undefined\n");
    exit(1);
  }
  return L->cursor->data;
}

int equals(List A, List B) {
  Node iter1 = A->front;
  Node iter2 = B->front;
  while (iter1 != NULL && iter2 != NULL) {
    if (iter1->data != iter2->data) {
      return 0;
    }
    iter1 = iter1->next;
    iter2 = iter2->next;
  }
  if (iter1 != NULL || iter2 != NULL) {
    return 0;
  }
  return 1;
}

void clear(List L) {
  Node iter = L->front;
  while (iter != NULL) {
    Node next = iter->next;
    freeNode(&iter);
    iter = next;
  }
  L->front       = NULL;
  L->back        = NULL;
  L->cursor      = NULL;
  L->cursorIndex = -1;
}

void moveFront(List L) {
  if (L->front != NULL) {
    L->cursor      = L->front;
    L->cursorIndex = 0;
  }
}

void moveBack(List L) {
  if (L->back != NULL) {
    L->cursor      = L->back;
    L->cursorIndex = length(L) - 1;
  }
}

void movePrev(List L) {
  if (L->cursor != NULL) {
    L->cursor = L->cursor->prev;
    L->cursorIndex --;
  } 
}

void moveNext(List L) {
  if (L->cursor != NULL) {
    L->cursor = L->cursor->next;
    L->cursorIndex ++;
    if (L->cursor == NULL) {
      L->cursorIndex = -1;
    }
  } 
}
    
void prepend(List L, int data) {
  Node node = newNode(data);
  if (L->front == NULL) {
    L->front = node;
    L->back  = node;
  } else {
    L->front->prev = node;
    node->next     = L->front;
    L->front       = node;
  }
  if (L->cursor != NULL) {
    L->cursorIndex ++;
  }
}

void append(List L, int data) {
  Node node = newNode(data);
  if (L->back == NULL) {
    L->front = node;
    L->back  = node;
  } else {
    L->back->next = node;
    node->prev    = L->back;
    L->back       = node;
  }
}

void insertBefore(List L, int data) {
  if (length(L) <= 0) {
    printf("List Error: insertBefore() length <= 0\n");
    exit(1);
  }
  if (L->cursorIndex < 0) {
    printf("List Error: insertBefore() cursorIndex < 0\n");
    exit(1);
  }
  Node node             = newNode(data);
  node->next            = L->cursor;
  node->prev            = L->cursor->prev;
  if (L->cursor->prev == NULL) {
    L->front = node;
  } else {
    L->cursor->prev->next = node;
  }
  L->cursor->prev       = node;
  L->cursorIndex ++;
}
    
void insertAfter(List L, int data) {
  if (length(L) <= 0) {
    printf("List Error: insertAfter() length <= 0\n");
    exit(1);
  }
  if (L->cursorIndex < 0) {
    printf("List Error: insertAfter() cursorIndex < 0\n");
    exit(1);
  }
  Node node             = newNode(data);
  node->next            = L->cursor->next;
  node->prev            = L->cursor;
  if (L->cursor->next == NULL) {
    L->back = node;
  } else {
    L->cursor->next->prev = node;
  }
  L->cursor->next       = node;
}

void deleteFront(List L) {
  if (length(L) <= 0) {
    printf("List Error: deleteFront() length <= 0\n");
    exit(1);
  }
  if (L->cursor == L->front) {
    L->cursor      = NULL;
    L->cursorIndex = -1;
  } else if (L->cursor != NULL) {
    L->cursorIndex --;
  }
  Node old = L->front;
  L->front = L->front->next;
  if (L->front == NULL) {
    L->back = NULL;
  } else {
    L->front->prev = NULL;
  }
  freeNode(&old);
}

void deleteBack(List L) {
  if (length(L) <= 0) {
    printf("List Error: deleteBack() length <= 0\n");
    exit(1);
  }
  if (L->cursor == L->back) {
    L->cursor      = NULL;
    L->cursorIndex = -1;
  }
  Node old = L->back;
  L->back = L->back->prev;
  if (L->back == NULL) {
    L->front = NULL;
  } else {
    L->back->next = NULL;
  }
  freeNode(&old);
}

void delete(List L) {
  if (length(L) <= 0) {
    printf("List Error: delete() length <= 0\n");
    exit(1);
  }
  if (index(L) < 0) {
    printf("List Error: delete() index < 0\n");
    exit(1);
  }
  Node old = L->cursor;
  if (L->cursor->prev == NULL) {
    L->front = L->cursor->next;
    if (L->front != NULL) {
      L->front->prev = NULL;
    } else {
      L->back = NULL;
    }
  } else {
    L->cursor->prev->next = L->cursor->next;
  }
  if (L->cursor->next == NULL) {
    L->back = L->cursor->prev;
    if (L->back != NULL) {
      L->back->next = NULL;
    } else {
      L->front = NULL;
    }
  } else {
    L->cursor->next->prev = L->cursor->prev;
  }
  L->cursor      = NULL;
  L->cursorIndex = -1;
  freeNode(&old);
}

List copyList(List L) {
  List N    = newList();
  Node iter = L->front;
  while (iter != NULL) {
    append(N, iter->data);
    iter = iter->next;
  }
  return N;
}

List concatList(List A, List B) {
  List C    = copyList(A);
  Node iter = B->front;
  while (iter != NULL) {
    append(C, iter->data);
    iter = iter->next;
  }
  return C;
}

void printList(FILE* out, List L) {
  fprintf(out, "(");
  int count = 0;
  Node iter = L->front;
  while (iter != NULL) {
    if (count != 0) {
      fprintf(out, ", ");
    }
    if (count == L->cursorIndex) {
      if (iter != L->cursor) {
	printf("List Error: toString() cursor does not match cursorIndex\n");
	exit(1);
      }
      fprintf(out, "<");
    }
    fprintf(out, "%d", iter->data);
    if (count == L->cursorIndex) {
      fprintf(out, ">");
    }
    count ++;
    iter = iter->next;
  }
  fprintf(out, ")");
}

