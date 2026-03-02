#include <stdio.h>
#include <stdlib.h>
int countNonZero(int **mat, int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
                count++;
    return count;
}
void displayUpperTriangular(int **mat, int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                printf("%d ", mat[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void displayAboveBelowDiagonal(int **mat, int n) {
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i + 1 || j == i - 1)
                printf("%d ", mat[i][j]);
            else
                printf("  "); 
        }
        printf("\n");
    }
}

int main() {
    int **mat, n;
    printf("Enter the size of square matrix (n x n): ");
    scanf("%d", &n);
    mat = (int **)malloc(n * sizeof(int *));
    if (mat == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (mat[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }
    printf("Enter elements of %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int nonZero = countNonZero(mat, n);
    printf("\nNumber of non-zero elements: %d\n", nonZero);
    displayUpperTriangular(mat, n);
    displayAboveBelowDiagonal(mat, n);
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
    return 0;
}
