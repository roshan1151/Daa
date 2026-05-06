-- -- -- -- -- -- -- -- -- -- -- -- -- --1 -- -- -- -- -- -- -- --

#include <stdio.h>
void readf();
void knapsack(int, int);
void dsort(int n);
void display(int);
int p[20], w[20], n, m;
double x[20], d[20], temp, res = 0.0, sum = 0.0;
void readf()
{
    int m, n, i;
    printf("\n Enter the no of Profits and weights:");
    scanf("%d", &n);
    printf("\n Enter the Maximum Capacity of the Knapsack:");
    scanf("%d", &m);
    printf("\n Enter %d profits of the weights:", n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("\n Enter %d Weights:", n);
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (i = 0; i < n; i++)
        d[i] = (double)p[i] / w[i];
    dsort(n);
    knapsack(m, n);
    display(n);
}
void dsort(int n)
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (d[j] < d[j + 1])
            {
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
                t = w[j];
                w[j] = w[j + 1];
                w[j + 1] = t;
            }
        }
    }
}
void display(int n)
{
    int i, m;
    printf("\n The Required Optimal solution is:\n");
    printf("Profits Weights Xvalue\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%f\n", p[i], w[i], x[i]);
        sum = sum + (p[i] * x[i]);
        res = res + (w[i] * x[i]);
    }
    printf("\n The Total Resultant Profit is:%f", sum);
    printf("\n The total resultant Weight into the knapsack is:%f", res);
}
void knapsack(int m, int n)
{
    int i, cu = m;
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    for (i = 0; i < n; i++)
    {
        if (w[i] < cu)
        {
            x[i] = 1.0;
            cu = cu - w[i];
        }
        else
            break;
    }
    if (i <= n)
    {
        x[i] = (double)cu / w[i];
    }
}
int main()
{
    readf();
    return 0;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- --2 -- -- -- -- -- -- -- -- -- -- -- -- -- -

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 10

int tsp(int graph[MAX][MAX], int n, int start){
    bool visit[MAX] = {false};
    int cost = 0;
    int current = start;
    visit[current] = true;
    printf("tour : %d -> ", current);
    for (int count = 1; count < n; count++)
    {
        int near = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i] && graph[current][i] && graph[current][i] < min)
            {
                min = graph[current][i];
                near = i;
            }
        }
        if (near == -1)
            break;
        visit[near] = true;
        cost += min;
        current = near;
        printf("%d->", current);
    }
    cost += graph[current][start];
    printf("%d\n", start);
    return cost;
}

int main()
{
    int graph[MAX][MAX], n, start;
    printf("Enter number of cities:");
    scanf("%d", &n);
    printf("enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter stating city (0 to %d):", n - 1);
    scanf("%d", &start);
    int total = tsp(graph, n, start);
    printf("total cost of tour %d\n", total);
    return 0;
}
