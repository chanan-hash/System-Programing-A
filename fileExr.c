#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  //   FILE *stream;

  //   if ((stream = fopen("myfile.txt", "r+")) == NULL) {
  //     printf("File opened successfully\n");
  //     fclose(stream);
  //     return 1;
  //   } else {
  //     printf("Error opening file\n");
  //   }

  //   /* Reading data */
  //   printf("Reading data from file\n");
  //   char buffer[100];

  //   if (fclose(stream) == EOF) {
  //     printf("File closed successfully\n");
  //   } else {
  //     return 2;
  //     printf("Error closing file\n");
  //   }
  //   stream = fopen("myfile.txt", "rb+");
  //   if (stream == NULL) {
  //     printf("Error opening file\n");
  //     exit(1);
  //   }

  //   char buffer[100];

  //   fscanf(stream, " %s", buffer);
  //   printf("Data read: %s\n", buffer);

  //   fclose(stream);

  // FILE *file;
  // char ch;
  // char line[100];

  // int account;
  // char name[30];
  // double balance;

  // // Open the file in read mode
  // file = fopen("myfile.txt", "r+");

  // // Check if file opened successfully
  // if (file == NULL) {
  //   printf("Unable to open file.\n");
  //   return 1;
  // }

  // // Read and print each character from the file
  // //   printf("Contents of the file:\n");
  // //   while ((ch = fgetc(file)) != EOF) {
  // //     printf("%c", ch);
  // //   }
  // while (fgets(line, sizeof(line), file) != NULL) {
  //   printf("%s", line);
  // }

  // printf("Enter account, name, and balance:\n");
  // printf("Enter EOF to end input.\n");
  // printf(">>");
  // scanf("%d%s%lf", &account, name, &balance);

  // while (!feof(stdin)) {
  //   fprintf(file, "%d %s %.2f\n", account, name, balance);
  //   printf(">>");
  //   scanf("%d%s%lf", &account, name, &balance);
  // }

  // // Close the file
  // fclose(file);

  // FILE *fileread;
  // int readAccount;
  // char readName[30];
  // double readBalance;

  // if ((fileread = fopen("myfile.txt", "r")) == NULL) {
  //   printf("File could not be opened\n");
  //   return 1;
  // } else {
  //   printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
  //   fscanf(fileread, "%d%s%lf", &readAccount, readName, &readBalance);

  //   while (!feof(fileread)) {
  //     printf("%-10d%-13s%7.2f\n", readAccount, readName, readBalance);
  //     fscanf(fileread, "%d%s%lf", &readAccount, readName, &readBalance);
  //   }
  // }
  // fclose(fileread);  // Close the file}

  FILE *fp;
  char ch, st[100];

  if (!(fp = fopen("myfile.txt", "r"))) {
    exit(1);
  }

  while (fscanf(fp, "%c", &ch) != EOF) {
    printf("%c", ch);
  }
  rewind(fp);  // taking the pointer to the start of the file

  while (fgets(st, 100, fp) != NULL) {
    printf("%s\n", st);
    fclose(fp);
  }
  rename("myfile.txt", "myfile.txt");

  return 0;
}
