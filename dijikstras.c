#include <stdio.h> 
#define MAX 100 
#define INF 99999 
 
int adjacency_matrix[MAX][MAX]; 
int num_vertices; 
 
void dijkstra(int source_vertex) 
{ 
    int distance[MAX], visited[MAX], i, j, min_distance, next_vertex; 

    for (i = 0; i < num_vertices; i++) 
    { 
        distance[i] = INF; 
        visited[i] = 0; 
    } 
 
    distance[source_vertex] = 0; 
 
    for (i = 0; i < num_vertices - 1; i++) 
    { 
        min_distance = INF; 

        for (j = 0; j < num_vertices; j++) 
        { 
            if (!visited[j] && distance[j] < min_distance) 
            { 
                next_vertex = j; 
                min_distance = distance[j]; 
            } 
        } 
 
        visited[next_vertex] = 1; 
 
        for (j = 0; j < num_vertices; j++) 
        { 
            if (!visited[j] && adjacency_matrix[next_vertex][j] && distance[next_vertex] + adjacency_matrix[next_vertex][j] < distance[j]) 
            { 
                distance[j] = distance[next_vertex] + 
adjacency_matrix[next_vertex][j]; 
            } 
        } 
    } 

    printf("Distances from source vertex %d: \n", source_vertex); 
    for (i = 0; i < num_vertices; i++) { 
        printf("%d: %d\n", i, distance[i]); 
    } 
} 
 
int main() 
{ 
    int i, j, source_vertex; 
 
    printf("Enter the number of vertices: "); 
    scanf("%d", &num_vertices); 
 
    printf("Enter the adjacency matrix: \n"); 
    for(i = 0; i < num_vertices; i++) { 
        for(j = 0; j < num_vertices; j++) 
        { 
            scanf("%d", &adjacency_matrix[i][j]); 
        } 
    } 
 
    printf("Enter the source vertex: "); 
    scanf("%d", &source_vertex); 
    dijkstra(source_vertex); 
    return 0; 
}