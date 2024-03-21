#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Q1

// The function gets a string apparently a number and converting it to a number
// int func(char* str) {
//   int sigen = 1;
//   if (*str == '-') {
//     sigen = -1;  // if the first char is '-' the sigen will be -1
//     str++;       // moving the pointer to the next char
//   }
//   int res = *str;  // res = the first char
//   // str++;           // moving the pointer to the next char

//   while (*str)  // while the pointer is not null
//   {
//     res *= 10;          // res = res * 10
//     res += *str - '0';  // res = res + the char
//     str++;              // moving the pointer to the next char
//   }
//   return res * sigen;  // return the result * the sigen
// }

// Their code and it's doesn't work
int func(char* str) {
  int sigen = 1;
  if (*str == '-') {
    sigen = -1;
    str++;
  }
  int res = *str;
  // str++; // remove this
  while (*str) {
    res *= 10;
    // res+= *str;
    res += *str - '0';  // the '0' is a char
    str++;
  }
  return res * sigen;
}

// function that take a int and convert to string
int lengthNum(int num) {
  int len;
  while (num > 0) {
    num /= 10;
    len++;
  }  // the len will be the number of digits
  return len;
}

// char* intToStr(int num) {
//   int len = lengthNum(num);
//   char* str = (char*)malloc(len + 1);
//   str[len] = '\0';
//   while (num > 0) {
//     str[len - 1] = num % 10 + '0';
//     num /= 10;
//     len--;
//   }
//   return str;
// }

char* toString(int num) {
  // first we'll do malloc
  int len = lengthNum(num);
  int temp = num;
  char* str = (char*)malloc((len + 1) * sizeof(char));  // for the '\0'
  if (str == NULL) {
    free(str);
  }
  str[len] = '\0';  // the last char will be '\0'
  while (temp > 0) {
    int digit = temp % 10;       // each time this is the One's digit
    str[len - 1] = digit + '0';  // converting the digit to char
    temp /= 10;                  // moving to the next digit
    len--;
  }

  return str;
}

// char* toString2(int num) {
//   int len = lengthNum(num);
//   int tmp = num, power = 0, i = 0;

//   char* str = (char*)malloc((len + 1) * sizeof(char));
//   if (str == NULL) {
//     free(str);
//     return NULL;
//   }

//   while (tmp) {
//     power = (int)pow((double)10, (double)len - i);
//     tmp = tmp / power;
//     str[i] = tmp - '0';  // converting the digit to char
//     i++;
//     tmp = num % power;
//   }
//   str[len] = '\0';  // or str[len] = 0;
//   return str;       // The user we'll need to free it
// }

// Q2
typedef struct NodeWorker {
  int id;
  char* name;
  struct worker*
      under[5];  // array of pointers to workers that each one is a struct

} worker, *pworker;

// pworker createWorker(int id, char* name) {
//   pworker newWorker = (pworker)malloc(sizeof(worker));
//   if (newWorker == NULL) {
//     free(newWorker);
//     return NULL;
//   }
//   newWorker->id = id;
//   newWorker->name = (char*)malloc(strlen(name) + 1);
//   if (newWorker->name == NULL) {
//     free(newWorker->name);
//     free(newWorker);
//     return NULL;
//   }
//   strcpy(newWorker->name, name);
//   for (int i = 0; i < 5; i++) {
//     newWorker->under[i] = NULL;
//   }
//   return newWorker;
// }

pworker newWork(int id, char* name) {
  worker* newWorker = (worker*)malloc(sizeof(worker));
  if (newWorker == NULL) {
    free(newWorker);
    return NULL;
  }

  newWorker->id = id;
  newWorker->name = (char*)malloc(strlen(name) * sizeof(char));
  if (newWorker->name == NULL) {
    free(newWorker->name);
    free(newWorker);
    return NULL;
  }
  strcpy(newWorker->name, name);  // copy the name to the newWorker->name
  for (int i = 0; i < 5; i++) {
    newWorker->under[i] = NULL;  // initializing the under array to NULL
  }
  return newWorker;
}

// first need to find the manger

pworker findManager(pworker worker, int id) {
  if (worker == NULL) {
    return NULL;
  }
  if (worker->id == id) {
    return worker;
  }
  for (int i = 0; i < 5; i++) {
    // recursive call for each employee in the array 'under'
    pworker manger = findManager(worker->under[i], id);
    if (manger != NULL) {
      return manger;
    }
  }
  return NULL;  // didn't find the manger
}

void addWorker(pworker* comp, pworker worker, int id) {
  if (id == -1) {
    comp = &worker;  // because the company is a pointer ot the first worker
    // *comp = worker;
    return;
  }

  // here *comp is the worker like the root of the tree
  pworker manger = findManager(*comp, id);
  int i = 0;
  for (i = 0; i < 5; i++) {
    if (manger->under[i] == NULL) {
      manger->under[i] = worker;  // in struct '=' is for copy
      return;                     // or break;
    }
  }
  if (i == 5) {  // means the is no place for the new worker
    printf("The manger is full\n");
  }
  printf("worker added\n");
  return;
}

// Q3

int is_in_string(char* str, char c) {
  while (*str) {
    if (*str == c) {
      return 1;
    }
    str++;  // moving the pointer
  }
  return 0;
}

// need to think about it
int max_new_increase_substring(char* str) {
  char max = 'a';
  int count = 0, i = 0;
  while (*str) {
    if (str[i] < str[i + 1]) {
      count++;
      i++;
      max = str[i] > max ? str[i] : max;
    } else if (str[i] > max && is_in_string(str, str[i])) {
      count++;
      max = str[i];
      i++;
    } else {
      count = 0;
      i++;
    }
  }

  return 0;
}

int main() {
  char* str = "123456789";
  printf("%d\n", func(str));
  printf("%ld\n", strlen(str));

  char* st = "abfaaczcak";
  printf("%d\n", max_new_increase_substring(st));

  char* string = (char*)malloc(100 * sizeof(char));
  // gets(string);
  // scanf("%s", string);  // or to do malloc. but it's not necessary

  // int len = strlen(string);
  printf("%d\n", max_new_increase_substring(string));
  free(string);

  return 0;
}
