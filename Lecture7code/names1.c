/*names1.c Creates an array of strings, each of an unknown length*/
#include <stdio.h>
#include <stdlib.h> /* prototypes of malloc(), free(), exit() */
#include <string.h> 
#define EXIT_FAIL 42
void free_names(char * names[], int num); /* prototype */
 
int get_names(char *names[], int num)
{
	int i = 0;
	char str[128];
	do {
	     puts("Enter a name (press CTRL/Z ENTER to stop) "
					" => "); 
		if (gets(str) == NULL)
			break;
		
		 names[i] = (char*) malloc(strlen(str)+1) 
if(names[i]== NULL)
		{
			puts ("Not enough memory. Sorry.\n");
			free_names(names, i); /* some memory has
					 been allocated ! */ 
			exit(EXIT_FAIL);
		} 
		strcpy(names[i], str); /* copy the name into the
							 memory */  
	}while (++i < num);
	return i;/* return the actual number of names in the array */
}
 
void print_names(const char *names[], int num)
{
	int i;
	for (i = 0 ; i < num ; i++) 
		printf("%2d) %s\n", i + 1, names[i]);
}
void free_names(char * names[], int num)
{  
	int i; 
	for( i = 0 ; i < num ; ++i )
		free(names[i]);
}
 
void main(void)
{
	char *names[10]; /* an array of 10 pointers to char */
	int final_num;/*in case the user enters less than 10 names*/  
	final_num = get_names(names, 10);/* get names into the
							 array */
	print_names(names, final_num);/*print the array of names*/ 
	free_names(names, final_num);/* free all the allocated
							 memory */
}

