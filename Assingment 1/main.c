#include <stdio.h>
#include <stdbool.h>
#include "NumClass.h"

// TODO add here a simple check for each function
int main()
{

    int num1, num2;
    // printf("Enter 2 numbers:\n");
    scanf("%d%d", &num1, &num2); // Scaning the numbers for the  user

    // Printing all the Strong numbers between them
    printf("The Armstrong numbers are:");
    for (int i = num1; i <= num2; i++)
    {
        if (isArmstrong(i))
        {
            printf(" %d", i);
        }
    }

    printf("\n");
    printf("The Palindromes are:");
    // Printing all the Prime numbers between them
    for (int i = num1; i <= num2; i++)
    {
        if (isPalindrom(i))
        {
            printf(" %d", i);
        }
    }

    printf("\n");

    // Printing all the Palindrome numbers between them
    printf("The Prime numbers are:");
    for (int i = num1; i <= num2; i++)
    {
        if (isPrime(i))
        {
            printf(" %d", i);
        }
    }

    printf("\n");

    // Printing all the Armstrong numbers between them
    printf("The Strong numbers are:");
    for (int i = num1; i <= num2; i++)
    {
        if (isStrong(i))
        {
            printf(" %d", i);
        }
    }

    printf("\n");
    
    return 0;

    // printf("Checking isPrime\n");
    // printf("is prime: %d\n", isPrime(0));
    // printf("is prime: %d\n", isPrime(1));
    // printf("is prime: %d\n", isPrime(2));
    // printf("is prime: %d\n", isPrime(3));
    // printf("is prime: %d\n", isPrime(7));
    // printf("is prime: %d\n", isPrime(50));
    // printf("is prime: %d\n", isPrime(100));

    // printf("Checking is strong\n");
    // printf("is Strong: %d\n", isStrong(1));
    // printf("is Strong: %d\n", isStrong(2));
    // printf("is Strong: %d\n", isStrong(145));
    // printf("is Strong: %d\n", isStrong(40585));
    // printf("is Strong: %d\n", isStrong(3));
    // printf("is Strong: %d\n", isStrong(5));
    // printf("is Strong: %d\n", isStrong(146));
    // printf("is Strong: %d\n", isStrong(12));

    // printf("Checking is palindrome\n");
    // printf("is palindrom %d\n", isPalindrom(1));
    // printf("is palindrom %d\n", isPalindrom(121));
    // printf("is palindrom %d\n", isPalindrom(123));
    // printf("is palindrom %d\n", isPalindrom(12321));
    // printf("is palindrom %d\n", isPalindrom(5));
    // printf("is palindrom %d\n", isPalindrom(10));

    // printf("Checking is Armstrong\n");
    // printf("is Armstrong %d\n", isArmstrong(1));
    // printf("is Armstrong %d\n", isArmstrong(2));
    // printf("is Armstrong %d\n", isArmstrong(153));
    // printf("is Armstrong %d\n", isArmstrong(407));
    // printf("is Armstrong %d\n", isArmstrong(370));
    // printf("is Armstrong %d\n", isArmstrong(371));
    // printf("is Armstrong %d\n", isArmstrong(23));
    // printf("is Armstrong %d\n", isArmstrong(10));
    // printf("is Armstrong %d\n", isArmstrong(100));
    // printf("is Armstrong %d\n", isArmstrong(1007));
}