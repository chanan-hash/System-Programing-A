#include <stdio.h>
// #include <math.h>
#include <stdbool.h>
#include "NumClass.h"

// Helpers function for them
// we'll check th3e palindrom in the same idea, by reversing the numbers
// This funciton without using 'math.h' library
// We gazering the 'rev' this is the the varivable for reversing the number
int reversRec(int num, int rev)
{
    if (num == 0)
    {
        return rev;
    }
    rev = (rev * 10) + (num % 10);
    return reversRec(num / 10, rev); // The recursion call
}

// Helpers functions for Armstrong number

int getDigitNum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1 + getDigitNum(n / 10);
}

// Power function to replcae 'math.h'
// Getting x and power, returning x^power

int getPowerRec(int x, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else
    {
        return getPowerRec(x, power - 1) * x;
    }
}


// The power will get from the 'getDigitNum' function
int sumOfDigit(int number, int power)
{
    if (number == 0)
    {
        return 0; // This is like to initializ a variable of sum
    }
    return (getPowerRec(number % 10, power) + sumOfDigit(number / 10, power));
}

int isPalindrom(int number)
{
    if (number == reversRec(number, 0))
    {
        return 1;
    }
    return 0;
}

int isArmstrong(int num)
{
    int power = getDigitNum(num);
    int res = sumOfDigit(num, power);
    return (num == res ? 1 : 0);
}

// int reversRec(int rev)
// {
//     int dig = (int)log10(rev);
//     if (rev == 0)
//     {
//         return 0;
//     }
//     return (rev % 10 * pow(10, dig)) + reversRec(rev / 10); // The recursion call
// }

// int sumOfDigit(int number, int power)
// {
//     if (number == 0)
//     {
//         return 0; // This is like to initializ a variable of sum
//     }
//     return (pow(number % 10, power) + sumOfDigit(number / 10, power));
// }
