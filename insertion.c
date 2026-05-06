#include<stdio.h> 
int main() 
{ 
 int i,j,n,x,a[10]; 
 printf("\n Enter the no of elements:"); 
 scanf("%d",&n); 
 printf("\n Enter the unsorted data:"); 
    for(i=0;i<n;i++) 
 scanf("%d",&a[i]); 
 printf("\n Display the unsorted data:"); 
 for(i=0;i<n;i++) 
   printf("%4d",a[i]); 
 for(i=1;i<n;i++) 
  { 
   x=a[i]; 
   for(j=i-1;j>=0 && x<a[j];j--) 
   a[j+1]=a[j]; 
   a[j+1]=x; 
  } 
  printf("\n Display the sorted data:"); 
  for(i=0;i<n;i++) 
     printf("%4d",a[i]); 
  return 0; 
} 