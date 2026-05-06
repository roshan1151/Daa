------------------1------------------

#include <stdio.h>

int a[20][20], reach[20], n;
void dfs(int v)
{
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++)
        if (a[v][i] && !reach[i])
        {
            printf("\n %d->%d", v, i);
            dfs(i);
        }
}
void main()
{
    int i, j, count = 0;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        reach[i] = 0;
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    }
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    dfs(1);
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        if (reach[i])
            count++;
    }
    if (count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
}

Slip11_2
    Write a program to find shortest paths from a given vertex in a weighted connected graph,
    to other
        vertices using Dijkstra’s algorithm.
#include <stdio.h>
#define N 4
#define INF 9999
    int main()
{
    int graph[N][N] = {
        {0, 1, 4, 0},
        {1, 0, 2, 6},
        {4, 2, 0, 3},
        {0, 6, 3, 0}};
    int dist[N] = {INF, INF, INF, INF};
    int visited[N] = {0};
    int src = 0;
    dist[src] = 0;
    for (int i = 0; i < N; i++)
    {
        int min = INF, u;
        // Find minimum distance vertex
        for (int j = 0; j < N; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        // Update neighbors
        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Print result
    for (int i = 0; i < N; i++)
    {
        printf("Distance to %d = %d\n", i, dist[i]);
    }
    return 0;
}