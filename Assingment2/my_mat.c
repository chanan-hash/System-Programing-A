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
            sanf("%d", &mat[i][j]); // Scaning to the address in the memory fo the matrix
        }
    }
}

// Helper dijkstra algorithm or Floyd-Warshall
int findPath(int** mat, int size ,int src, int dst)
{
    // TODO
}

int isPath(int **mat, int size, int i, int j)
{
    int result = findPath(mat, size, i ,j); // Operationg the algorithm on the matrix
    return (result < INFINITY && result != 0); // INFINITY means there is no path, like in definotions of gragh theory. 0 means this is the place it self
}

int shortesPath(int **mat, int size, int i, int j)
{
    if (isPath(mat, size, i, j) == False) // If there is no path, returning -1
    {
        return -1;
    }
}
