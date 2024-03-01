#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

// int main(int argc, int **argv){
int main()
{
    compress_file("input.txt","output.bin");
    return 0;
}