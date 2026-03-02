#include <stdio.h>

int adj[20][20], visited[20];
int n;

void bfs(int start) {
    int queue[20], front = 0, rear = 0;
    int i, v;
    visited[start] = 1;
    queue[rear++] = start;
    printf("%d ", start + 1);

    while (front < rear) {
        v = queue[front++];
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i + 1);
                queue[rear++] = i;
            }
        }
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

    printf("BFS Traversal Sequence: ");
    bfs(0);
    printf("\n");
    return 0;
}
