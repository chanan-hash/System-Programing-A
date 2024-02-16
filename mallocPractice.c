#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d,", arr[i]);
    }
}

int main()
{
    // printf("Enter an array size:\n");
    // int n;
    // scanf("%d", &n);
    // int arr[n]; // allocating  array in size n;

    // printf("Enter numbers into the array:\n");
    // for (int i = 0; i < n; ++i)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // for (int i = 0; i < n; ++i)
    // {
    //     printf("%d,", arr[i]);
    // }

    // int *arr = (int *)malloc(sizeof(int) * n); // Allocating memort space, accordding to type int size the to the value of the pointer n
    //                                            // malloc - returns an address to the first open/free byte
    // if (arr == NULL)
    // { // checking that it has been realy allocated
    //     printf("Error\n");
    // }
    // printf("Enter numbers into the array:\n");
    // for (int i = 0; i < n; ++i)
    // {
    //     scanf("%d", &arr[i]);
    // }
    // printArray(arr, n);

    // free(arr); // getting the address that malloc returned and freeing the allocated memory from it

    // In allocating memory we won't get a warning if we have used malloc and not free after it

    // Realloc
    // char *cptr = NULL; // character pointer. Equal to null so we can use later malloc in this, and not chaning the address that can be at first

    // // allocating memory
    // cptr = (char *)malloc(6 * sizeof(char)); // allocating 6 bolck of memoty, each bolck size is the size of char

    // // if failed
    // if (cptr == NULL)
    // {
    //     printf("Failed to allocate memory spce. Termination the program...");
    //     return -1;
    // }

    // // Get some text
    // printf("Enter 5 letter word: ");
    // scanf("%s",cptr);

    // // Display
    // printf("Word you've entered: %s\n",cptr);

    // // Reallocating memory
    // cptr = realloc(cptr, (9 * sizeof(char))); // getting the address to reallocate, and the size to reallocate

    // // if failed
    // if (cptr == NULL)
    // {
    //     printf("Failed to reallocate memory spce. Termination the program...");
    //     return -1;
    // }

    // // content
    // printf("\nContent of the allocated memory spce after reallocation:\n");
    // printf("%s\n\n",cptr);
    // // printf("%ld",sizeof(cptr)); ld - long decimal

    // // Get some new text
    // printf("Enter 8 letter word: ");
    // scanf("%s",cptr);

    // // Display
    // printf("Word you've entered: %s\n",cptr);

    // // Free memory
    // free (cptr);

    /************************************/

    // Exr1
    // allocating memory for float int and char

    // int *iVar;
    // char *cVar;
    // float *fVar;

    // iVar = (int *)malloc(1 * sizeof(int));
    // cVar = (char *)malloc(1 * sizeof(char));
    // fVar = (float *)malloc(1 * sizeof(float));

    // printf("Enter an integer: ");
    // scanf("%d", iVar);

    // printf("Enter a character: ");
    // scanf("%c",cVar); // because we have allocated only one  bolck of char we can't enter a string. only a char

    // //scanf(" %s", cVar); // if we want to enter a string

    // printf("Enter a float: ");
    // scanf("%f", fVar);

    // printf("The input is: %d, %c, %.2f\n", *iVar, *cVar, *fVar);

    // //printf("The input is: %d, %s, %.2f\n", *iVar, cVar, *fVar); // if we want to print a string so we won't put a star for getting the value because %s works with pointers

    // // Freeing the allocated memory
    // free(iVar);
    // free(cVar);
    // free(fVar);

    /************************************/

    // Exr2 - printing a text by a dynamic memory
    // int num;
    // char *text;

    // printf("Enter a size of text: ");
    // scanf("%d", &num);

    // // Allocating memory
    // text = (char *)malloc(num * sizeof(char));

    // printf("Enter a text: ");
    //    scanf("%s",text);
    // // scanf(" "); // Clear input buffer
    // // gets(text);
    // // puts(text);

    // printf("Input of the text is: %s\n",text);

    // // Freeing memory
    // free(text);

    /************************************/

    // Exr3

    int *arr;
    int length;
    int sum = 0;

    printf("Enter array's length: ");
    scanf("%d", &length);

    arr = (int *)malloc(length * sizeof(int));

    if (arr == NULL) // Checking condition
    {
        printf("Insufficient memory, Exiting...\n");
        return -1;
    }

    printf("Enter %d elemnts:\n", length);
    for (int i = 0; i < length; ++i)
    {
        printf("Enter elment number %3d: ", i + 1);
        scanf("%d", (arr + i)); // Equals to arr[i]
        sum += *(arr + i);      // Adding to the sum the value at the address that we've just entered in, means the value that sits in address arr + id
    }

    printf("Arrays elements are: ");
    for (int i = 0; i < length; i++)
    {
        printf("%3d", *(arr + i));
    }

    printf("\nThe sum is: %d\n", sum);

    free(arr);

    /************************************/

    //Exr4

    return 0;
}