#include <stdio.h>

// int sum1(int a[]) {
//   size_t i;
//   int sum = 0;

//   for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
//     sum += a[i];
//   }
//   return sum;
// }

// int sum2(int a[42]) {
//   size_t i;
//   int sum = 0;

//   for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
//     sum += a[i];
//   }
//   return sum;
// }

// int sum3(int a[], size_t n) {
//   size_t i;
//   int sum = 0;

//   for (i = 0; i < n; i++) {
//     sum += a[i];  // a + i * sizeof(int)
//   }
//   return sum;
// }

// int sum4(int a[], size_t n) {
//   size_t i;
//   int sum = 0;

//   for (i = 0; i < n; i++) {
//     sum += a[i];
//   }
//   return sum;
// }

int PrinntArray(int a[], size_t n) {
  int *p = a;
  while (p < a + n)  // The size of the array
  {
    printf("%d\n", *p);
    p++;  // p = p + 1, moving to the pointer
  }
  return p - a;  // the number of elements in the array
}

int main() {
  //   int i, j;
  //   int *x;  // declaring on a pointer

  //   // assume the the addresses at 200 for exmp'
  //   i = 1;   // add200 = 1
  //   x = &i;  // add201[add[200]]

  //   printf("%d\n", i);
  //   printf("%d\n", x);  // will print a number
  //   printf("%p\n", x);  // printing the address

  //   j = *x;  // j = the value at x = 1 // j = addressJ[addressX[addressI]] =
  //   1 printf("%d\n", j);

  //   x = &j;  // x points on j address, changing x we'll change j as well

  //   (*x) = 3;
  //   printf("%d\n", j);
  //   printf("%d\n", *x);

  //   printf("\n");

  //   int arr[10];
  //   int *p1 = &arr[2];
  //   int *p2 = &arr[3];

  //   printf("%d\n", p2 - p1);  // 1, the number of indexes between them
  //   printf("\n");

  //   int *p;
  //   int a[3];
  //   p = &a[0];  // --> p = a

  //   *(p + 1) = 1;  // a[1] = 1, we want the value at p + 1 amount of byte to
  //   be
  //                  // equal to 1
  //   p[2] = 2;      // *(p+2) = 2

  //   *(a + 3) = 3;  // a[3] = 3, <--> *(p+3) = 3
  //   p++;           // p == a+1 == &a[1], here we worked with the addresses

  //   printf("%zu\n", sizeof(a));  // size of array 3 * sizeof(int) = 3 * 4 =
  //   12 printf("%zu\n", sizeof(p));  // sizeof a pointer is 8 bytes

  //   printf("%zu\n",
  //          sizeof(a) / sizeof(a[0]));  // 3, the size of the the array,
  //          dividing
  //                                      // by the size of the first element

  //   printf("\n");
  //   printf("%d\n", sum1(a));     // 6
  //   printf("%d\n", sum2(a));     // 6
  //   printf("%d\n", sum3(a, 3));  // 6
  //   printf("%d\n", sum4(a, 3));  // 6

  /**************************************/

  //   int a[5] = {1, 2, 3, 4, 5};
  //   int *p = a;           // points to &a[0]
  //   char *q = (char *)a;  // points to &a[0], but with casting to char

  //   // p moves by 4 bytes, q moves by 1 byte
  //   p++;  // (a+1) == &a[1]
  //   q++;
  //   printf("%d\n", *p);  // 2 --> *(a+1) == a[1]
  //   printf("%d\n", *q);  // 0 since one byte is still on the first element in
  //   the
  //   // array
  //   printf("\n");
  //   PrinntArray(a, 5);

  //   printf("\n");

  //   int array[4] = {1, 2, 3, 4};
  //   //   int *p1 = array;
  //   long i = (long)array;        // the address of the first element in the
  //   array long j = (long)(array + 1);  // the address of the second element
  //   in the array

  //   long diff = j - i;  // 4, the difference between the addresses of the
  //   first
  //                       // and second elements in the array

  //   printf("%ld\n", diff);

  /**************************************/

  //   int k, *ptr = NULL;
  //   int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  //   ptr = Arr;  // pointing on the first element in the array

  //   k = *ptr++;  // k = 1, ptr = Arr + 1. like k = *ptr, ptr++;

  //   printf("%d\n", k);

  //   k = *++ptr;  // k = 3, ptr = Arr + 2. like ptr++, k = *ptr
  //   printf("%d\n", k);

  //   k = (*ptr)++;  // k = 3, *ptr = 4, ptr = Arr + 3
  //   printf("%d\n", k);

  //   k = *(ptr++);  // k = 4, ptr = Arr + 4, like k = *ptr, ptr++
  //   printf("%d\n", k);

  //   k = ++*ptr;  // k = 5, ptr = Arr + 5, like ptr++, k = *ptr
  //   printf("%d\n", k);

  int arr2[10] = {0};  // initializing all the elements in the array to 0
  int *p_start = arr2;
  // int *p_end = arr2 + 10;
  int *p_end = &arr2[9];  // the address of the last element in the array

  int i = 0;
  for (i = 0; i < 10; i++) {
    *p_start = i;  // putting  i value in the array, and increasing the pointer
    ++p_start;
  }
  p_start = arr2;  // reseting to the first element in the array

  while (p_end >= p_start) {
    printf("%d ", *p_end);
    p_end -= 2;  // moving the pointer 2 indexes back
  }

  printf("\n");
  return 0;
}
