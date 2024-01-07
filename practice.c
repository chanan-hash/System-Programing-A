#include <stdio.h>

int main()
{
int i = 0;
int j = 0;

for ( i = 0; i < 10; i++)
{
    j+=i;
    printf("%d %d %d\n", i , j, (i*(i+1)/2));
}
return 0;
}