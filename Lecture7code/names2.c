/* names2.c
Creates an array for unknown number of strings. The length of each
string is also unknown. Dynamic memory allocation is used. */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_FAIL 42
void free_names(char **names, int num)
{
	while(num > 0)
		free(names[--num]);
}
 
void print_names(const char **names, int num)
{
	int ctr;
 	printf("The following %d names were entered :\n",
							 num);
	for(ctr = 0 ; ctr < num ; ++ctr)
		printf("%2d) %s\n", ctr + 1, names[ctr]);
}
void get_names(char **names, int *num)
{
	int i = 0;     
	char str[128]; /* for getting names from the user */
 	/* loop until num names have been entered or until the user
	chooses to stop entering names. */  
	do 
	{
        printf("Enter the #%d name (press CTRL/Z ENTER"
			"to stop)=> ",i+1); 
	   if(gets(str) == NULL) /* the user wants to stop
						 entering names */
		break; 
	   if((names[i] = (char*)malloc(strlen(str)+1))==NULL)
	   { 
		puts ("Not enough memory. Sorry.\n");
		free_names(names, i); /* some memory was
					 allocated! Free it ! */ 
		free(names);
     	exit(EXIT_FAIL); 
	   } 
		strcpy(names[i], str); /* copy the name into the
							 memory */  
		}while (++i < *num);
 
	*num = i; /* update the number of names */
}
 
int get_number_of_names()
{
	int num = 0; 
 
	while(num <= 0) /* loop until a legal number has been
							 entered */
	{
		printf("How many names do you wish to enter ? "
 			"=> ");
		scanf("%d", &num);
		getchar();
	}
	return num;
 }

void main(void)
{   
	char **names = NULL;      /* will be an array of string */
	int num;/* the number of names that the user wants to keep */ 
 
	num = get_number_of_names(); 
 
   /* allocate memory for num elements, each is a pointer to char*/
	names = (char**)malloc(num * sizeof(char*));
	if(! names) /* there is not enough available consecutive
							 memory */
	{
		puts("There is not enough memory for the"
			"program. Sorry.\n");
		exit(EXIT_FAIL); 
	}
	/* call a function that will get the names. The variable num
	is sent 	by address so that if the user chooses to enter fewer 
	names that he originally intended to enter, the function will
	change num to the correct number of names that were 
	entered.*/
    get_names(names, &num);
	
	/* print the array of names */
	print_names(names, num); 
 
	/* free the memory that was dynamically allocated for the 
							names */ 
	free_names(names, num); 
 
	/* the array of pointers was also allocated dynamically. 
							Free it */
	free(names); 
}

