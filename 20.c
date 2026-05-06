-- -- -- -- -- -- -- -- - 1 -- -- -- -- -- -- -- -- -- --
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
void addEdge(int u, int v)
{
    adj[u][v] = 1;
}
void dfs(int v, int vertices)
{
    visited[v] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (adj[v][i] && !visited[i])
        {
            dfs(i, vertices);
        }
    }
    stack[++top] = v;
}
void topologicalSort(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            dfs(i, vertices);
        }
    }
    printf("\n Topological Sort Order:\n");
    while (top >= 0)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main()
{
    int vertices, edges, u, v;
    printf("Enter the number of vertices:");
    scanf("%d", &vertices);
    printf("Enter Number of Edges:");
    scanf("%d", &edges);
    printf("Enter edges (u,v) Where u->v:\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    topologicalSort(vertices);
    return 0;
}

Slip20_2
    Write a program to solve N Queens Problem using Backtracking.
#include <stdio.h>
#include <stdlib.h> // for abs()
    int x[10];
// Check if queen can be placed safely
int place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}
// Backtracking function
void nqueen(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                for (int j = 1; j <= n; j++)
                    printf("%d ", x[j]);
                printf("\n");
            }
            else
            {
                nqueen(k + 1, n);
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    nqueen(1, n);
    return 0;
}
