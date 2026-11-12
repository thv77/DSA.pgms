#include <stdio.h>

#define MAX 10

int main(void)
{
    int vertices, start, current, i, j, top = -1;

    int stack[MAX];
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX)
    {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    if (start < 0 || start >= vertices)
    {
        printf("Invalid starting vertex\n");
        return 1;
    }

    stack[++top] = start;
    visited[start] = 1;

    printf("DFS:\n");

    while (top != -1)
    {
        current = stack[top--];

        printf("%d ", current);

        for (i = vertices - 1; i >= 0; i--)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");

    return 0;
}

