#include <stdio.h>

int adj[20][20], visited[20];
int n;

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v + 1);
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() {
    int i, j, count;
    char ch;
    printf("Enter number of vertex: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Vertices %d & %d are Adjacent ? (Y/N): ", i + 1, j + 1);
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

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal Sequence: ");
    dfs(0);
    printf("\n");
    return 0;
}
