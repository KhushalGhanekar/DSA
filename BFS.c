
#include <stdio.h>
#include <conio.h>
#define MAX 20

int graph[MAX][MAX], visited[MAX];
int q[MAX], n;

void createGraph()
{
    int i, j;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("\nInvalid number of vertices");
        n = 0;
        return;
    }

    printf("\nEnter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
}

void BFS(int start)
{
    int front, rear, i, v;

    front = 0;
    rear = 0;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    q[rear] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front <= rear)
    {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void main()
{
    int ch, start;

    clrscr();

    n = 0;

    do
    {
        printf("\n\n1.Create Graph");
        printf("\n2.BFS Traversal");
        printf("\n3.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                createGraph();
                break;

            case 2:
                if (n == 0)
                    printf("\nCreate Graph First");
                else
                {
                    printf("\nEnter starting vertex (0 to %d): ", n-1);
                    scanf("%d", &start);

                    if (start >= 0 && start < n)
                        BFS(start);
                    else
                        printf("\nInvalid Vertex");
                }
                break;

            case 3:
                printf("\nExiting");
                break;

            default:
                printf("\nInvalid Choice");
        }

    } while(ch != 3);

    getch();
}
