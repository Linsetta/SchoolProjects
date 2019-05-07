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

int countLinesInFile(FILE* inFile) {
  char ch;
  int  lineExists = 0;
  int  lineNumber = 0;
  int  done       = 0;
  clearerr(inFile);
  fseek(inFile, 0, SEEK_SET);
  while (! done) {
    ch = fgetc(inFile);
    if (feof(inFile)) {
      done = 1;
    } else {
      lineExists = 1;
      if (ch == '\n') {
	lineNumber ++;
	lineExists = 0;
      }
    }
  }
  if (lineExists) {
    lineNumber ++;
  }
  return lineNumber;
}

int readLineLengthFromFile(FILE* inFile) {
  int  offset = ftell(inFile);
  int  done   = 0;
  int  len    = 0;
  char ch;
  while (! done) {
    ch = fgetc(inFile);
    if (feof(inFile)) {
      done = 1;
    } else {
      if (ch == '\n') {
	done = 1;
      } else {
	len ++;
      }
    }
  }
  clearerr(inFile);
  fseek(inFile, offset, SEEK_SET);
  return len;
}

void readLineFromFile(FILE* inFile, char* str) {
  int  done  = 0;
  int  index = 0;
  char ch;
  while (! done) {
    ch = fgetc(inFile);
    if (feof(inFile)) {
      done = 1;
    } else {
      if (ch == '\n') {
	done = 1;
      } else {
	str[index] = ch;
	index ++;
      }
    }
  }
  str[index] = '\0';
}

void readLinesFromFile(FILE* inFile, char** array) {
  int done      = 0;
  int lineIndex = 0;
  int len;
  clearerr(inFile);
  fseek(inFile, 0, SEEK_SET);
  
  while (! done) {
    len = readLineLengthFromFile(inFile);
    if (len == 0) {
      done = 1;
    } else {
      array[lineIndex] = (char*)malloc(sizeof(char) * (len + 1));
      readLineFromFile(inFile, array[lineIndex]);
      if (feof(inFile)) {
	done = 1;
      }
      lineIndex ++;
    }
  }
}

int main (int argc, char** argv) {
  if (argc != 3) {
    printf("USAGE: FindComponents <infile> <outfile>\n");
    exit(-1);
  }
  char* inFileName  = argv[1];
  char* outFileName = argv[2];
  printf("FindComponents %s %s\n", inFileName, outFileName);
  FILE* inFile = fopen(inFileName, "r");
  if (inFile == NULL) {
    printf("FindComponents Error: Cannot open \"%s\" for reading.\n", inFileName);
    exit(1);
  }
  FILE* outFile = fopen(outFileName, "w");
  if (outFile == NULL) {
    printf("FindComponents Error: Cannot open \"%s\" for writing.\n", inFileName);
    exit(1);
  }
  
  int    lineNumber = countLinesInFile(inFile);
  char** array      = (char**)malloc(sizeof(char*) * lineNumber);
  int    i;
  for (i = 0; i < lineNumber; i ++) {
    array[i] = NULL;
  }
  readLinesFromFile(inFile, array);
  
  //{
  //  for (int i = 0; i < lineNumber; i ++) {
  //    printf("array[%d] = \"%s\"\n", i, array[i]);
  //  }
  //}
  
  int   order = atoi(array[0]);
  Graph G     = newGraph(order);
  i           = 1;
  {
    int u = -1;
    int v = -1;
    while (u != 0 && v != 0) {
      char* next;
      u = strtol(array[i], &next, 10);
      v = strtol(next, NULL, 10);
      //printf("(u,v) = (%d,%d)\n", u, v);
      if (u != 0 && v != 0) {
	addArc(G, u, v);
      }
      i ++;
    }
  }
  
  fprintf(outFile, "Adjacency list representation of G:\n");
  printGraph(outFile, G);
  fprintf(outFile, "\n");
  
  List S = newList();
  for (i = 1; i <= order; i ++) {
    append(S, i);
  }
  DFS(G, S);
  //printf("DFS(G)\n");
  moveFront(S);
  while (listIndex(S) >= 0) {
    int x = get(S);
    if (getParent(G, x) == NIL) {
      //printf("  getParent(%d) == NIL\n", x);
    } else {
      //printf("  getParent(%d) == %d\n", x, getParent(G, x));
    }
    moveNext(S);
  }
  
  Graph T = transpose(G);
  DFS(T, S);
  int countSCC = 0;
  //printf("DFS(T)\n");
  moveFront(S);
  while (listIndex(S) >= 0) {
    int x = get(S);
    if (getParent(T, x) == NIL) {
      countSCC ++;
      //printf("  getParent(%d) == NIL\n", x);
    } else {
      //printf("  getParent(%d) == %d\n", x, getParent(T, x));
    }
    moveNext(S);
  }
  fprintf(outFile, "G contains %d strongly connected components:\n", countSCC);
  List* SCCArray = (List*)malloc(sizeof(List) * countSCC);
  for (i = 0; i < countSCC; i ++) {
    SCCArray[i] = newList();
  }

  int indexSCC = 0;
  moveFront(S);
  while (listIndex(S) >= 0) {
    int x = get(S);
    if (getParent(T, x) == NIL) {
      indexSCC ++;
      //printf("  getParent(%d) == NIL\n", x);
    } else {
      //printf("  getParent(%d) == %d\n", x, getParent(T, x));
    }
    append(SCCArray[countSCC - indexSCC], x);
    moveNext(S);
  }
  
  for (i = 0; i < countSCC; i ++) {
    fprintf(outFile, "Component %d:", (i + 1));
    moveFront(SCCArray[i]);
    while (listIndex(SCCArray[i]) >= 0) {
      int x = get(SCCArray[i]);
      fprintf(outFile, " %d", x);
      moveNext(SCCArray[i]);
    }
    fprintf(outFile, "\n");
  }
  
  for (i = 0; i < countSCC; i ++) {
    freeList(&(SCCArray[i]));
  }
  free(SCCArray);
  freeGraph(&G);
  freeGraph(&T);
  freeList(&S);
  
  fclose(outFile);
  fclose(inFile);
  
  for (i = 0; i < lineNumber; i ++) {
    free(array[i]);
  }
  free(array);
  
  return 0;
}
