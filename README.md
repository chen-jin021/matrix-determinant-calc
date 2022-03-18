# matrix-determinant-calc

## Functionality and Usage:

A C-program that allows an input of `.txt` file that has the format of:
```
Num_rows num_cols
row1_val1 row1_val2 row1_val3...
row2_val1 row2_val2 row2_val3...
```
And computes for the corresponding determinant.

## `matrix.h` header file

- the header file that contains the overall structure of matrix.
- It has a struct of matrix named `Matrix` and also method signatures that are implmented in the `matrix.c` file.

## `matrix.c` file:
- This file implements the matrix.h header file.

    1) the functionalities of importing the txt file information and convert it to a matrix (more particularly, a matrix pointer).

    2)  It also has the computing determinant function (`determinant`) that computes for the determinant of the matrix recursively which also calls the `subMatrix()` function.

    3) `subMatrix` function has inputs of a Matrix pointer and designated column of which the `determinant` function is currently on when calling the function. It will construct and return a new Matrix pointer which excludes the specified row and column.

## Running the file:

- use `gcc` compiler
- command line argument: takes in a fileName/path of a txt file that has the structure of matrix mentioned above.

## Sample:

Assume we are given a txt file that has the following contents:
```
3 3
1 2 3
4 5 6
7 8 9
```

By using the command as follows:
```
./a.out fileName.txt
```
The following result will be printed to the console:
```
The determinant is 0.00.
```