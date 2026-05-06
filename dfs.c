#include <stdio.h> 
#define MAX 100 
 
int visited[MAX] = {0}; 
int adjacency_matrix[MAX][MAX]; 
int n; 
 
void DFS(int vertex) { 
    int i; 
    visited[vertex] = 1; 
    printf("%d ", vertex); 
 
    for(i = 0; i < n; i++) { 
        if(adjacency_matrix[vertex][i] && !visited[i]) { 
            DFS(i); 
        } 
    } 
} 
 
int main() { 
    int i, j, start_vertex; 
 
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 
 
    printf("Enter the adjacency matrix: \n"); 
    for(i = 0; i < n; i++) { 
        for(j = 0; j < n; j++) { 
            scanf("%d", &adjacency_matrix[i][j]); 
        } 
    } 
 
    printf("Enter the starting vertex: "); 
    scanf("%d", &start_vertex); 
 
    printf("DFS traversal: "); 
    DFS(start_vertex); 
 
    return 0; 
}