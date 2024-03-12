/**
 * This code for checking if two given files have the same information
 */

#include <stdio.h>

// Copilot solution
int diffFiles(char *file1, char *file2) {
  FILE *f1 = fopen(file1, "r");
  FILE *f2 = fopen(file2, "r");

  if (f1 == NULL || f2 == NULL) {
    return -1;  // Error opening files
  }

  char ch1, ch2;
  while ((ch1 = fgetc(f1)) != EOF && (ch2 = fgetc(f2)) != EOF) {
    if (ch1 != ch2) {  // comparing chars
      return 0;        // return false
    }
  }

  if (ch1 != ch2) {  // end of file
    return 0;        // return false
  }

  fclose(f1);
  fclose(f2);
  return 1;  // return true
}

// Practice solution
int diff(char *fname1, char *fname2) {
  FILE *f1, *f2;

  char c1, c2;

  f1 = fopen(fname1, "r");  // only for reading
  f2 = fopen(fname2, "r");

  if (!f1 || !f2) {
    return -1;  // Error opening files
  }

  do {
    c1 = fscanf(f1, "%c", &c1);
    c2 = fscanf(f1, "%c", &c2);

  } while (c1 == 1 && c2 == 1 && c1 == c2);

  fclose(f1);
  fclose(f2);

  return (c1 == EOF && c2 == EOF);
}

int main() {
  int ans;
  ans = diff("file1.txt", "file2.txt");
  if (ans == -1) {
    printf("Error opening files\n");
  } else if (ans == 1) {
    printf("The files have the same information\n");
  } else {
    printf("The files do not have the same information\n");
  }

  return 0;
}