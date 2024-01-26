#include <stdio.h>
// #include <math.h>
#include <stdbool.h>
#include "NumClass.h"

/**
 * We can't use 'math.h' library so we'll create our own functions:
 * log10, and pow
 */

// This we'll replace the log10 function, for getting the digit number
int getDigNum(int number)
{
    int digNum = 0;
    while (number > 0)
    {
        digNum++;
        number /= 10;
    }
    return digNum;
}

// returning x^p
int getPower(int x, int p)
{
    int pow = 1;
    for (int i = 1; i <= p; i++)
    {
        pow = pow * x;
    }
    return pow;
}

// We'll revers the number and check if it is eqaul to the origin number
// We'll vreate a new number that equals to the reversed one, and check if they both equals
int isPalindrome(int num)
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
    int power = getDigNum(n), sum = 0, temp = n;

    while (temp > 0)
    {
        int dig = temp % 10;
        sum += (int) getPower(dig, power);
        temp /= 10;
    }
    return ((sum == n) ? 1 : 0);
}

// int isArmstrong(int n)
// {
//     int power = ((int)log10(n) + 1), sum = 0, temp = n;

//     while (temp > 0)
//     {
//         int dig = temp % 10;
//         sum += (int)pow(dig, power);
//         temp /= 10;
//     }
//     return ((sum == n) ? 1 : 0);
// }
