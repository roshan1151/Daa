-------1-----

#include <stdio.h>
#include <stdbool.h>
#define V 4 

bool isSafe(int v, bool graph[V][V], int color[], int c) 
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) 
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) 
    {
        if (isSafe(v, graph, color, c)) 
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[V][V], int m) 
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0)) 
    {
        printf("Solution does not exist\n");
        return false;
    }
    printf("Solution exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
    return true;
}

int main() 
{
    bool graph[V][V] = 
    {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; 
    graphColoring(graph, m);
    return 0;
}


------------2-------------

#include <stdio.h>
#include <stdbool.h>
#define V 5 

void classifyNodes(bool graph[V][V]) {
    int liveNodes = 0, eNodes = 0, deadNodes = 0;

    for (int i = 0; i < V; i++) 
    {
        int degree = 0;
        for (int j = 0; j < V; j++) 
        {
            if (graph[i][j])
                degree++;
        }
        if (degree == 0)
            deadNodes++;
        else if (degree == 1)
            eNodes++;
        else
            liveNodes++;
    }
    printf("Live Nodes: %d\n", liveNodes);
    printf("E Nodes: %d\n", eNodes);
    printf("Dead Nodes: %d\n", deadNodes);
}

int main() 
{
    bool graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0}
    };
    classifyNodes(graph);
    return 0;
}
