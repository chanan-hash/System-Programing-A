#ifndef COMPRESS_H
#define COMPRESS_H
#include <stdio.h>
// Converting digits 0-9 to their to binary and to their not format
// Doing it in strait forword way
// int convert_to_bin(int);

// void convert_to_bin(int, char*);

// void compress_file(const char*, const char*);

void str_to_bin(char, FILE*);

void conv_F_to_bin(const char *,const char *);

void bin_to_str(char, FILE *);

void conv_bin_to_F(const char *,const char *);

void change_F_end(const char *,const char *,const char *);


#endif