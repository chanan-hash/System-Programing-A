#include <stdlib.h> // for malloc
#include <stdio.h>  // for printf
#include <string.h> // for memcpy

// Do not learn styling from this code

/// Prints the given array.
///
/// \param arr - the given array.
/// \param sz - number of elements in the array.
void printArr(const int arr[], size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
    {
        printf("%d ", arr[i]);
    }
}

/// Swaps two blocks of memory.
/// We assume the blocks don't overlap.
/// If memory runs out the function has undefined behavior.
///
/// \param p1,p2 - the blocks to swap.
/// \param size  - the size of the blocks.
void memswap_memcpy(void *p1, void *p2, size_t size)
{
    void *tmp;
    tmp = malloc(size);

    printf("In memswap_memcpy\n ");

    memcpy(tmp, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, tmp, size);

    free(tmp);
    return;
}

/// Swaps two blocks of memory.
/// We assume the blocks *don't overlap*.
///
/// \param p1,p2 - the blocks to swap.
/// \param size  - the size of the blocks.
void memswap_arr(void *p1, void *p2, size_t size)
{
    size_t i;
    char *pc1 = (char *)p1;
    char *pc2 = (char *)p2;
    char ch;

    printf("In memswap_arr\n ");

    for (i = 0; i < size; ++i)
    {
        ch = pc1[i];
        pc1[i] = pc2[i];
        pc2[i] = ch;
    }
}

/// Swaps two blocks of memory.
/// We assume the blocks don't overlap.
///
/// \param p1,p2 - the blocks to swap.
/// \param size  - the size of the blocks.
void memswap_ptr(void *p1, void *p2, size_t size)
{
    size_t i;
    char *pc1 = (char *)p1;
    char *pc2 = (char *)p2;
    char ch;

    printf("In memswap_ptr\n ");

    for (i = 0; i < size; ++i)
    {
        ch = *pc1;
        *pc1 = *pc2;
        *pc2 = ch;
        ++pc1;
        ++pc2;
    }
}

int main()
{

    int i1, i2;
    double d1, d2;
    i1 = 1;
    i2 = 2;
    d1 = 1.1;
    d2 = 2.2;
    memswap_memcpy(&i1, &i2, sizeof(int));
    printf("i1==%d i2==%d \n", i1, i2);
    memswap_memcpy(&d1, &d2, sizeof(double));
    printf("d1==%f d2==%f \n", d1, d2);

    i1 = 1;
    i2 = 2;
    d1 = 1.1;
    d2 = 2.2;
    memswap_arr(&i1, &i2, sizeof(int));
    printf("i1==%d i2==%d \n", i1, i2);
    memswap_arr(&d1, &d2, sizeof(double));
    printf("d1==%f d2==%f \n", d1, d2);

    i1 = 1;
    i2 = 2;
    d1 = 1.1;
    d2 = 2.2;
    memswap_ptr(&i1, &i2, sizeof(int));
    printf("i1==%d i2==%d \n", i1, i2);
    memswap_ptr(&d1, &d2, sizeof(double));
    printf("d1==%f d2==%f \n", d1, d2);

    // Overlap memory swap - will fail - ill defined...
    int arr[] = {1, 2, 3, 4};
    int *parr0 = &arr[0];
    int *parr1 = &arr[1];
    const size_t arrSizeM1 = sizeof(arr) / sizeof(arr[0]) - 1;

    // Overlap memory swap (ill defined) - will fail (at least logically)
    printf("parr0==");
    printArr(parr0, arrSizeM1);
    printf("parr1==");
    printArr(parr1, arrSizeM1);

    memswap_memcpy(parr0, parr1, sizeof(arr[0]) * arrSizeM1);
    printf("parr0==");
    printArr(parr0, arrSizeM1);
    printf("parr1==");
    printArr(parr1, arrSizeM1);
    printf("\n\n");

    return 0;
}
