/*******************************************************
 Homework 5:
 a program which generates a cross-reference listing of
 the identifiers in an input C program.The input and output
 files are specified on the command line.
 The program has a:
 - queue (Queue.c) with a line numbers;
 - BST of identifiers (BST.c);
 - handling of identifiers not show up in comments or quotd
  strings (single or double)


 NAME: Nina Demenchukova
 IDE: CodeBlocks
 *******************************************************/

#include "ReadC.h"

void print_usage() {
    printf("HW5 <input-c-filename> <output-filename>\n");
}

void printOutputFile(char* filename, BST_NODE* identifiers) {
    FILE* fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Could not open \"%s\" for writing.\n");
        exit(-1);
    }
    time_t timeval;
    struct tm *timeptr;
    char time_stamp_string[1024];
    time(&timeval);
    timeptr = localtime(&timeval);
    strftime(time_stamp_string, 1024, "%A, %B %d, %I:%M:%S, %Y", timeptr);
    fprintf(fptr, "/************************  Cross Reference Listing  ************************/\n");
    fprintf(fptr, "\n");
    fprintf(fptr, "Cross reference listing made at: %s\n", time_stamp_string);
    printTreeInOrder(identifiers, fptr);
    fclose(fptr);
}

int main(int argc, char** argv) {
    char* input_c_filename;
    char* output_filename;
    BST_NODE* identifiers;

    if (argc != 3) {
        print_usage();
        exit(-1);
    }
    input_c_filename = argv[1];
    output_filename  = argv[2];

    int input_c_filename_length = strlen(input_c_filename);
    if (input_c_filename[input_c_filename_length - 2] != '.' ||
        input_c_filename[input_c_filename_length - 1] != 'c') {
        printf("Input C file must have .c extension!\n");
        exit(-1);
    }

    identifiers = read_c_identifiers(input_c_filename);

    printOutputFile(output_filename, identifiers);

    free_bst(&identifiers);

    return 0;
}
/*OUTPUT FILE:
/************************  Cross Reference Listing  ************************

Cross reference listing made at: Sunday, March 17, 04:17:47, 2019

  DUMMY_TRAILER          11  93 195
  NULL                   95 140 145 153 160 165 172 174 199
  REQUEST                16 130 160 192
  SERVICE                25  36  38  39  41  61  63  66  81 125 127 128 129 140 190
  char                   19  28  37  38  42  72  87 106 108 125 145 165
  curr                  127 133 135 136 138 151 157 180 181
  define                 11
  else                  115 155 178
  exit                   70  76  85  91 143 148 163 168
  for                   199
  front                  29 153 174 176 199
  getinfo                37  46 106
  gets                  111
  h                       7   8   9
  if                     67  73  82  88 113 138 140 145 160 165 174
  include                 7   8   9
  init_list              36  45  61
  insert                 38  48 125
  int                    34
  job_id                 20  37  38  43  46  48 106 116 125 171 201
  line                  108 111 113 116
  long                   20  37  38  43 106 125
  main                   34
  malloc                 66  72  81  87 140 145 160 165
  newreq                130 160 165 170 171 172 176 180
  newserv               129 140 145 150 151 152 153 157 174 176
  next                   21  31  81  82  87  88  93  94  95 127 136 151 152 172 180 181 194 199 204
  prev                  128 135 152
  printf                 69  75  84  90 110 142 147 162 167 197 198 201
  putchar               203
  qname                  28  37  38  42  46  48  72  73  78  87  88  93  94 106 114 116 125 133 138 145 150 195 197
  rear                   30 176 180 181
  reqptr                192 199 201
  request                16  17  21  29  30
  return                 52  97 117 183
  serv_ptr               38  39  41  45  48  50  63  66  67  72  73  78  81  82  87  88  93  94  95  97 125 127 128 190 194 195 197 199 204
  service                25  26  31
  sizeof                 66  81 140 160
  sscanf                116
  stdio                   7
  stdlib                  8
  strcmp                 46 113 133 138
  strcpy                114 150 170
  string                  9
  strlen                145 165
  struct                 16  17  21  25  26  29  30  31
  traverse               39  50 190
  typedef                16  25
  username               19  37  38  42  46  48 106 116 125 165 170 201
  void                   34  36  37  38  39  61 106 125 190
  while                  46 133 195

**************************************************************************
Output on a screen:
home/linsetta/Desktop/codeblocks-workspace/HW5/HW5
% bin/Debug/HW5                                                    1506 | pts/0
HW5 <input-c-filename> <output-filename>
linsetta@linsetta | Tue 19 Mar 2019 21:44:16
/home/linsetta/Desktop/codeblocks-workspace/HW5/HW5
% bin/Debug/HW5 ../inputs/input.c ../outputs/myout.txt             1507 | pts/0
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
Line number already in the tree node queue!
*/
