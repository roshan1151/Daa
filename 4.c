Slip4_1
    Write a program to implement a Merge Sort algorithm to sort a given set of elements and determine
        the time required to sort the elements
#include <stdio.h>
#include <time.h>
    void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l, t[100];
    while (i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= m)
        t[k++] = a[i++];
    while (j <= r)
        t[k++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = t[i];
}
void sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int a[100], n, i;
    clock_t s, e;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    s = clock();
    sort(a, 0, n - 1);
    e = clock();
    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime = %f sec", (double)(e - s) / CLOCKS_PER_SEC);
    return 0;
}

Slip4_2
    Write a program to implement Knapsack problems using Greedy method
#include <stdio.h>
    int main()
{
    int i, j, n;
    float w[10], p[10], ratio[10], temp;
    float weight, profit = 0;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    printf("Enter profits and weights:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &p[i], &w[i]);
        ratio[i] = p[i] / w[i];
    }
    printf("Enter capacity of knapsack: ");
    scanf("%f", &weight);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (w[i] <= weight)
        {
            profit += p[i];
            weight -= w[i];
        }
        else
        {
            profit += ratio[i] * weight;
            break;
        }
    }
    printf("Maximum Profit = %f", profit);
    return 0;
}