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
// int count_space(char *str) {
//   int counter = 0;
//   while (*str) {
//     if (*str == ' ') {
//       counter++;
//     }
//     str++;  // moving also the pointer
//   }
//   return counter;
// }

// char *add_word(char **pstr) {  // pointer to a string
//   int word_len = 0;
//   char *ref = *pstr;  // start of the string
//   while (*ref != ' ' && *ref == '\0') {
//     word_len++;
//     ref++;
//   }
//   //   char *word = (char *)malloc(word_len * sizeof(char) + 1);
//   char *word = (char *)malloc(word_len * sizeof(char) + 1);

//   if (!word) {  // if couldn't allocate memory
//     return NULL;
//   }

//   for (int i = 0; i < word_len; i++) {
//     word[i] = ref[i];
//   }
//   *pstr = *pstr + word_len +
//           1;  // moving the original pointer word_len + 1 char forward
//   return word;
// }

// // freeing all the acllocated memory

// void free_words(char **arr, int size) {
//   for (int i = 0; i < size; i++) {
//     if (arr[i] != NULL) {  // means something is there
//       free(arr[i]);
//       continue;
//     }
//     break;
//   }
//   free(arr);
//   return;
// }

// // This function getting a string and spliting it according to spcae, and
// return char **split_space(char *str) {
//   int space_num = count_space(str);
//   char **out_arr = (char **)malloc(sizeof(char *) * space_num + 1);

//   if (!out_arr) {  // allocation failed
//     return NULL;
//   }
//   int i = 0;
//   while (*str) {
//     out_arr[i] = add_word(&str);  // sending the address of the string is
//     like
//                                   // sending two pointers
//     if (!out_arr[i]) {
//       free_word(out_arr, space_num);
//     }
//     i++;
//   }
//   return out_arr;
// }

// Question 3

typedef struct Node {
  int matrix[2][3];
  struct Node *next;
} Node, *pNode;

// creating a simple single node
pNode create(int mat[2][3]) {
  pNode node = (pNode)malloc(sizeof(Node));
  if (!node) {
    return NULL;
  }
  node->next = NULL;

  //   for (int i = 0; i < 6; i++) {
  //     node->matrix[i] =
  //         mat[i];  // can be also with to loops, here we can use one loop
  //         because
  //                  // in the memory it's sits in one array
  //   }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      node->matrix[i][j] = mat[i][j];
    }
  }
  return node;
}

void add(Node **head, pNode node) {
  Node **p = head;
  while (*p) {
    p = &((*p)->next);  // or p = p->next
  }
  *p = node;

  // Node *n = StrList->head;
  //         while (n->_next != NULL) // while (p->_next !=NULL)
  //         {
  //             n = n->_next;
  //             // p = &((*p)._next);
  //         }
  //         n->_next = p;
}

void print_node(pNode node) {
  //   for (int i = 0; i < 2; i++) {
  //     for (int j = 0; j < 3; j++) {
  //       printf("%d ", node->matrix[i][j]);
  //     }
  //     printf("\n");
  //   }

  printf("%d %d %d\n", node->matrix[0][0], node->matrix[0][1],
         node->matrix[0][2]);
  printf("%d %d %d\n\n\n", node->matrix[1][0], node->matrix[1][1],
         node->matrix[1][2]);
}

void print_all(pNode head) {
  while (head) {  // != NULL
    print_node(head);
    head = head->next;
  }
  return;
}

void free_list(Node **head) {
  Node **p = head;
  while (*p) {
    Node *temp = *p;    // to hold the current node
    p = &((*p)->next);  // p = p->next;
    free(temp);
  }
  //   free(head); // we'll get "invalid pointer" error
  return;
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

  // Question 3

  int m1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int m2[2][3] = {{7, 8, 9}, {10, 11, 12}};
  int m3[2][3] = {0};  // initializing all the values to 0
  int m4[2][3] = {1};  // initializing the first value to 1 and the rest to 0

  Node *head = NULL;

  add(&head, create(m1));  // &head == **head
  add(&head, create(m2));
  add(&head, create(m3));
  add(&head, create(m4));

  print_all(head);
  free_list(&head);  // like **head

  return 0;
}
