#include <stdio.h>
#include <math.h>
#include "NumClass.h"

// We'll revers the number and check if it is eqaul to the origin number
// We'll vreate a new number that equals to the reversed one, and check if they both equals
int isPalindrom(int num)
{
    int revers = 0, dig = 0, temp = num;
    while (temp > 0)
    {
        dig = temp % 10;
        revers = revers * 10 + dig;
        temp /= 10;
    }
    return num == revers ? 1 : 0;
}

// To find if a givven number is an Armstrong number, we'll find the number of digits, the take if digit of the number and power it up,
// and check if the sum is equals to the origing number
int isArmstrong(int n)
{
    int power = ((int)log10(n) + 1), sum = 0, temp = n;

    while (temp > 0)
    {
        int dig = temp % 10;
        sum += (int)pow(dig, power);
        temp /= 10;
    }
    return ((sum == n) ? 1 : 0);
}