#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Question 1
// void init_array(const double *array1, double array2[]) {
//   size_t num_items = sizeof(*array1) / sizeof(array1[0]);

//   for (size_t i = 0; i < num_items; i++) {
//     array2[i] = 2 * array1[i];
//   }
// }

// Question 2.a
void print_digits(int num1, int num2) {
  int len_b = 1;
  int temp = 10;
  while (num2 / temp > 0) {  // calculating the length of num2
    len_b++;
    temp *= 10;  // getting the height power of the number
  }
  temp = 1;
  for (int i = 0; i < len_b - num1; i++) {
    temp *= 10;
    printf("%d", num2 / temp);
  }
}

// Question 2.b
// finding the last location of a char in a string, if not exist return -1
int last_location(char c, char *str) {
  int location = -1;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == c) {
      location = i;
    }
  }
  return location;
}

// Their solution
int last_location2(char c, char *str) {
  int i = 0, ret = -1;
  while (*str) {  // while not '\0'
    if (*str == c) {
      ret = i;
    }
    i++;
    str++;
  }
  return ret;
}

// Question 2.c

// counting the number of spaces in a string
int count_space(char *str) {
  int counter = 0;
  while (*str) {
    if (*str == ' ') {
      counter++;
    }
    str++;  // moving also the pointer
  }
  return counter;
}

char *add_word(char **pstr) {  // pointer to a string
  int word_len = 0;
  char *ref = *pstr;  // start of the string
  while (*ref != ' ' && *ref == '\0') {
    word_len++;
    ref++;
  }
  //   char *word = (char *)malloc(word_len * sizeof(char) + 1);
  char *word = (char *)malloc(word_len * sizeof(char) + 1);

  if (!word) {  // if couldn't allocate memory
    return NULL;
  }

  for (int i = 0; i < word_len; i++) {
    word[i] = ref[i];
  }
  *pstr = *pstr + word_len +
          1;  // moving the original pointer word_len + 1 char forward
  return word;
}

// freeing all the acllocated memory

void free_words(char **arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] != NULL) {  // means something is there
      free(arr[i]);
      continue;
    }
    break;
  }
  free(arr);
  return;
}

// This function getting a string and spliting it according to spcae, and return
char **split_space(char *str) {
  int space_num = count_space(str);
  char **out_arr = (char **)malloc(sizeof(char *) * space_num + 1);

  if (!out_arr) {  // allocation failed
    return NULL;
  }
  int i = 0;
  while (*str) {
    out_arr[i] = add_word(&str);  // sending the address of the string is like
                                  // sending two pointers
    if (!out_arr[i]) {
      free_word(out_arr, space_num);
    }
    i++;
  }
  return out_arr;
}

int main() {
  //   double array1[7] = {1.2, 2.4, 4.8};
  //   double array2[7];

  //   init_array(array1, array2);

  //   for (int i = 0; i < 7; i++) {
  //     printf("%f, ", array2[i]);
  //   }
  //   printf("\n");

  // Question 1.b

  //   char testarr[] = {'A', 'B', 'C'};
  //   char *ptr = testarr;

  //   char val;

  //   val = *++ptr;

  //   printf("%c, %c\n", val, *ptr);  // B, B

  //   val = *ptr++;

  //   printf("%c, %c\n", val, *ptr);  // B, C

  return 0;
}
