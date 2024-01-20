#include <stdio.h>
// #include <math.h>
#include "NumClass.h"

int isPalindrom(int number)
{
    if (number == reversRec(number))
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

// Helpers function for them
// we'll check th3e palindrom in the same idea, by reversing the numbers
// This funciton without using 'math.h' library

int reversRec(int rev)
{
    int dig = getDigitNum(rev);
    if (rev == 0)
    {
        return 0;
    }
    return (rev % 10 * getPowerRec(10, dig)) + reversRec(rev / 10); // The recursion call
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

// The power will get from the 'getDigitNum' function
int sumOfDigit(int number, int power)
{
    if (number == 0)
    {
        return 0; // This is like to initializ a variable of sum
    }
    return (getPowerRec(number % 10, power) + sumOfDigit(number / 10, power));
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
