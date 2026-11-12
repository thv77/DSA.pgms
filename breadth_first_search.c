#include <stdio.h>

#define MAX 10

int main(void)
{
    int vertices, start, current, i, j;
    int front = 0, rear = -1;

    int queue[MAX];
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

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS:\n");

    while (front <= rear)
    {
        current = queue[front++];

        printf("%d ", current);

        for (i = 0; i < vertices; i++)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");

    return 0;
}

