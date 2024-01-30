#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"
int main()
{
    int graph[MAT_SIZE][MAT_SIZE];
    
    char userChoise;
    int i, j;
    while (userChoise != 'D') // Exit the program
    {
        scanf(" %c", &userChoise); // May not need the space

        if (userChoise == 'A') // Entering value to the graph that represented as a matrix
        {
            matValues(graph,MAT_SIZE);
        }
        else if (userChoise == 'B') // Finding a path from i to j in the graph
        {
            scanf("%d%d", &i, &j);
            printf("%s\n", isPath(graph,MAT_SIZE,i,j) ? "True" : "False");

        }
        else if (userChoise == 'C') // If there is a path fiding the shortest-path
        {
            scanf("%d%d", &i, &j);
            printf("%d\n", shortesPath(graph, MAT_SIZE, i ,j ));

        }

        scanf(" %c", &userChoise); // For entering another choise
    }

    // If we'll use malloc we'll need to free the memory by using 'free' function

    return 0;
}