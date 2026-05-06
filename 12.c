----------------1------------------

#include<stdio.h>
int a[20][20],q[2],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
	for(i=1;i<=n;i++)
	{
		if(a[v][i] && !visited[i])
		{
			q[++r]=i;
		}
		if(f<=r)
		{
			visited[q[f]]=1;
			bfs(q[f++]);
		}
	}
}
void main()
{
	int v;
	printf("\n Enter The Number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enetr Graph data in matrix form:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	printf("\n The node which are reachable are:\n");
	for(i=1;i<=n;i++)
	{
		if(visited[i])
			printf("%d\t",i);
	}
}


Slip12_2
Write a program to sort a given set of elements using the Selection sort method and
determine the time required to sort the elements
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
    printf("Enter elements:\n");
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
    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}