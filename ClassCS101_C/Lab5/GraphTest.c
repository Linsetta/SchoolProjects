/**
 * Nina Demenchukova
 * ndemench
 * CMPS 101
 * Algorithms and Abstract Data Types
 * Programming Assignment 5
 */
#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS ((int)0)
#define FAILURE ((int)-1)

int GraphTest_constructorDestructor() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    freeGraph(&G);
    if (G != NULL) {
      return FAILURE;
    }
  }
  return SUCCESS;
}

int GraphTest_copyGraph() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G     = newGraph(n);
    Graph copyG = copyGraph(G);
    if (getOrder(G) != getOrder(copyG)) {
      return FAILURE;
    }
    if (getSize(G) != getSize(copyG)) {
      return FAILURE;
    }
    freeGraph(&G);
    freeGraph(&copyG);
    if (G != NULL) {
      return FAILURE;
    }
    if (copyG != NULL) {
      return FAILURE;
    }
  }
  return SUCCESS;
}

int GraphTest_getOrder() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    if (getOrder(G) != n) {
      return FAILURE;
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_getSize() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph UG = newGraph(n);
    if (getSize(UG) != 0) {
      printf("GraphTest_getSize FAILURE: n = %d, getSize(UG) != 0\n", n);
      return FAILURE;
    }
    for (int k = 1; k <= n; k ++) {
      addEdge(UG, k, (k % n) + 1);
      if (getSize(UG) != k) {
	printf("GraphTest_getSize FAILURE: n = %d, k = %d, getSize(UG) != k\n", n, k);
	return FAILURE;
      }
    }
    freeGraph(&UG);
  }
  return SUCCESS;
}

int GraphTest_getSource() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    if (getSource(G) != NIL) {
      return FAILURE;
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_getParent() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    for (int u = 1; u <= getOrder(G); u ++) {
      if (getParent(G, u) != NIL) {
	return FAILURE;
      }
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_getDist() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    for (int u = 1; u <= getOrder(G); u ++) {
      if (getDist(G, u) != INF) {
	return FAILURE;
      }
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_getDiscover() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    for (int u = 1; u <= getOrder(G); u ++) {
      if (getDiscover(G, u) != UNDEF) {
	return FAILURE;
      }
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_getFinish() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    for (int u = 1; u <= getOrder(G); u ++) {
      if (getFinish(G, u) != UNDEF) {
	return FAILURE;
      }
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_makeNull() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    makeNull(G);
    if (getSize(G) != 0) {
      return FAILURE;
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_addArc() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    for (int i = 0; i < 100; i ++) {
      int u = (rand() % getOrder(G)) + 1;
      int v = (rand() % getOrder(G)) + 1;
      addArc(G, u, v);
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_addEdge() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    for (int i = 0; i < 100; i ++) {
      int u = (rand() % getOrder(G)) + 1;
      int v = (rand() % getOrder(G)) + 1;
      addEdge(G, u, v);
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_printGraph() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 10; n++) {
    Graph G = newGraph(n);
    for (int i = 0; i < 10; i ++) {
      int u = (rand() % getOrder(G)) + 1;
      int v = (rand() % getOrder(G)) + 1;
      addEdge(G, u, v);
    }
    fprintf(stdout, "Graph of order %d:\n", n);
    printGraph(stdout, G);
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_BFS() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 10; n++) {
    Graph G = newGraph(n);
    for (int i = 0; i < 10; i ++) {
      int u = (rand() % getOrder(G)) + 1;
      int v = (rand() % getOrder(G)) + 1;
      addEdge(G, u, v);
    }
    for (int s = 1; s <= getOrder(G); s ++) {
      BFS(G, s);
      if (getSource(G) != s) {
	return FAILURE;
      }
      if (getDist(G, s) != 0) {
	return FAILURE;
      }
      if (getParent(G, s) != NIL) {
	return FAILURE;
      }
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_getPath() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 10; n++) {
    Graph G = newGraph(n);
    for (int i = 0; i < 10; i ++) {
      int u = (rand() % getOrder(G)) + 1;
      int v = (rand() % getOrder(G)) + 1;
      addEdge(G, u, v);
    }
    for (int s = 1; s <= getOrder(G); s ++) {
      BFS(G, s);
      for (int u = 1; u <= getOrder(G); u ++) {
	List L = newList();
	getPath(L, G, u);
	freeList(&L);
      }
    }
    freeGraph(&G);
  }
  return SUCCESS;
}

int GraphTest_transpose() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    for (int k = 1; k <= n; k ++) {
      addArc(G, k, (k % n) + 1);
    }
    Graph tG = transpose(G);
    if (getOrder(G) != getOrder(tG)) {
      return FAILURE;
    }
    if (getSize(G) != getSize(tG)) {
      return FAILURE;
    }
    freeGraph(&G);
    freeGraph(&tG);
  }
  return SUCCESS;
}

int GraphTest_DFS() {
  // test many graph orders from 1 to 99
  for (int n = 1; n < 100; n++) {
    Graph G = newGraph(n);
    List  S = newList();
    for (int k = 1; k <= n; k ++) {
      addArc(G, k, (k % n) + 1);
      append(S, k);
    }
    DFS(G, S);
    if (length(S) != getOrder(G)) {
      return FAILURE;
    }
    freeGraph(&G);
    freeList(&S);
  }
  return SUCCESS;
}

void GraphTest_runAllTests() {
  int totalSuccess = 0;
  int totalTest    = 17;
  printf("Running all Graph tests.\n");
  printf("GraphTest_constructorDestructor: %s\n", (GraphTest_constructorDestructor() == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_copyGraph            : %s\n", (GraphTest_copyGraph()             == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getOrder             : %s\n", (GraphTest_getOrder()              == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getSize              : %s\n", (GraphTest_getSize()               == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getSource            : %s\n", (GraphTest_getSource()             == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getParent            : %s\n", (GraphTest_getParent()             == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getDiscover          : %s\n", (GraphTest_getDiscover()           == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getFinish            : %s\n", (GraphTest_getFinish()             == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getDist              : %s\n", (GraphTest_getDist()               == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_makeNull             : %s\n", (GraphTest_makeNull()              == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_addArc               : %s\n", (GraphTest_addArc()                == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_addEdge              : %s\n", (GraphTest_addEdge()               == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_printGraph           : %s\n", (GraphTest_printGraph()            == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_BFS                  : %s\n", (GraphTest_BFS()                   == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_getPath              : %s\n", (GraphTest_getPath()               == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_transpose            : %s\n", (GraphTest_transpose()             == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("GraphTest_DFS                  : %s\n", (GraphTest_DFS()                   == SUCCESS) ? ({totalSuccess ++; "SUCCESS";}) : "FAILURE");
  printf("\n");
  printf("GraphTest Total Success        : %d/%d\n", totalSuccess, totalTest);
}

int main(int argc, char** argv) {
  GraphTest_runAllTests();
  return 0;
}
