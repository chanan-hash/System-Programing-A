#ifndef _NUMCLASS_H // For the preproccesor, if it's not defined define it, it's to keep that we are not including this code twicegcc
#define _NUMCLASS_H

// This class is holding the sings of our functions
/*will return if a number is Armstrong number.
An Armstrong number is an n-digits number that is equals to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int);

/*will return if a number is palindrom*/
int isPalindrom(int);

/*will return if a number is prime*/
int isPrime(int);

/*Strong number is a special number whose sum of factorial of digit is equal to original number.
 For Example: 145 is storng number
 1! + 4! + 5! = 145
*/
int isStrong(int);

#endif