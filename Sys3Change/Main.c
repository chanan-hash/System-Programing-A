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

int main(void)
{
    int comm, index;
    size_t words;
    char *str;

    StrList *p_strlist = StrList_alloc();

    do
    {
        scanf(" %d", &comm);
        if (comm == 1)
        {
            scanf(" %ld", &words);
            // str = (char *)malloc(STR_LEN * words);
            for (int i = 0; i < words; i++)
            {
                str = getString();
                if (str == NULL)
                {
                    printf("Invalid input\n");
                    // scanf(" %[^\n]s", str);
                }
                StrList_insertLast(p_strlist,str);
                // initList(p_strlist, words, str);
                free(str);
            }
        }
        if (comm == 2)
        {
            scanf(" %d", &index);
            // str = (char *)malloc(STR_LEN);
            // scanf(" %s", str);
            str = getString();
            if (str == NULL)
            {
                printf("Invalid input\n");
            }
            StrList_insertAt(p_strlist, str, index);
            free(str);
        }
        if (comm == 3)
        {
            StrList_print(p_strlist);
        }
        if (comm == 4)
        {
            printf("%ld\n", StrList_size(p_strlist));
        }
        if (comm == 5)
        {
            scanf(" %d", &index);
            StrList_printAt(p_strlist, index);
        }
        if (comm == 6)
        {
            printf("%d\n", StrList_printLen(p_strlist));
        }
        if (comm == 7)
        {
            // str = (char *)malloc(STR_LEN);
            str = getString();
            // scanf(" %s", str);
            if (str == NULL)
            {
                printf("Invalid input\n");
            }
            printf("%d\n", StrList_count(p_strlist, str));
            free(str);
        }
        if (comm == 8)
        {
            // str = (char *)malloc(STR_LEN);
            str = getString();
            // scanf(" %s", str);
            if (str == NULL)
            {
                printf("Invalid input\n");
            }
            StrList_remove(p_strlist, str);
            free(str);
        }
        if (comm == 9)
        {
            scanf(" %d", &index);
            StrList_removeAt(p_strlist, index);
        }
        if (comm == 10)
        {
            StrList_reverse(p_strlist);
        }
        if (comm == 11)
        {
            StrList_free(p_strlist);
        }
        if (comm == 12)
        {
            StrList_sort(p_strlist);
        }
        if (comm == 13)
        {
            if (StrList_isSorted(p_strlist))
                printf("true\n");
            else
                printf("false\n");
        }
    } while (comm != 0);
    StrList_free(p_strlist);
    free(p_strlist);

    return 0;
}
