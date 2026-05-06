-- -- -- -- -- -- -- -- -1 -- -- -- -- -- -- -- -- -- -
#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalBST(int key[], int freq[], int n)
{
    int cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
    for (int l = 2; l <= 2; l++)
    {
        for (int i = 0; i <= n; i++)
        {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++)
            {
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main()
{
    int n;
    printf("Enter the number of keys:");
    scanf("%d", &n);
    int key[n], freq[n];
    printf("Enter %d sorted keys:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &key);
    printf("Enter the frequencies for each key :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);
    int result = optimalBST(key, freq, n);
    printf("Mininum cost of optimal binary search tree :%d\n", result);
    return 0;
}

Slip9_2
    Write a program to implement Sum of Subset by Backtracking
#include <stdio.h>
    int w[10],
    x[10], n, target;
void subset(int s, int k)
{
    if (s == target)
    {
        printf("Subset: ");
        for (int i = 0; i < k; i++)
            if (x[i])
                printf("%d ", w[i]);
        printf("\n");
        return;
    }
    if (k >= n || s > target)
        return;
    x[k] = 1; // include
    subset(s + w[k], k + 1);
    x[k] = 0; // exclude
    subset(s, k + 1);
}
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);
    subset(0, 0);
    return 0;
}