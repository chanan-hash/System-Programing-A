#include <stdio.h>

#define COLS 5
#define ROWS 3

// Question 1
void f(int *z) {
  int *a, b;  // a is a pointer, b is an int
  z++;        // moving z pointer 4 bytes because it is an int pointer
  a = &z[0];  // a is going to be the address of z[0], that is actually the
              // address of z[1]
  b = z[2];   // b is going to be the value of z[2], that is actually z[3]
  (*a)--;     // decrementing the value of z[1]
  ++b;        // incrementing the value of z[3]
}

// Question 2
int Get_1D_Array(int arr[], int n) { return arr[n]; }

// Question 3 a
// getting aa binary file, that has number and string. The number represent the
// size of the string. The function is going to read the number and the string
// and reversing it, without using any more memory, and writing it int the end
// of the file, after it printing it

int reversfile(FILE *file, char *filename) {
  file = fopen(filename, "ab+");
  int size = 0;
  fread(&size, sizeof(size), 1, file);   // reading into size the number that
                                         // represent the size of the string
  fseek(file, -sizeof(char), SEEK_END);  // going to the end of the file
  for (int i = 0; i < size; i++) {
    char ch;
    fread(&ch, sizeof(ch), 1, file);     // reading the string
    fwrite(&ch, sizeof(char), 1, file);  // writing the string
    printf("%c", ch);
    fseek(file, -2 * (i + 1) * sizeof(char) - 1,
          SEEK_CUR);  // going back 2 bytes
  }
  printf("\n");
  fclose(file);
}

// Question 3 b
int f1(int a) { return a + 1; }

// getting a pointer to a function and an array
// This function is operating the function on each element of the array, and
// return the sum of the results
int applyArray(int (*f)(int), int arr[]) {
  int result = 0;
  for (int i = 0; i < 4; i++) {
    result += f(arr[i]);
  }
  return result;
}

// Question 4
// We have a struct that represent a matrix, and we want to create a function
typedef struct _matrix {
  int rows;
  int cols;
  int **data;
} Matrix;

// In the end the user we'll need to know to free it
Matrix *createMatrix(int rows, int cols) {
  Matrix *m =
      (Matrix *)malloc(sizeof(Matrix));  // allocating memory for the struct
  m->rows = rows;
  m->cols = cols;
  m->data = (int **)malloc(
      rows * sizeof(int *));  // allocating memory for the rows of the matrix

  for (int i = 0; i < rows; i++) {
    m->data[i] = (int *)malloc(cols * sizeof(int));
  }
  return m;
}

// putting the values of the matrix
void setMatrix(Matrix *m, int *old_mat[]) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; i < m->cols; j++) {
      m->data[i][j] = old_mat[i][j];
    }
  }
}

// Addition of two matrices
Matrix *addMatrix(Matrix *m1, Matrix *m2) {
  if (m1->rows != m2->rows || m1->cols != m2->cols) {
    return NULL;
  }
  Matrix *m3 =
      createMatrix(m1->rows, m1->cols);  // creating the new third matrix
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->cols; j++) {
      m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
    }
  }
  return m3;
}

// printing the matrix
void printMatrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("%d ", m->data[i][j]);
    }
    printf("\n");
  }
}

// freeing the memory
void freeMatrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {  // freeing every row
    free(m->data[i]);
  }
  free(m->data);  // freeing the pointer to the rows
  free(m);        // freeing the struct
}

int main() {
  // Question 1
  // int arr[5] = {10, 20, 30, 40, 50};
  // f(arr);
  // for (int i = 0; i < 5; i++) {
  //   printf("%d ", arr[i]);
  //   printf("\n");
  // }

  // Question 2
  // int arr[ROWS][COLS] = {
  //     {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
  // printf("%d\n", Get_1D_Array(arr, 5));  // it'll return 6, because it is the
  //                                        // 5th element in the 1D array

  // Question 3
  int arr1 = {6, 4, 3, 0};

  // int *ptrFunc = &f1;
  int (*ptrFunc)(int) = &f1;
  int result = applyArray(ptrFunc, arr1);

  printf("%d\n", result);

  return 0;
}