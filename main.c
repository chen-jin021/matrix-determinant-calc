#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

int main(int argc, char* argv[]) {
    char fileName[20];
    strcpy(fileName, argv[1]);
    FILE* f;
    f = fopen(fileName, "r");

    // assume failure of opening
    if (f == NULL) {
        printf("Error Opening");
        return 0;
    }

    Matrix* m = matrixConversion(f);
    printf("Determinant is : %.2f\n", determinant(m, m->cols));

    return 0;
}