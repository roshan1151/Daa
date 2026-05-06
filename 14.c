Slip14_1
    Write a program to sort a list of n numbers in ascending order using Insertion sort and
        determine the time required to sort the elements.
#include <stdio.h>
#include <time.h>
    int main()
{
    int n, a[1000], i, j, key;
    clock_t s, e;

    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    s = clock();
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    e = clock();
    printf("\nSorted:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime = %f seconds",
           (double)(e - s) / CLOCKS_PER_SEC);
    return 0;
}

Slip14_2
    Write a program to implement DFS and BFS.Compare the time complexity
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
    int adj[MAX][MAX],
    visited[MAX];
int n;
// ----------- DFS FUNCTION -----------
void DFS(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
// ----------- BFS FUNCTION -----------
void BFS(int v)
{
    int queue[MAX], front = 0, rear = 0, i;
    printf("%d ", v);
    visited[v] = 1;
    queue[rear++] = v;
    while (front < rear)
    {
        v = queue[front++];
        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
// ----------- MAIN FUNCTION -----------
int main()
{
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    // DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nDFS Traversal: ");
    DFS(start);
    // BFS
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nBFS Traversal: ");
    BFS(start);
    return 0;
}