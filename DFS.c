
#include <stdio.h>
#include <conio.h>
#define MAX 20

int graph[MAX][MAX], visited[MAX];
int n;

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

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void main()
{
    int ch, start, i;

    clrscr();

    n = 0;

    do
    {
        printf("\n\n1.Create Graph");
        printf("\n2.DFS Traversal");
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

                    if (start < 0 || start >= n)
                        printf("\nInvalid Vertex");
                    else
                    {
                        for (i = 0; i < n; i++)
                            visited[i] = 0;

                        printf("\nDFS Traversal: ");
                        DFS(start);
                    }
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
