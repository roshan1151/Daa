#include <stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#define MAXSIZE 20 
typedef struct 
{ 
    int data[MAXSIZE]; 
    int top; 
}STACK; 
void init(STACK *ps) 
{ 
  ps->top=-1; 
} 
int isempty(STACK *ps) 
{ 
  return(ps->top==-1); 
} 
void push(STACK *ps, int n) 
{ 
  ps->data[++ps->top]=n; 
} 
int pop(STACK *ps) 
{ 
  return ps->data[ps->top--]; 
} 
 
void topological_sort(int m[10][10],int n) 
 { 
    int i,j,v,w; 
    int indeg[10]; 
    int visited[10]={0}; 
    printf("Enter the matrix:"); 
    for(i=0;i<n;i++) 
        { 
            for(j=0;j<n;j++) 
            { 
                scanf("%d",&m[i][j]); 
            } 
        } 
 
    for(i=0;i<n;i++) 
        { 
        indeg[i]=0; 
        for(j=0;j<n;j++) 
        { 
            if(i!=j) 
            indeg[i] = indeg[i]+ m[j][i]; 
        } 
 
        printf("Indegree of v%d=%d\t",i+1,indeg[i]); 
 
 } 
   printf("\nTopological sort: "); 
    STACK s; 
    init(&s); 
    while(1) 
    { 
     for(v=0;v<n;v++) 
         if((visited[v]==0)&&(indeg[v]==0)) 
         { 
             visited[v]=1; 
             push(&s,v); 
             printf("v%d",v+1); 
         } 
     if(isempty(&s)) 
        break; 
     v=pop(&s); 
     for(w=0;w<n;w++) 
         if(m[v][w]==1) 
            indeg[w]=indeg[w]-1; 
   } 
} 
int main() 
{ 
    //int m[4][4]={{0,1,1,0},{0,0,1,1},{0,0,0,1},{0,0,0,0}}; 
    int m[10][10],n; 
    printf("How many vertices :"); 
    scanf("%d",&n); 
       topological_sort(m,n); 
 
} 