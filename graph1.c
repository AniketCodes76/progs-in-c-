#include <stdio.h>

int main() {
    int n, i, j, count;
    char ch;
    printf("Enter number of vertex: ");
    scanf("%d", &n);
    int adj[20][20];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Vertices %d & %d are Adjacent ? (Y/N) :", i + 1, j + 1);
            scanf(" %c", &ch);
            adj[i][j] = (ch == 'y' || ch == 'Y') ? 1 : 0;
        }
    }

    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++)
            count += adj[i][j];
        printf("Degree of vertex %d = %d\n", i + 1, count);
    }

    return 0;
}
