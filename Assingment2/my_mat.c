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