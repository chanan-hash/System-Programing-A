#include <stdio.h>
#include <stdlib.h>
void someFunction(int args)
{
    printf("This is someFunction being called and arg is: %d\n", args);
    printf("leavingthe function now!\n");
}

int compare(const void *left, const void *right) // This is a comperator
{
    return (*(int *)right - *(int *)left); // bigger than zero if r > l, less than zero if r < l, and zero if equal
    // This will give us descending order, left - right will give ascending order
}

int main()
{

    void (*pf)(int); // pointer void to be generic, and casting to int

    pf = &someFunction; // can be also without the '&' pf = someFunction

    printf("We're about to call someFunction() using a pointer!\n");

    (pf)(5); // like someFunction(5);

    printf("Wow that was cool! Back to main now!\n\n");

    int (*cmp)(const void *, const void *);

    cmp = compare;

    int iarray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    qsort(iarray, sizeof(iarray) / sizeof(*iarray), sizeof(*iarray), cmp); // array, size of array, sizeof the type (first element int the array) and compare function
                                                                           // The reason to use  'sizeof(iarray) / sizeof(*iarray)', for generic types, if we don't know what kind of array is it. That why cmp geeting void types
    int c = 0;
    while (c < sizeof(iarray) / sizeof(*iarray))
    {
        printf("%d \t", iarray[c]);
        c++;
    }
    printf("\n");

    return 0;
}