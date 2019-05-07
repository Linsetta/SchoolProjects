/*********************************************************************************
 ** CIS 26B                                                           Extra Credit
 ** Advanced C
 ******************

 Multi-dimensional Arrays


 Find a path of maximum value.

 The figure below shows a number triangle. Write a program that
 calculates the highest sum of numbers passed on a route that
 starts at the top and ends somewhere on the base. Each step can
 go either down or diagonally down to the right. The number of
 rows in the triangle is >1 but <=100. The numbers in the triangle,
 all integers, are between 0 and 99.

 Input Data

 Data about the number of rows in the triangle are first read from
 the INPUT.TXT file. In our example, INPUT.TXT appears as follows:

 5

 7
 3 8
 8 1 0
 2 7 4 4
 4 5 2 6 5

 Output Data
 The highest sum is written as an integer in the OUTPUT.TXT file.
 In our example: 30 = 7 + 3 + 8 + 7 + 5

 In addition to printing the sum,
 print the path too, for instance:
 (0,0)->(1,0)->(2,0)->(3,1)->(4,1)


 Name: Nina Demenchukova

 ***************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void printTable(FILE* fptr, int size, int** table) {
    for (int y = 0; y < size; y ++) {
        for (int x = 0; x <= y; x ++) {
            fprintf(fptr, " %2d", table[y][x]);
        }
        fprintf(fptr, "\n");
    }
}

int** findPathHelper(int size, int** table, int start_x, int start_y, int* sum) {
    int path_length = size - start_y;
    int** path = (int**)malloc(sizeof(int*) * path_length);
    for (int y = start_y; y < size; y ++) {
        path[y - start_y] = (int*)malloc(sizeof(int) * 2);
    }
    path[0][0] = start_x;
    path[0][1] = start_y;
    *sum = table[start_y][start_x];
    if (start_y + 1 < size) {
        int   down_path_sum;
        int** down_path = findPathHelper(size, table, start_x, start_y + 1, &down_path_sum);
        int   right_path_sum;
        int** right_path = findPathHelper(size, table, start_x + 1, start_y + 1, &right_path_sum);
        int   best_path_sum;
        int** best_path;
        if (down_path_sum > right_path_sum) {
            best_path_sum = down_path_sum;
            best_path     = down_path;
        } else {
            best_path_sum = right_path_sum;
            best_path     = right_path;
        }
        *sum += best_path_sum;
        for (int y = start_y + 1; y < size; y ++) {
            path[y - start_y][0] = best_path[y - (start_y + 1)][0];
            path[y - start_y][1] = best_path[y - (start_y + 1)][1];
        }
        freePath(size - (start_y + 1), down_path);
        freePath(size - (start_y + 1), right_path);
    }
    return path;
}

int** findPath(int size, int** table, int* sum) {
    return findPathHelper(size, table, 0, 0, sum);
}

void freePath(int size, int** path) {
    for (int y = 0; y < size; y ++) {
        free(path[y]);
    }
    free(path);
}

void printPath(FILE* fptr, int size, int** path) {
    for (int y = 0; y < size; y ++)
        {
        if (y != 0) {
            fprintf(fptr, "->");
        }
        fprintf(fptr, "(%d,%d)", path[y][0], path[y][1]);
    }
}

int** loadTable(char* filename, int* size) {
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening EC_Tables_input.txt for reading.\n");
        exit(-1);
    }
    char line[100];
    char* token;
    const char* delimiter = " \t\r\n";
    fgets(line, 100, fptr); // read size
    *size = strtol(line, NULL, 10);
    int** table = (int**)malloc(sizeof(int*) * (*size));
    fgets(line, 100, fptr); // skip a line
    for (int y = 0; y < (*size); y ++) {
        table[y] = (int*)malloc(sizeof(int) * (y + 1));
        fgets(line, 100, fptr);
        for (int x = 0; x <= y; x ++) {
            if (x == 0) {
                token = strtok(line, delimiter);
            } else {
                token = strtok(NULL, delimiter);
            }
            table[y][x] = strtol(token, NULL, 10);
        }
    }
    fclose(fptr);
    return table;
}

void saveOutput(char* filename, int sum, int size, int** path) {
    FILE* fptr = fopen(filename, "w");
    fprintf(fptr, "sum = %d\n", sum);
    printPath(fptr, size, path);
    fclose(fptr);
}

int main(void)
{
    int size;
    int** table = loadTable("EC_Tables_input.txt", &size);
    printTable(stdout, size, table);
    int sum;
    int** path = findPath(size, table, &sum);
    printPath(stdout, size, path);
    saveOutput("OUTPUT.txt", sum, size, path);
    freePath(size, path);
    return 0;
}
/* Output:
  7
  3  8
  8  1  0
  2  7  4  4
  4  5  2  6  5
  8  9 10 11 12 99
(0,0)->(1,1)->(2,2)->(3,3)->(4,4)->(5,5)

 Output in OUTPUT.txt:
 sum = 123
(0,0)->(1,1)->(2,2)->(3,3)->(4,4)->(5,5)%
*/
