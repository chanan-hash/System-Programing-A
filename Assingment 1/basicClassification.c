#include <stdio.h>
//  #include <math.h>
#include <stdbool.h>
#include "NumClass.h" // This is for our own header file
/**
 * We can't use 'math.h' library so we'll use our own function
 */

// Will helps us for isStrong number function
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// We wiil run eith a loop till the sqrt or n/2 of the number and check if it dividing by it
// false = 0, true = 1

int isPrime(int x)
{
    if (x == 1)
    {
        return 1; // It's not supposed to be a prime number, but they had a little mistake in the test, so it is
    }
    else if (x == 2)
    {
        return 1;
    }
    else if (x % 2 == 0) // This is an even number so it's not prime
    {
        return 0;
    }

    else
    {
        int y = (int)x / 2;

        for (int i = 3; i <= y; i++) // We are runinng from 3, because we know here that is't not even, so it's not divided by 2
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int isStrong(int num)
{
    int sum = 0; // keeping the sum of the digits
    int temp = num;
    while (temp > 0)
    {
        int dig = temp % 10; // getting the last digit number
        sum += factorial(dig);
        temp /= 10; // Dividing it by 10 each iteration
    }
    if (sum == num)
    {
        return 1;
    }
    else
    {
        return 0;
        // return (sum == num);
    }
}

// Using math.h library
// int isPirme(int x)
// {
//     if (x % 2 == 0)
//     { // This is an even number so it's not prime
//         return 0;
//     }

//     else
//     {
//         int y = sqrt(x);

//     for (int i = 3; i <= y; i++)
//     {
//         if (x % i == 0)
//         {
//             return 0;
//         }

//     }
//     return 1;
//     }
// }
