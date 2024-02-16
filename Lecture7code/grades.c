/* grades.c
This program calculates the average grade of a class. The 
programmer doesn’t know the number of students in the class, so 
he can’t declare an array.
Dynamic allocation is used instead */
 
#include <stdio.h>
#include <stdlib.h> /* for the prototypes of malloc, free and 
exit */
#define EXIT_FAIL 42
 
void main(void)
{
	float *grades = NULL; /* the grades are of type float */
	int num_students; /* will be entered by the user */
	float sum = 0; /* will help calculating the average. */
	int ctr;
	do
	{ /* loop until a legal number of students is entered */ 
	   printf("How many students are there in class?=> ");
	   scanf("%d", &num_students);
	} while(num_students <= 0); 
	/* now we know the number of students, so we can dynamically
	allocate an array for holding their grades (floats) */
	grades = (float*)malloc(num_students * sizeof(float));
    grades = (float*)calloc(n,sizeof(float));
	/* if there isn’t enough consecutive memory,malloc() returns
							 NULL */
	if(! grades)
	{
		puts("There is not enough memory. Sorry.\n"); 
		exit (EXIT_FAIL); /* exit the program */
	}

	for (ctr = 0; ctr < num_students ; ++ctr) /* get the
							 grades */
	{
		printf("Enter grade #%d: ", ctr + 1);
		scanf("%f", &grades[ctr]);
		sum += grades[ctr]; /* for calculating the average
							 later */
	}
 
	printf("The average of the grades is : %f\n",  sum/num_students);
	/* memory that was allocated by malloc/calloc must be freed!*/
	free(grades);   /* free the allocated memory */
} 

