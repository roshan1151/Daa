Slip2_1
    Write a program to sort n randomly generated elements using Heapsort
        method.
#include <stdio.h>
#include <stdlib.h>
    void heap(int a[], int n, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, m = i, t;
    if (l < n && a[l] > a[m])
        m = l;
    if (r < n && a[r] > a[m])
        m = r;
    if (m n != i)
    {
        t = a[i];
        a[i] = a[m];
        a[m] = t;
        heap(a, n, m);
    }
}

int main()
{
    int n, i, a[50];
    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    for (i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heap(a, i, 0);
    }

    printf("Sorted list:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

Sample Input
    Enter n : 6

    Generated Random
    Elements(Example – may vary each time) 23 87 12 45 9 66

    Sample Output
    Sorted list : 9 12 23 45 66 87

    Slip2_2
    Write a program to implement Strassen’s Matrix multiplication

#include <stdio.h>
    int main()
{
    int a, b, c, d, e, f, g, h;
    int M1, M2, M3, M4, M5, M6, M7;
    int r1, r2, r3, r4;
    printf("Enter 4 elements of Matrix A: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("Enter 4 elements of Matrix B: ");
    scanf("%d%d%d%d", &e, &f, &g, &h);
    M1 = (a + d) * (e + h);
    M2 = (c + d) * e;
    M3 = a * (f - h);
    M4 = d * (g - e);
    M5 = (a + b) * h;
    M6 = (c - a) * (e + f);
    M7 = (b - d) * (g + h);
    r1 = M1 + M4 - M5 + M7;
    r2 = M3 + M5;
    r3 = M2 + M4;
    r4 = M1 - M2 + M3 + M6;
    printf("\nResult Matrix:\n%d %d\n%d %d", r1, r2, r3, r4);
    return 0;
}

� Simple Example
    If : Matrix A : 1 2 3 4 Matrix B : 5 6 7 8 Output : 19 22