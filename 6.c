Slip6_1 
Write a program for the Implementation of Prim’s algorithm to find minimum cost spanning tree.
#include <stdio.h> 
int main()
{
    int n, i, j, a[10][10], visited[10] = {0};
    int min, x, y, total = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    visited[1] = 1;
    for (int k = 1; k < n; k++)
    {
        min = 999;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (visited[i] && !visited[j] && a[i][j] < min)
                {
                    min = a[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        printf("Edge %d-%d = %d\n", x, y, min);
        total += min;
        visited[y] = 1;
    }

    printf("Minimum Cost = %d", total);

    return 0;
}

Slip6_2
    Write a Program to find only length of Longest Common Subsequence.
#include <stdio.h>
#include <string.h>

    int main()
{
    char X[100], Y[100];
    int m, n, i, j, L[100][100];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    // Build LCS table
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    printf("Length of LCS = %d", L[m][n]);

    return 0;
}