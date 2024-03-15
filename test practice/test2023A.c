#include <stdio.h>

// Question 1

char get_char() {    // it was void changed to char
  static int i = 0;  // static variable only in this function
  i++;               //  i = 1
  char c = 'a';
  return c + i;  // return 'a' + 1 = 'b', we'll return int and not char
}

void print_char(char c) { printf("%c ", c); }  // printing a character

void print_two_chars(char c1, char c2) {
  printf("%c %c ", c1, c2);
}  // printing two characters

// // Question 2.a
// int result(int c1, int c2, unsigned o1, unsigned o2) {
//   if () {
//     return c1 + c2;
//   } else if () {
//     return c2 - c1;
//   } else if () {
//     return c1 * c2;
//   } else if () {
//     return c1 / c2;
//   }
// }

// // Question 2.b bitfields
// struct status_struct {
//                 :1;
//                 unsigned int c1 : 5;
//                 :1;
//                 unsigned int c2 : 2;
//                 :1;
//                 unsigned int o1 : 1;
//                 :1;
//                 unsigned int o2 : 1;
//                 :1;
// };

// // Question 2.c | &  ^ ~
// void xor_bitwise(int a, int b) {
//   int c = a ^ b;
//   printf("%d\n", c);
// }

// Question 3

struct Node {
  int data;
  struct Node *next;
};

typedef struct QUEUE {
  int size = 0;
  struct Node *front;
} queue, *pqueue;

void push(queue q, int num) {
  if (q.size == 0) {
    q.front = (struct Node *)malloc(sizeof(struct Node));
    q.front->data = num;
    q.front->next = NULL;
    q.size++;
  } else {
    struct Node *temp = q.front;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = (struct Node *)malloc(sizeof(struct Node));
    temp->next->data = num;
    temp->next->next = NULL;
    q.size++;
  }
}

int pop(queue q) {
  if (q.size == 0) {
    return -1;
  } else {
    int num = q.front->data;
    struct Node *temp = q.front;
    q.front = q.front->next;
    free(temp);
    q.size--;
    return num;
  }
}

int main() {
  //   char c1 = get_char();  // c1 = b;
  //   char c2 = get_char();  // c2 = c; because i is static and it is not
  //   reset

  //   printf("1: \n");
  //   print_two_chars(c1, c2);  // b c
  //   printf("\n");
  //   printf("2: \n");
  //   print_two_chars(get_char(), get_char());
  //   // undefined can be both "d e"
  //   // or "c d" because the static variable is not reset, and we
  //   // don;t know who we'll be call first

  //   printf("\n");
  //   printf("3: \n");
  //   if (get_char() > 'd' || get_char() < 'q') {
  //     // first get_char will increment to 'f', second condition doesn't
  //     matter print_char(get_char());  // g print_char(get_char());  // h
  //   }

  //   printf("\n");
  //   printf("4: \n");
  //   if (get_char() > 'd' && get_char() < 'q') {  // 'i' and then 'j'
  //     print_char(get_char());                    // k
  //     print_char(get_char());                    // l
  //   }
  //   printf("\n");

  // Question 2.b

  //   struct status_struct status;
  //   if (status.o1 && status.o2) printf("%d\n", status.c1 / status.c2);
  //   // o1 = 1 o2 = 1 --> 1&1 = 1,
  //   if (status.o1 && !status.o2) printf("%d\n", status.c1 * status.c2);
  //   // o1 = 1, o2 = 0 --> !0 = 1 --> 1&1

  //   if (!status.o1 && !status.o2) printf("%d\n", status.c1 + status.c2);
  //   // o1 = 0, o2 = 0 --> !0 = 1, !0 = 1 --> 1&1 = 1

  //   if (!status.o1 && status.o2) printf("%d\n", status.c1 - status.c2);
  //   // o1 = 0, o2 = 1 --> !0 = 1, 1&1 = 1

  return 0;
}