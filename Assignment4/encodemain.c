#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

int main(int argc, int *argv[])
{

    const char *inputFileName = argv[2]; // the name of the file

    char outputName[256];

    //  converting the regular file to notbinary
    if ((strstr(argv[2], ".txt") != NULL) && (strstr(argv[1], "-c") != NULL))
    {
        change_F_end(inputFileName, outputName, ".bin");
        conv_F_to_bin(inputFileName, outputName);
    }

    // decoding from notbinary to integer
    else if ((strstr(argv[2], ".bin") != NULL) && (strstr(argv[1], "-d") != NULL))
    {
        change_F_end(inputFileName, outputName, ".txt");
        conv_bin_to_F(inputFileName, outputName);
    }
    else
    {
        printf("Invalid File or command!\n");
        return -1;
    }

    printf("Complite to convert!\n");
    return 0;
}