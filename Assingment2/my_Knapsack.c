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

int knapSack(int weight[], int values[], int selected_bool[])
{
}

int main()
{   
    // The items values and their wieght for the knapsack
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