-- -- -- -- --1 -- -- -- -- --

#include <stdio.h>
#include <stdbool.h>

#define V 5 // Maximum number of vertices

int graph[V][V]; // Adjacency matrix
int path[V];                 // Stores the path

// Check if current vertex can be added to Hamiltonian Cycle
bool isSafe(int v, int pos)
{
    // Check if this vertex is adjacent to the previous one
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex is already included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to solve Hamiltonian Cycle problem
bool hamiltonianCycleUtil(int pos)
{
    // Base case: all vertices are in the path
    if (pos == V)
    {
        // Check if last vertex is connected to the first
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            if (hamiltonianCycleUtil(pos + 1))
                return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

// Function to start the process
bool hasHamiltonianCycle()
{
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Start from vertex 0

    if (hamiltonianCycleUtil(1))
    {
        printf("Hamiltonian Cycle Found:\n");
        for (int i = 0; i < V; i++)
            printf("%d -> ", path[i]);
        printf("%d\n", path[0]); // To complete the cycle
        return true;
    }
    else
    {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }
}

int main()
{
    printf("Enter the adjacency matrix (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    hasHamiltonianCycle();

    return 0;
}

-----------2----------

#include <stdio.h>
#include <stdbool.h>
#define N 4

void printSolution(int board[N][N]) 
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) 
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int board[N][N], int col) 
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1))
                return true;
            board[i][col] = 0; 
        }
    }

    return false;
}

void solve4Queens() 
{
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (solveNQueens(board, 0) == false) 
    {
        printf("Solution does not exist");
        return;
    }
    printSolution(board);
}

int main() 
{
    solve4Queens();
    return 0;
}