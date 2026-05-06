Slip1_1
Write a program to sort a list of n numbers in ascending order using selection sort and
determine the time required to sort the elements.
#include <stdio.h>
#include <time.h>
    int main()
{
    int n, i, j, min, temp;
    clock_t start, end;
    double time_taken;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock(); // Start time

    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    end = clock(); // End time
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted list:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}

Sample Input 
Enter number of elements: 5 
Enter 5 elements: 
64 25 12 22 11 
Sample Output 
Sorted list: 
11 12 22 25 64 
Time taken: 0.000002 seconds


Slip1_2 
Write a program to sort a given set of elements using the Quick sort method and determine 
the time required to sort the elements. Repeat the experiment for different values of n, the 
number of elements in the list to be sorted. The elements can be read from a file or can be 
generated using the random number generator.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void quick(int a[], int l, int h)
{
    int i = l, j = h, p = a[l], t;
    if (l >= h)
        return;
    while (i < j)
    {
        while (a[i] <= p && i < h)
            i++;
        while (a[j] > p)
            j--;
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[l] = a[j];
    a[j] = p;
    quick(a, l, j - 1);
    quick(a, j + 1, h);
}

int main()
{
    int n, i;
    clock_t s, e;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];

    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    s = clock();
    quick(a, 0, n - 1);
    e = clock();

    printf("Time = %f sec", (double)(e - s) / CLOCKS_PER_SEC);
    return 0;
}