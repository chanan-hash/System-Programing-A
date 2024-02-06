#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SACK_WIEGHT 20
#define ARRAY_SIZE 5

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// int (*table) [capacity+1] = malloc(sizeof(int[num_items+1][capacity+1]));
// A Dynamic Programming based 
// solution for 0-1 Knapsack problem

int knapSack(int weight[], int values[], int selected_bool[])
{
    int K[ARRAY_SIZE + 1][SACK_WIEGHT + 1]; // building the matrix row - number of items, column the capacity

    for (int i = 0; i <= ARRAY_SIZE; i++)
    {
        for (int j = 0; i <= SACK_WIEGHT; i++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0; // initilize the firt row and column by zero
            }
            else if (weight[i - 1] <= j)
            {
                // Checking if we can take other item
                K[i][j] = max(values[i - 1] + K[i - 1][j - weight[i - 1]], K[i - 1][j]);
            }
            else
            {
                K[i][j] = K[i - 1][j]; // Means we're taking the same as above
            }
        }
    }
    return K[ARRAY_SIZE][SACK_WIEGHT]; // The optimal value to take
}

int main()
{
    // The items values and their weight for the knapsack
    int items[ARRAY_SIZE];
    int values[ARRAY_SIZE];
    int weights[ARRAY_SIZE];

    int result[0];
    int maxProf = 0;

    // Scanning 5 items from the user
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%d", &items[i]);
    }

    // Scanning the values of the item
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%d", &values[i]);
    }

    // Scanning the values of the item
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%d", &weights[i]);
    }

    maxProf = (weights, values, result);

    printf("Maximun profit: %d", maxProf);
    return 0;
}