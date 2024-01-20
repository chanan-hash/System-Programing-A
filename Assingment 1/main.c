#include <stdio.h>
#include "NumClass.h"

// TODO add here a simple check for each function
int main()
{
    // int x, y, i;
    // scanf("%d%d",&a,&b); // Scaning the numbers for the  user
    printf("Checking isPrime\n");
    printf("is prime: %d\n", isPrime(0));
    printf("is prime: %d\n", isPrime(1));
    printf("is prime: %d\n", isPrime(2));
    printf("is prime: %d\n", isPrime(3));
    printf("is prime: %d\n", isPrime(7));
    printf("is prime: %d\n", isPrime(50));
    printf("is prime: %d\n", isPrime(100));

    printf("Checking is strong\n");
    printf("is Strong: %d\n", isStrong(1));
    printf("is Strong: %d\n", isStrong(2));
    printf("is Strong: %d\n", isStrong(145));
    printf("is Strong: %d\n", isStrong(40585));
    printf("is Strong: %d\n", isStrong(3));
    printf("is Strong: %d\n", isStrong(5));
    printf("is Strong: %d\n", isStrong(146));
    printf("is Strong: %d\n", isStrong(12));

    printf("Checking is palindrome\n");
    printf("is palindrom %d\n", isPalindrom(1));
    printf("is palindrom %d\n", isPalindrom(121));
    printf("is palindrom %d\n", isPalindrom(123));
    printf("is palindrom %d\n", isPalindrom(12321));
    printf("is palindrom %d\n", isPalindrom(5));
    
}