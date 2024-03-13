#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question 1.a

char *input() {
  int count = 0;  // for realocating memory

  char c;  // for reading characters

  // for storing the chars
  char *str = (char *)malloc((count + 1) * sizeof(char));
  char *cpy = str;

  // while we're getting characters and it is not a new line
  while (scanf("%c", &c) && c != '\n') {
    count++;
    // reallocate memory, count +1 for the '\0'
    str = realloc(str, (count + 1) * sizeof(char));
    if (!str) {
      printf("Memory allocation failed\n");
      free(cpy);
      return NULL;  // that we'll say to the user that the allocation failed and
                    // he needs to free str
    }
    cpy = str;
    str[count - 1] = c;
  }

  str[count] = '\0';  // add the null terminator
  return str;
}

// Question 1.b

void creating_fifo(int *my_fifo, int size) {
  //   my_fifo = (int *)malloc(size * sizeof(int));
  //   if (!my_fifo) {
  //     printf("Memory allocation failed\n");
  //     return;
  //   }
  my_fifo = (int *)malloc(size * sizeof(int));
}

// Question 2.c

int main(void) {
  //   char *str = input();

  //   printf("%s\n", str);
  //   free(str);

  //   int *my_fifo;

  // Question 1.c
  //   int i = 32, j = 4, k, *q, u;  // k and u, aren't used can be a problem

  //   k = --i / j;  // 31/4 = 7
  //   q = &j;       // q equals to the address of j

  //   int m;  // none used variable can be a problem

  //   {
  //     int i, j = 10;
  //     i = j - ++(*q);  // can be a problem,
  //     // because q point to address of another j;
  //     // 10 - (4+1 = 5) = 5
  //     printf("i = %d, j = %d\n", i, j);  // i = 5, j = 10
  //   }
  //   printf("i = %d, j = %d\n", i, j);  // i = 31, j = 5 and not 4
  // because we've move'd the pointer

  // Question 2.a

  // case 1.
  char *m[7];  // this is a pointer to array of 7 char, pointer to pointer

  // case 2.
  char(*m2)[7];

  printf("%zu\n", sizeof(m));   // 56
  printf("%zu\n", sizeof(*m));  // 8 gives the amount of bytes we have
  // char = 1 byte, 1 * 8 = 8 bits, 7 * 8 = 56 bytes

  printf("\n");
  printf("%zu\n", sizeof(m2));   // 56
  printf("%zu\n", sizeof(*m2));  // 8

  // Question 2.c

  //   int counter;
  //   char str[10];
  //   printf("Enter a string: \n");
  //   scanf("%s", str);

  //   for (int i = 0; i < strlen(str); i++) {
  //     if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <=
  //     'Z')) {
  //       counter++;
  //     }
  //   }
  //   //  printf("%zu\n", strlen(str));

  //   printf("Numbers of letters = %d\n", counter);

  // Chatgpt solution
  //   char *input = NULL;  // Pointer to store input string
  //   int count = 0;
  //   char ch;

  //   // Prompt user for input
  //   printf("Enter a string: ");

  //   // Read characters until newline or EOF is encountered
  //   while ((ch = getchar()) != '\n' && ch != EOF) {
  //     // Check if the character is an alphabet letter
  //     if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
  //       count++;  // Increment count if the character is a letter
  //     }
  //   }

  //   printf("Number of letters: %d\n", count);

  //   // Free dynamically allocated memory
  //   free(input);

  return 0;
}