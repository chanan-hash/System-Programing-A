
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// char* st;

// void input() {
//   gets(st);  // str = is global
// }

// void input2() {
//   int count = 0;
//   char c;
//   char* str = (char*)malloc(sizeof(char) * (count + 1));
//   char* cpy = str;
//   while (getchar() != '\n') {
//     c = getchar();
//     count++;
//     str = (char*)realloc(str, sizeof(char) * (count + 1));
//     if (str == NULL) {
//       free(cpy);
//       return;
//     }
//     cpy = str;
//     str[count - 1] = c;
//   }
//   str[count] = '\0';
//   return str;
// }

#include <stdio.h>

void BinaryToText(char *inputFile, char *outputFile) {
  FILE *finp = fopen(inputFile, "rb");
  FILE *fout = fopen(outputFile, "w");

  if (finp == NULL || fout == NULL) {
    printf("Error opening files.\n");
    return;
  }

  unsigned int num;
  int len;

  while (fread(&len, sizeof(len), 1, finp) == 1) {
    unsigned char *str =
        (unsigned char *)malloc(len + 1);  // Allocate space for string
    if (str == NULL) {
      printf("Memory allocation failed.\n");
      fclose(finp);
      fclose(fout);
      return;
    }
    fread(str, len, 1, finp);
    str[len] = '\0';  // Null-terminate the string
    fread(&num, sizeof(num), 1, finp);
    fprintf(fout, "%s %u\n", str, num);
    free(str);  // Free allocated memory
  }

  fclose(finp);
  fclose(fout);
}

void BinaryToText2(char *inputFile, char *outputFile) {
  unsigned char str[256];
  unsigned int num;  // assuming 32 bit ints
  int i, len;

  FILE *finp = fopen(inputFile, "rb");
  FILE *fout = fopen(outputFile, "w");

  while ((len = fgetc(finp)) != EOF) {
    fread(str, len, 1, finp);
    str[len] = '\0';
    num = (unsigned int)fgetc(finp) << 24;
    num |= fgetc(finp) << 16;
    num |= fgetc(finp) << 8;
    num |= fgetc(finp);
    fprintf(fout, "%s %d\n", (char *)str, num);
  }
  fclose(finp);
  fclose(fout);
}

int main(void) {
  int(*m1)[7];
  int *m[7];
  printf("%ld %ld %ld %ld\n", sizeof(m1), sizeof(m), sizeof(*m1), sizeof(*m));

  //  BinaryToText2("input.bin", "output.txt");
  return 0;
}