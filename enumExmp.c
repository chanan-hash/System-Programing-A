#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum week
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};

union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    enum week today;
    today = wednesday;
    printf("Day %d\n\n", today + 1);

    /*********************** Union ******************************/

    union Data data;

    printf("Memory sizr occupied by data: %ld\n", sizeof(data));

    // Each time we're chaning the values it's override what we have in the i=ohter. beacuse they are sitting on the same block of memory
    // data.i = 20;
    // data.f = 220.5;
    // strcpy(data.str, "C programing");

    // printf("data.i : %d\n",data.i);
    // printf("data.f : %f\n",data.f);
    // printf("data.str : %s\n",data.str);

    data.i = 20;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %f\n", data.f);

    strcpy(data.str, "C programing");
    printf("data.str : %s\n", data.str);

    return 0;
}