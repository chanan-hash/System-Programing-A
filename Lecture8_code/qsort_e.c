#include <stdlib.h>
#include <stdio.h>
#include <limits.h> // for INT_MAX INT_MIN
#include <float.h>  // for DBL_MAX DBL_MIN

// Do not learn styling from this code

int int_compare(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    if ((*ia) > (*ib))         return 1;
    if ((*ia) < (*ib))         return -1;
    return 0;
}

int double_compare(const void *a, const void *b)
{
    const double *da = (const double *)a;
    const double *db = (const double *)b;
    if ((*da) > (*db))        return 1;
    if ((*da) < (*db))        return -1;
    return 0;
}

int main()
{

    size_t i;
    typedef int (*CompareFunc)(const void *, const void *);

    CompareFunc comp1, comp2;

    int arr[] = {INT_MIN, INT_MAX, 6, 5, 1, 3, 1, 4};
    const char *printfFormat = "%d ";
    const size_t ELEM_SIZE = sizeof(arr[0]);
    const size_t ARR_LEN = sizeof(arr) / ELEM_SIZE;

    double darr[] = {DBL_MAX, 0.1, 0.4, 0.3, -3, 41, 0.3, -DBL_MAX};
    const char *dprintfFormat = "%.2e ";
    const size_t DELEM_SIZE = sizeof(darr[0]);
    const size_t DARR_LEN = sizeof(darr) / DELEM_SIZE;

    comp1 = &int_compare;
    qsort(arr, ARR_LEN, ELEM_SIZE, comp1);
    for (i = 0; i < ARR_LEN; ++i)
    {
        printf(printfFormat, arr[i]);
    }
    printf("\n");

    comp2 = &double_compare;
    qsort(darr, DARR_LEN, DELEM_SIZE, comp2);
    for (i = 0; i < DARR_LEN; ++i)
    {
        printf(dprintfFormat, darr[i]);
    }
    printf("\n");

    return 0;
}
