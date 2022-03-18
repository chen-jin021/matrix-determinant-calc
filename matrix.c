#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix *matrixConversion(FILE *f) {
    // read number of rows and cols
    Matrix *m = malloc(sizeof(Matrix));
    fscanf(f, "%d", &(m->rows));
    fscanf(f, "%d", &m->cols);
    //  malloc space
    m->eles = (double **)malloc(sizeof(double) * m->rows);
    int i, j;
    for (i = 0; i < m->rows; i++)
        m->eles[i] = (double *)malloc(m->cols * sizeof(double));

    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            fscanf(f, "%lf", &m->eles[i][j]);
        }
    }
    return m;
}

double determinant(Matrix *m, int n) {
    double det = 0;
    if (n == 1)
        return m->eles[0][0];
    else if (n == 2) {
        return m->eles[0][0] * m->eles[1][1] - m->eles[0][1] * m->eles[1][0];

    } else {
        // take the first row of the matrix
        int col;

        for (col = 0; col < n; col++) {
            det += m->eles[0][col] * (col % 2 != 0 ? -1 : 1) * determinant(subMatrix(m, n, col), n - 1);
        }
    }

    return det;
}

// get the submatrix
Matrix *subMatrix(Matrix *m, int n, int c) {
    Matrix *sub = malloc(sizeof(Matrix));
    sub->cols = n - 1;
    sub->rows = n - 1;
    sub->eles = (double **)malloc(sizeof(double) * sub->rows);
    int i, j, i_counter, j_counter = 0;
    for (i = 0; i < sub->rows; i++)
        sub->eles[i] = (double *)malloc(sub->cols * sizeof(double));

    int sub_i = 0;
    int sub_j = 0;
    for (i = 1; i < n; i++) {
        sub_j = 0;

        for (j = 0; j < n; j++) {
            if (j == c) {
                continue;
            }
            sub->eles[sub_i][sub_j] = m->eles[i][j];
            sub_j++;
        }
        sub_i++;
    }
    return sub;
}