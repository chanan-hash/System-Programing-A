/* bit_print.c
This program reads an unsigned int and prints the 16 
( or 32 - depending on sizeof(int) )  bits that represent it. */
 
#include <stdio.h>
#include <limits.h>
 
void b_uns(unsigned num)
{
	int i;
	int mask = 1 << (8 * sizeof(int) -1); 
 
	for (i = 0 ; i < 8*sizeof(int) ; ++i)
	{
		if ( num &  mask)  			printf("1");
		else            			printf("0");
		num <<= 1;
	}
}
void main(void)
{
	unsigned num;
 
	printf("Enter an unsigned integer (0 to %u) => ", UINT_MAX); 
	scanf("%u" ,&num);
	printf("The number %u is represented by the following"
		"bits:\n", num);
	b_uns(num);
}



