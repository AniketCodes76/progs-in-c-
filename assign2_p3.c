#include <stdio.h>
#include <stdlib.h>

// Function to convert to 3-tuple format
int **convertToTuple(int **matrix, int rows, int cols, int *tupleRows) {
    int count = 0;

    // Count non-zero elements
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                count++;

    *tupleRows = count + 1; // total rows in tuple = non-zero + 1 (for header)

    // Allocate memory for tuple
    int **tuple = (int **)malloc((*tupleRows) * sizeof(int *));
    for (int i = 0; i < *tupleRows; i++)
        tuple[i] = (int *)malloc(3 * sizeof(int));

    // First row is metadata
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = count;

    int k = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = matrix[i][j];
                k++;
            }

    return tuple;
}
int **transposeTuple(int **tuple, int tupleRows) {
    int nonZero = tuple[0][2];
    int **trans = (int **)malloc(tupleRows * sizeof(int *));
    for (int i = 0; i < tupleRows; i++)
        trans[i] = (int *)malloc(3 * sizeof(int));
    trans[0][0] = tuple[0][1];
    trans[0][1] = tuple[0][0];
    trans[0][2] = nonZero;
    int k = 1;
    for (int col = 0; col < tuple[0][1]; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (tuple[i][1] == col) {
                trans[k][0] = tuple[i][1];
                trans[k][1] = tuple[i][0];
                trans[k][2] = tuple[i][2];
                k++;
            }
        }
    }

    return trans;
}

// Function to display tuple
void displayTuple(int **tuple, int rows) {
    printf("Row Col Value\n");
    for (int i = 0; i < rows; i++)
        printf("%3d %3d %5d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
}

int main() {
    int rows, cols;

    // Input matrix size
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    // Dynamic allocation of matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    // Input elements
    printf("Enter elements of %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    // Convert to tuple
    int tupleRows;
    int **tuple = convertToTuple(matrix, rows, cols, &tupleRows);

    printf("\n3-Tuple Representation:\n");
    displayTuple(tuple, tupleRows);

    // Transpose tuple
    int **transpose = transposeTuple(tuple, tupleRows);

    printf("\nTranspose of 3-Tuple Representation:\n");
    displayTuple(transpose, tupleRows);

    // Free allocated memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    for (int i = 0; i < tupleRows; i++) {
        free(tuple[i]);
        free(transpose[i]);
    }
    free(tuple);
    free(transpose);

    return 0;
}
