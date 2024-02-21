#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"
#define WORD_MAX 100

int main()
{
    int chose;
    int index;
    int number_of_words;
    char str[WORD_MAX];

    StrList *list = StrList_alloc();

    do
    {
        if (scanf("%d", &chose) != 1)
        {
            printf("Invalid input\n");
            break;
        }
        switch (chose)
        {
        case 1:
            if (scanf("%d", &number_of_words) != 1)
            {
                printf("Invalid input\n");
                break;
            }
            for (int i = 0; i < number_of_words; i++)
            {
                if (scanf("%s", str) != 1)
                {
                    printf("Invalid input\n");
                    break;
                }
                StrList_insertLast(list, str);
            }
            break;

        case 2:
            if (scanf("%d %s", &index, str) != 2) // Tells us how many values was entered
            {
                printf("Invalid input\n");
                break;
            }
            StrList_insertAt(list, str, index);

        case 3:
            StrList_print(list);
            break;

        case 4:
            printf("%ld\n", StrList_size(list));
            break;

        case 5:
            if (scanf("%d", &index) != 1)
            {
                printf("Invalid input\n");
                break;
            }
            StrList_printAt(list, index);
            break;

        case 6:
            printf("%d\n", StrList_printLen(list));
            break;

        case 7:
            if (scanf("%s", str) != 1)
            {
                printf("Invalid input\n");
                break;
            }
            printf("%d\n", StrList_count(list, str));
            break;

        case 8:
            if (scanf("%s", str) != 1)
            {
                printf("Invalid input\n");
                break;
            }
            StrList_remove(list, str);
            break;

        case 9:
            if (scanf("%d", &index) != 1)
            {
                printf("Invalid input\n");
                break;
            }
            StrList_removeAt(list, index);
            break;

        case 10:
            StrList_reverse(list);
            break;

        case 11:
            StrList_free(list); // Freeing it and allocating a new list
            list = StrList_alloc();
            break;

        case 12:
            StrList_sort(list);
            break;

        case 13:
            printf(StrList_isSorted(list) ? "true\n" : "false\n");
        }

    } while (chose != 0);

    StrList_free(list);

    return 0;
}
