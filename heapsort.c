#include<stdio.h> 
 void heapsort(int a[],int n); 
 void buildheap(int a[],int n); 
 void heapify(int a[],int i,int last); 
 void display(int a[],int n); 
 int main() 
 { 
     int a[7]={17,4,19,2,16,8,28}; 
     heapsort(a,7); 
     printf("Sorted elements are \n"); 
     display(a,7); 
 } 
 void heapsort(int a[7],int n) 
 { 
     int temp,i=0,last; 
     buildheap(a,n); 
     printf("Initial heap= \n"); 
     display(a,n); 
     for(last=n-1;last>=1;last--) 
     { 
         temp=a[i]; 
         a[i]=a[last]; 
         a[last]=temp; 
         printf("After iteartion %d\n",n-last); 
         display(a,n); 
         heapify(a,i,last-1); 
     } 
 } 
  
 void buildheap(int a[7],int n) 
 { 
     int i; 
     for(i=n/2-1;i>=0;i--) 
         heapify(a,i,n-1); 
  
 } 
 
 void heapify(int a[],int i,int last) 
 { 
    int l,temp,max; 
     max=a[i]; 
     l=2*i+1; 
     if((l<last)&&(a[l]<a[l+1])) 
         l=l+1; 
      if((l<=last)&&(max<a[l])) 
      { 
         temp=a[i]; 
         a[i]=a[l]; 
         a[l]=temp; 
         heapify(a,l,last); 
      } 
 } 
 
 void display(int a[],int n) 
 { 
     int i; 
     for(i=0;i<n;i++) 
         printf("%d\n",a[i]); 
 }