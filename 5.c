Slip5_1 
Write a program for the Implementation of Kruskal’s algorithm to find 
minimum cost spanning tree.
#include <stdio.h> 
int parent[10];
// Find parent
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
// Union
void uni(int i, int j)
{
    parent[j] = i;
}
int main()
{
    int n, i, j, a, b, u, v;
    int cost[10][10], min, mincost = 0;
    printf("Enter vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    for (int k = 1; k < n; k++)
    {
        min = 999;
        // Find minimum edge
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (u != v)
        {
            printf("(%d-%d) = %d\n", a, b, min);
            mincost += min;
            uni(u, v);
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost = %d", mincost);
    return 0;
}

Slip5_2
        Write a program to implement Huffman Code using greedy methods and also calculate the
            best case and worst -
    case complexity.
#include <stdio.h>
int main() {
    int i, n, a[10], sum = 0;
    printf("Enter number of symbols: ");
    scanf("%d", &n);
    printf("Enter frequencies:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (n > 1) {
        int min1 = 0, min2 = 1, temp;
        if (a[min1] > a[min2]) {
            temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (i = 2; i < n; i++) {
            if (a[i] < a[min1]) {
                min2 = min1;
                min1 = i;
            } else if (a[i] < a[min2]) {
                min2 = i;
            }
        }
        sum += a[min1] + a[min2];
        a[min1] = a[min1] + a[min2];
        a[min2] = a[n - 1];
        n--;
    }
    printf("Minimum Cost = %d\n", sum);
    return 0;
}