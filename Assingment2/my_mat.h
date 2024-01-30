// Here we're giving the sings of our function
#ifndef _MY_MAT_H
#define _MY_MAT_H

# define MAT_SIZE 10
# define True 1
# define False 0
# define INFINITY 2147483647 // The max number of int, we need it to use for initialzing the distance finding in the graph

// This functions is getting the values for the matrix from the user
// Getting a pointer to the start of the matrix, and int valuse for the size of it
void matValues(int**, int);

// This function is getting matrix and i and j values, returning True if there is a  path from i to j, and False if there isn't
// Getting - Matrix by pointer, size, i and j
int isPath(int**, int, int ,int);

// If there is a path from i to j, we'll want to find this path and return it, returning it's weight if there isn;t returning -1
// Getting - Matrix by pointer, size, i and j
int shortesPath(int**, int, int, int);

#endif