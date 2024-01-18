#include <stdio.h>
#include <math.h>
#include "NumClass.h" // This is for our own header file


// We wiil run eith a loop till the sqrt of the number and check if it dividing by it
// false = 0, true = 1
int isPirme(int x)
{
    if (x % 2 == 0)
    { // This is an even number so it's not prime
        return 0;
    }
    
    else
    {
        int y = sqrt(x);
    
    for (int i = 3; i <= y; i++)
    {
        if (x % i == 0)
        {
            return 0; 
        }
    
    }
    return 1;
    }
}

int isStrong (int num)
{
int sum = 0; // keeping the sum of the digits
while (num > 0)
{
    int dig = num % 10; // getting the last digit number
    sum += factorial(dig);
    num /= 10; // Dividing it by 10 each iteration
}
if (sum == num)
{
    return 1;
}
else
{
return 0;
}
}

int factorial(int n)
{
    int fact = 1;
    for(int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}