Slip7_1 
Write a program for the Implementation of Dijkstras algorithm to find shortest path to other 
vertices
#include <stdio.h>
#define MAX 10
#define INF 9999 
int main()
{
    int n, i, j, u, v, min;
    int cost[MAX][MAX], dist[MAX], visited[MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // no edge
        }
    }
    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    // Initialize distances
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
    }
    visited[src] = 1;
    // Dijkstra logic
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (v = 0; v < n; v++)
        {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Output
    printf("\nShortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}

Slip7_2 
Write a program for finding Topological sorting for Directed Acyclic Graph 
(DAG)                                                                                                      [15 Mark]
#include <stdio.h> 
int main()
{
    int n, i, j, k = 0;
    int a[10][10], indegree[10] = {0}, visited[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                indegree[j]++;
        }
    printf("Topological order: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (indegree[j] == 0 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;

                for (k = 0; k < n; k++)
                {
                    if (a[j][k] == 1)
                        indegree[k]--;
                }
            }
        }
    }

    return 0;
}