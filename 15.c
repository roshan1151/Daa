Slip15_1 
Write a program to implement to find out solution for 0/1 knapsack problem using LCBB (Least Cost 
Branch and Bound).
#include <stdio.h>
#define MAX 10 
int n, W;
int w[MAX], p[MAX];
// Function to calculate upper bound
float bound(int i, int weight, int profit)
{
    float b = profit;
    int j = i;
    while (j < n && weight + w[j] <= W)
    {
        weight += w[j];
        b += p[j];
        j++;
    }
    if (j < n)
        b += (W - weight) * ((float)p[j] / w[j]);
    return b;
}
int maxProfit = 0;
// LCBB function
void knapsack(int i, int profit, int weight)
{
    if (weight <= W && profit > maxProfit)
        maxProfit = profit;
    if (i >= n)
        return;
    float b = bound(i, weight, profit);
    if (b > maxProfit)
    {
        // Include item
        knapsack(i + 1, profit + p[i], weight + w[i]);
        // Exclude item
        knapsack(i + 1, profit, weight);
    }
}
int main()
{
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter profits:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter capacity: ");
    scanf("%d", &W);
    knapsack(0, 0, 0);
    printf("Maximum Profit = %d\n", maxProfit);
    return 0;
}

Slip15_2
    Write a program to implement Graph Coloring Algorithm
#include <stdio.h>
    int graph[10][10],
    color[10], n, m;
// Check if color can be assigned
int safe(int v, int c)
{
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return 0;
    return 1;
}
// Graph coloring using backtracking
int solve(int v)
{
    if (v == n)
        return 1;
    for (int c = 1; c <= m; c++)
    {
        if (safe(v, c))
        {
            color[v] = c;
            if (solve(v + 1))
                return 1;
            color[v] = 0; // backtrack
        }
    }
    return 0;
}
int main()
{
    printf("Vertices: ");
    scanf("%d", &n);
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Colors: ");
    scanf("%d", &m);
    if (solve(0))
    {
        for (int i = 0; i < n; i++)
            printf("V%d -> C%d\n", i, color[i]);
    }
    else
    {
        printf("No solution");
    }
}