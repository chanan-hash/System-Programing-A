#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Building the string char fter char
char *getString()
{
    int capacity = 10;
    char *str = (char *)malloc(capacity * sizeof(char));

    int i = 0;
    char c;
    while (1) // while true
    {
        c = getchar();
        if (c == ' ' || c == '\n')
        { // If it a space or enter
            if (i == 0)
            {
                continue;
            }
            str[i] = '\0';
            break; // Ending the string
        }
        str[i] = c;
        i++;
        if (i >= capacity)
        {
            capacity *= 2;                               // multiplying the capacity
            str = realloc(str, capacity * sizeof(char)); // Need to increase the memory allocation
        }
    }
    return str;
}

int main()
{
    char *str;
    printf("Enter a word:\n");

    for (int i = 0; i < 5; i++)
    {
        str = getString();

        printf("%s", str);
    }
    return 0;
}