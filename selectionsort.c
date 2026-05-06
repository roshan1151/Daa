#include <stdio.h>

int main() {
    int  a[100],i,j,temp,n,count=0;
    printf("How many Elements:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        count++;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(a[j]<a[i])
            {
                count++;
                temp=a[i];
                count++;
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("sorted elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("Time required %d\n",count);
    return 0;
}