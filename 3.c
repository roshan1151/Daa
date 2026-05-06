Slip3_1
    Write a program to sort a given set of elements using the Quick sort method and
        determine the time required to sort the elements
#include <stdio.h>
#include <time.h>
    void quick(int a[], int low, int high)
{
    int i = low, j = high, pivot = a[low], temp;
    if (low < high)
    {
        while (i < j)
        {
            while (a[i] <= pivot && i < high)
                i++;
            while (a[j] > pivot)
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        a[low] = a[j];
        a[j] = pivot;
        quick(a, low, j - 1);
        quick(a, j + 1, high);
    }
}
int main()
{
    int n, i;
    clock_t start, end;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    start = clock();
    quick(a, 0, n - 1);
    end = clock();
    // start time
    // end time
    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime taken = %f seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

Slip3_2
    Write a program to find Minimum Cost Spanning Tree of a given undirected graph using Prims
        algorithm
#include <stdio.h>
#define INF 999

    int main()
{
    int n, i, j, min, u, v, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], visited[n];

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1; // Start from vertex 0

    for (int k = 0; k < n - 1; k++)
    {
        min = INF;

        for (i = 0; i < n; i++)
            if (visited[i])
                for (j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }

        printf("Edge: %d -> %d  Cost: %d\n", u, v, min);
        total += min;
        visited[v] = 1;
    }

    printf("Total Minimum Cost = %d", total);

    return 0;
}
