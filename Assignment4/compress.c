#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

// int convert_to_bin(int dig)
// {
//     if (dig == 0)
//     {
//         return 1111;
//     }
//     else if (dig == 1)
//     {
//         return 1110;
//     }
//     else if (dig == 2)
//     {
//         return 1101;
//     }
//     else if (dig == 3)
//     {
//         return 1100;
//     }
//     else if (dig == 4)
//     {
//         return 1011;
//     }
//     else if (dig == 5)
//     {
//         return 1010;
//     }
//     else if (dig == 6)
//     {
//         return 1001;
//     }
//     else if (dig == 7)
//     {
//         return 1000;
//     }
//     else if (dig == 8)
//     {
//         return 0111;
//     }
//     else // dig == 9
//     {
//         return 0110;
//     }
// }

void convert_to_bin(int digit, char *binString)
{
    switch (digit)
    {
    case 0:
        strcpy(binString, "1111");
        break;
    case 1:
        strcpy(binString, "1110");
        break;
    case 2:
        strcpy(binString, "1101");
        break;
    case 3:
        strcpy(binString, "1100");
        break;
    case 4:
        strcpy(binString, "1011");
        break;
    case 5:
        strcpy(binString, "1010");
        break;
    case 6:
        strcpy(binString, "1001");
        break;
    case 7:
        strcpy(binString, "1000");
        break;
    case 8:
        strcpy(binString, "0111");
        break;
    case 9:
        strcpy(binString, "0110");
        break;
    default:
        fprintf(stderr, "Invalid digit: %d\n", digit);
        exit(EXIT_FAILURE);
    }

    // Creating the binarynot file
    void compress_file(const char *inputFileName, const char *outputFileName)
    {
        if (strcmp(inputFileName, outputFileName) != 0)
        {
            fprintf(stderr, "input and output name are different");
            exit(EXIT_FAILURE);
        }

        FILE *inputFile, *outputFile;
        char binaryString[5]; // 4 bit + 1 for NULL terminator

        if ((inputFile = fopen(inputFileName, "r")) == NULL)
        {
            perror("Error opening input file");
            exit(EXIT_FAILURE);
        }

        if ((outputFile = fopen(outputFileName, "wb")) == NULL)
        {
            perror("Error opening output file");
            fclose(inputFile);
            exit(EXIT_FAILURE);
        }

        while (fscanf(inputFile, "%1d", &digit) == 1) // means we succeeded to scan one digit and not more
        {
            convert_to_bin(digit, binString);
            fwrite(binString, sizeof(char), 4, outputFile);
        }

        fclose(inputFile);
        fclose(outputFile);
    }
}
