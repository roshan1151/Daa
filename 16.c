-----------1---------------

#include<stdio.h>
int w[10],p[10],v[10][10],n,i,j,cap,x[10]={0};
int max(int i,int j)
{
	return ((i>j)?i:j);
}
int knap(int i,int j)
{
	int value;
	if(v[i][j]<0)
	{
		if(j<w[i])
			value=knap(i-1,j);
		else
			value=max(knap(i-1,j),p[i]+knap(i-1,j-w[i]));
		v[i][j]=value;
	}
	return(v[i][j]);
}
void main()
{
	int profit,count=0;
	printf("\nEnter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the profit and weights of the elements\n");
	for(i=1;i<=n;i++)
	{
		printf("For item no %d\n",i);
		scanf("%d%d",&p[i],&w[i]);
	}
	printf("\nEnter the capacity \n");
	scanf("%d",&cap);
	for(i=0;i<=n;i++)
		for(j=0;j<=cap;j++)
			if((i==0)||(j==0))
				v[i][j]=0;
			else
				v[i][j]=-1;
	profit=knap(n,cap);
	i=n;
	j=cap;
	while(j!=0&&i!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
			i--;
		}
		else
			i--;
	}
	printf("Items included are\n");
	printf("Sl.no\tweight\tprofit\n");
	for(i=1;i<=n;i++)
		if(x[i])
			printf("%d\t%d\t%d\n",++count,w[i],p[i]);
	printf("Total profit = %d\n",profit);
}


---------------2----------------

#include <stdio.h>
#include <stdbool.h>

#define V 5 

int graph[V][V];     
int path[V];         


bool isSafe(int v, int pos) {

    if (graph[path[pos - 1]][v] == 0)
        return false;


    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}



bool hamiltonianCycleUtil(int pos) {

    if (pos == V) {

        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(pos + 1))
                return true;

            path[pos] = -1;  
        }
    }

    return false;
}

bool hasHamiltonianCycle() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; 

    if (hamiltonianCycleUtil(1)) {
        printf("Hamiltonian Cycle Found:\n");
        for (int i = 0; i < V; i++)
            printf("%d -> ", path[i]);
        printf("%d\n", path[0]); 
        return true;
    } else {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }
}

int main() {
    printf("Enter the adjacency matrix (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    hasHamiltonianCycle();

    return 0;
}
