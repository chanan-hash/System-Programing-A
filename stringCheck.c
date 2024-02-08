#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * To run this file use the command
 * gcc -Wall -g stringCheck.c -o stringCheck.exe
 * ./stringCheck.exe
 * */ 


// char *strcat2(char *dest, char *src)
// {
//     char *str12 = dest + strlen(dest); // assuming that dest has enough to hod both string
//     while (*src != '\0')
//     {
//         *str12 = *src; // from the end of dest starting to point to the second string
//         str12++;       // incrementing the pointers
//         src++;
//     }
//     *str12 = '\0'; // ending the pointer with '\0' as accepted
//     return dest;
// }

int ourStrcmp(char *s1, char *s2)
{
    while (*s1 && *s2) // while their are not equals to 0, and their values are equal because we're using *
    {
        s1++;
        s2++; // going forward with the pointer
    }
    return *s1 - *s2; // like a comparator
}

bool endWith(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 < len2)
    { // can't be a sub string
        return false;
    }
    return !strcmp(s1 + len1 - len2, s2); // we are checking form the end of the one before last word of s1, if the last word after it is s2, using pointers
                                          // == &s1[len1-len2]
}

// checking how many times str1 one is in str2, case-insensitive --> 'a' == 'A'
char upCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 'A'; // making them all Capital letters
    }
    return c; // it is already capital letter
}

int isEqualsStringN(char s1[], char s2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (upCase(s1[i]) != upCase(s2[i]))
        {
            return 0; // they are not equal
        }
    }
    return 1;
}

int CountSubstring(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int count = 0;
    for (int i = 0; i <= len2 - len1; i++)
    {
        if (isEqualsStringN(s1, s2 + i, len1))
        {
            count++;
        }
    }
    return count;
}

// Turning a num String to number

int char2dig(char ch)
{
    return ch - '0'; // getting the digit of the char
}

// in each iteration we'll find the digit, and according to the place we'll multiply by 10;
int str2num(char *str)
{
    int sign = 1;
    int num = 0;

    if (*str == '-')
    {
        sign = -1; // if the value at the addres of the pointer is minus we need to change the sing
        str++;     // moving to the next number/charecter
    }
    while (*str != '\0')
    {
        num = num * 10 + char2dig(*str);
        str++;
    }
    return sign * num;
}

int main()
{
    // char str1[] = "My Cat";
    // char str2[10] = "My Cat";
    // char str3[] = {'M','y',' ','C','a','t'};
    // char str4[7] = {'M','y',' ','C','a','t'};
    // char str5[7] = {'M','y','\0','C','a','t'};
    // char str6[7] = {'M','y','0','C','a','t'};
    // char str7[7] = "";

    // printf("%zu\n",sizeof(str1));
    // printf("%zu\n",sizeof(str2));
    // printf("%zu\n",sizeof(str3));
    // printf("%zu\n",sizeof(str4));
    // printf("%zu\n",sizeof(str5));
    // printf("%zu\n",sizeof(str6));
    // printf("%zu\n",sizeof(str7));

    // printf("\n");

    // printf("%zu\n",strlen(str1));
    // printf("%zu\n",strlen(str2));
    // printf("%zu\n",strlen(str3));
    // printf("%zu\n",strlen(str4));
    // printf("%zu\n",strlen(str5));
    // printf("%zu\n",strlen(str6));
    // printf("%zu\n",strlen(str7));

    // puts(str1);
    // puts(str2);
    // puts(str3);
    // puts(str4);
    // puts(str5);
    // puts(str6);
    // puts(str7);

    // char name[5];
    // printf("enter your name: ");
    // scanf("%s", name);
    // printf("name = %s\n ",name);

    char str1[] = "My Cat ";
    char str2[10] = "My Cat";

    char *new_string = strcat(str1, str2);
    // char *string2 = strcat2(str1, str2);
    printf("%s\n", new_string);
    puts(new_string);
    // printf("\n%s", string2);
    printf("\n");

    int cmp = ourStrcmp(str1, str2);
    printf("%d\n", cmp);

    char *st1 = "Hello world!";
    char *st2 = "world!";
    char *st3 = "Hello";

    bool is = endWith(st1, st2);
    bool is2 = endWith(st2, st1);
    bool is3 = endWith(st1, st3);

    printf("%d\n", is);
    printf("%d\n", is2);
    printf("%d\n", is3);

    printf("\n");

    char s2[] = "kaba 2 abababaBA$";
    char s1[] = "aba";

    int count1 = CountSubstring(s1, s2);
    int count2 = CountSubstring(s2, s1);

    printf("%d\n", count1);
    printf("%d\n", count2);
    printf("\n");

    char *s3 = "235424";
    char *s4 = "-2144";

    int n1 = str2num(s3);
    int n2 = str2num(s4);
    printf("%d\n", n1);
    printf("%d\n", n2);

    char *beatles[4] = {"John lennon", "Paul McCartny", "George Harrison", "Ringo Starr"};
    for (int i = 0; i < 4; i++)
    {
        printf("beatle %d = %s\n", i + 1, beatles[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Please welcome %s, who plays the %s!\n", *(beatles + i), (i == 3) ? "drums" : "guitar");

        printf("Here is his name is revers: ");
        for (int j = strlen(beatles[i])-1; j >= 0; j--)
        {
            // Same version for the printing. In the end it is like a matrix, and we're just accessing to it value, that is a char from the name
            // putchar((*(beatles + i))[j]); // the value form address of beatles --> the name, and them one of the chars --> [j]
            // putchar(*(beatles[i] + j));
            // putchar(*(*(beatles + i) + j));
            putchar(beatles[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}