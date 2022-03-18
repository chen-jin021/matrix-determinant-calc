#ifndef MATRICES
#define MATRICES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Num_rows num_cols
row1_val1 row1_val2 row1_val3...
row2_val1 row2_val2 row2_val3...
*/

// define a struct of matrix using the name Matrix
typedef struct matrix {
    int rows, cols;
    double **eles;
} Matrix;

Matrix *matrixConversion(FILE *f);
Matrix *subMatrix(Matrix *m, int n, int c);
double determinant(Matrix *m, int n);
#endif