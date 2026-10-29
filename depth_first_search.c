#include <stdio.h>

#define MAX_VERTICES 10

int main(void)
{
    int graph[MAX_VERTICES][MAX_VERTICES];
    int stack[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int n, start, i, j, top = -1, vertex;

    printf("Number of vertices (1-%d): ", MAX_VERTICES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1)
                return 1;
        }
    }

    printf("Starting vertex (0-%d): ", n - 1);
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    stack[++top] = start;
    visited[start] = 1;
    printf("DFS traversal: ");

    while (top >= 0) {
        vertex = stack[top--];
        printf("%d ", vertex);

        for (i = n - 1; i >= 0; i--) {
            if (graph[vertex][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
    return 0;
}
