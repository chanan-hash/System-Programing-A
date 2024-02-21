/* bit_operators.c   Illustrates bitwise operators */
#include <stdio.h>
void main(void)
{
	unsigned char and, or, xor, comp, shiftL, shiftR;
	unsigned char mask1 = 0X78, mask2 = 0XB2;
 
	and    = mask1 & mask2;
	or     = mask1 | mask2;
	xor    = mask1 ^ mask2;
	comp   = ~mask1;
	shiftL = mask1 << 3;
	shiftR = mask1 >> 3;
 
	printf("and    = %X HEXA\n", and);
	printf("or     = %X HEXA\n", or);
	printf("xor    = %X HEXA\n", xor);
	printf("comp   = %X HEXA\n", comp);
	printf("shiftL = %X HEXA\n", shiftL);
	printf("shiftR = %X HEXA\n", shiftR);
}
