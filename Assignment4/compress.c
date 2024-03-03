#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

// // int convert_to_bin(int dig)
// // {
// //     if (dig == 0)
// //     {
// //         return 1111;
// //     }
// //     else if (dig == 1)
// //     {
// //         return 1110;
// //     }
// //     else if (dig == 2)
// //     {
// //         return 1101;
// //     }
// //     else if (dig == 3)
// //     {
// //         return 1100;
// //     }
// //     else if (dig == 4)
// //     {
// //         return 1011;
// //     }
// //     else if (dig == 5)
// //     {
// //         return 1010;
// //     }
// //     else if (dig == 6)
// //     {
// //         return 1001;
// //     }
// //     else if (dig == 7)
// //     {
// //         return 1000;
// //     }
// //     else if (dig == 8)
// //     {
// //         return 0111;
// //     }
// //     else // dig == 9
// //     {
// //         return 0110;
// //     }
// // }

// void convert_to_bin(int digit, char *binString)
// {
//     switch (digit)
//     {
//     case 0:
//         strcpy(binString, "1111");
//         break;
//     case 1:
//         strcpy(binString, "1110");
//         break;
//     case 2:
//         strcpy(binString, "1101");
//         break;
//     case 3:
//         strcpy(binString, "1100");
//         break;
//     case 4:
//         strcpy(binString, "1011");
//         break;
//     case 5:
//         strcpy(binString, "1010");
//         break;
//     case 6:
//         strcpy(binString, "1001");
//         break;
//     case 7:
//         strcpy(binString, "1000");
//         break;
//     case 8:
//         strcpy(binString, "0111");
//         break;
//     case 9:
//         strcpy(binString, "0110");
//         break;
//     default:
//         fprintf(stderr, "Invalid digit: %d\n", digit);
//         exit(EXIT_FAILURE);
//     }

//     // Creating the binarynot file
//     void compress_file(const char *inputFileName, const char *outputFileName)
//     {
//         if (strcmp(inputFileName, outputFileName) != 0)
//         {
//             fprintf(stderr, "input and output name are different");
//             exit(EXIT_FAILURE);
//         }

//         FILE *inputFile, *outputFile;
//         char binaryString[5]; // 4 bit + 1 for NULL terminator

//         if ((inputFile = fopen(inputFileName, "r")) == NULL)
//         {
//             perror("Error opening input file");
//             exit(EXIT_FAILURE);
//         }

//         if ((outputFile = fopen(outputFileName, "wb")) == NULL)
//         {
//             perror("Error opening output file");
//             fclose(inputFile);
//             exit(EXIT_FAILURE);
//         }

//         while (fscanf(inputFile, "%1d", &digit) == 1) // means we succeeded to scan one digit and not more
//         {
//             convert_to_bin(digit, binString);
//             fwrite(binString, sizeof(char), 4, outputFile);
//         }

//         fclose(inputFile);
//         fclose(outputFile);
//     }
// }

// learning from Elyasf kopl. The idea is to write it strait to the file itself
// https://github.com/elyasafko/TM_task_4
// the input file is a text file so we're working with chars and strings
void str_to_bin(char C, FILE *outputF)
{
    if (c >= 0 && c <= 9)
    {
        switch (c)
        {
        case '0':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '1':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '2':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '3':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '4':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '5':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '6':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '7':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '8':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        case '9':
            fwrite("1111", sizeof(char), 4, outputF);
            break;
        default:
            break;
        }
    }
}

void conv_F_to_bin(const char *inputFileName, const char *outputFileName)
{
    FILE *inputFile = fopen(inputFileName, "r");   // only for reading
    FILE *outputFile = fopen(outputFileName, "w"); // only for writing

    if (inputFile == NULL || outputFile == NULL)
    {
        perror("Error in opening");
        return;
    }

    int c;
    int counter = 0; // To know if it is has odd number of digigts to put another 0000 in the end

    while ((c = fgetc(inputFile)) != EOF)
    {
        str_to_bin(c, outputFile);
        counter++;
    }
    if (counter % 2 != 0) // may have bug
    {
        fwrite("0000", sizeof(char), 4, outputFile);
    }

    if (fclose(inputFile) == EOF || fclose(outputFile) == EOF)
    {
        perror("Error closing");
        return;
    }
}

void bin_to_str(char c, FILE *outputF)
{
    char str[2];
    str[0] = c;
    str[1] = '\0'; // End of a string

    if (strcmp(str, "1111", 4) == 0)
    {
        fprintf(outputF, "0");
    }
    else if (strcmp(str, "1110", 4) == 0)
    {
        fprintf(outputF, "1");
    }
    else if (strcmp(str, "1101", 4) == 0)
    {
        fprintf(outputF, "2");
    }
    else if (strcmp(str, "1100", 4) == 0)
    {
        fprintf(outputF, "3");
    }
    else if (strcmp(str, "1011", 4) == 0)
    {
        fprintf(outputF, "4");
    }
    else if (strcmp(str, "1010", 4) == 0)
    {
        fprintf(outputF, "5");
    }
    else if (strcmp(str, "1001", 4) == 0)
    {
        fprintf(outputF, "6");
    }
    else if (strcmp(str, "1000", 4) == 0)
    {
        fprintf(outputF, "7");
    }
    else if (strcmp(str, "0111", 4) == 0)
    {
        fprintf(outputF, "8");
    }
    else if (strcmp(str, "0110", 4) == 0)
    {
        fprintf(outputF, "9");
    }
    else
    {
        fprintf(outputF, " ");
    }
}

void conv_bin_to_F(const char *inputFileName, const char *outputFileName)
{
    FILE *inputFile = fopen(inputFileName, "r");   // only for reading
    FILE *outputFile = fopen(outputFileName, "w"); // only for writing

    if (inputFile == NULL || outputFile == NULL)
    {
        perror("Error in opening");
        return;
    }

    char buffer[4];
    size_t byteread;

    while ((byteread = fread(buffer, sizeof(char), 4, inputFile)) > 0)
    {
        for (size_t i = 0; i < byteread; i++)
        {
            bin_to_str(buffer[i], outputFile);
        }
    }

    if (fclose(inputFile) == EOF || fclose(outputFile == EOF))
    {
        perror("Error closing");
        return;
    }
}

void change_F_end(const char *inputName, const char *outputName, const char *newEnding)
{
    strcpy(outputName, inputName);
    char *dot = strrchr(outputName, '.'); // adding the dot in the end of the string

    if (dot != NULL)
    {
        strcpy(dot, newEnding);
    }
    else
    {
        strcat(outputName, newEnding);
    }
}
