#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

// Scanning from the user the matrix values. getting a pointer to the matrix, size the will be the constant from the define
void matValues(int **mat, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; i++)
        {
            scanf("%d", &mat[i][j]); // Scaning to the address in the memory fo the matrix
        }
    }
}

// This function will find the minimun valuse in the row and it's index to know where to jump
int findMinDist(int distance[], bool isVisited[], int size)
{
    int min = INFINITY, minimumIndex = 0;
    for (int u = 0; u < size; u++)
    {
        if (isVisited[u] == False && distance[u] <= min)
        { // If we haven't visited that vertex we'll check it else we;ve visited that vertex all ready
            min = distance[u], minimumIndex = u;
        }
    }
    return minimumIndex; // This is the next index to jump for it in our shortest path
}

// Helper dijkstra algorithm or Floyd-Warshall
// This function is implementing dijksrta algorithm
// An explanation and animation for the idea https://www.youtube.com/watch?v=5Uaq71PXa8Y
int findPath(int **mat, int size, int src, int dst)
{
    bool ifVisited[size];
    int dist[size]; // Distance array from the givven point

    // going over the distance fron the given point and initilizing with INFINITY,and false, beacsue we're still didn't visited them
    for (int i = 0; i < size; i++)
    {
        dist[i] = INFINITY, ifVisited[i] = False;
    }

    dist[src] = 0; // From a the beggining vertex to itself, the distance is zero

    // Now to find the next vertex to go to we need to find the min value in our row
    for (int counter = 0; counter < size - 1; counter++)
    {
        int v = findMinDist(dist, ifVisited, size); // Finding the next vertex to go to
        ifVisited[v] = True;                        // Updating that we're going to visit this vertex

        // Now updating the distance to this vertex
        for (int u = 0; u < size; u++)
        {
            // If we haven't visited that vertex, and it's valuse is not infinity,
            // and the distance till it smaller from what we've found so we'll update it
            if (!ifVisited[u] && mat[v][u] && dist[v] != INFINITY && dist[v] + mat[v][u] < dist[u])
            {
                dist[u] = dist[v] + mat[v][u];
            }
        }
    }

    return dist[dst]; // returning the update shortest path to the destination vertex
}

int isPath(int **mat, int size, int i, int j)
{
    int result = findPath(mat, size, i, j);    // Operationg the algorithm on the matrix
    return (result < INFINITY && result != 0); // INFINITY means there is no path, like in definotions of gragh theory. 0 means this is the place it self
}

int shortesPath(int **mat, int size, int i, int j)
{
    if (isPath(mat, size, i, j) == False) // If there is no path, returning -1
    {
        return -1;
    }
    return findPath(mat, size, i, j);
}
