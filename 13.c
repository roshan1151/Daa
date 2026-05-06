Slip13_1
Write a program to find minimum number of multiplications in Matrix Chain Multiplication.
#include <stdio.h>
    int main()
{
    int n, i, j, k, L;
    int p[10], m[10][10];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter dimensions array:\n");
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    // Initialize diagonal as 0
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    // Chain length
    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = 9999;
            for (k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    printf("Minimum multiplications: %d", m[1][n]);
    return 0;
}

-----------2----------

#include<stdio.h>
#include<limits.h>

int sum(int freq[],int i,int j)
{
  int s=0;
  for(int k=i;k<=j;k++)
    s+=freq[k];
  return s;
}

int optimalBST(int key[],int freq[],int n)
{
  int cost[n][n];
  for(int i=0;i<n;i++)
    cost[i][i]=freq[i];
  for(int l=2;l<=2;l++)
  {
    for(int i=0;i<=n;i++)
    {
      int j=i+l-1;
      cost[i][j]=INT_MAX;
      for(int r=i;r<=j;r++)
      {
        int c=((r>i)?cost[i][r-1]:0)+((r<j)?cost[r+1][j]:0)+sum(freq,i,j);
        if(c<cost[i][j])
          cost[i][j]=c;
      }
    }
  }
  return cost[0][n-1];
}

int main()
{
  int n;
  printf("Enter the number of keys:");
  scanf("%d",&n);
  int key[n],freq[n];
  printf("Enter %d sorted keys:\n",n);
  for(int i=0;i<n;i++)
    scanf("%d",&key);
    printf("Enter the frequencies for each key :\n");
    for(int i=0;i<n;i++)
      scanf("%d",&freq[i]);
  int result=optimalBST(key,freq,n);
  printf("Mininum cost of optimal binary search tree :%d\n",result);
  return 0;
}                       
