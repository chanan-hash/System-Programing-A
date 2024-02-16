#include <stdio.h>
#include <malloc.h>              //malloc library 

int static3darray()
{
    int i,j,k;                         //variables for nested for loops
	int arr[2][3][3];              //array declaration
	printf("enter the values in the array: \n");
	for(i=1;i<=2;i++)              //represents block
	{
		for(j=1;j<=3;j++)          //represents rows
		{
			for(k=1;k<=3;k++)      //represents columns
			{
				printf("the value at arr[%d][%d][%d]: ",i,j,k);
				scanf("%d",&arr[i][j][k]);
			}
		}
	}
	printf("printing the values in array: \n");
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=3;j++)
		{
			for(k=1;k<=3;k++)
			{
				printf("%d ",arr[i][j][k]);
				if(k==3)
				{
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}

void dynamic3dArray()
{
  int ***arr;                    //triple pointer
  int block,row,column;          //variables for block, rows and columns
  int i,j,k;                     //nested for loop
  printf("enter the blocks, rows and columns: ");
  scanf("%d %d %d",&block,&row,&column);
  arr=(int ***)malloc(sizeof(int ***)*block);
  for(i=0;i<block;i++) 
  {
    arr[i]=(int **)malloc(sizeof(int*)*row);
    for(j=0;j<row;j++) 
	{
      arr[i][j]=(int *)malloc(sizeof(int)*column);
    }
  }
  for(i=0;i<block;i++) 
  {
    for(j=0;j<row;j++) 
	{
      for(k=0;k<column;k++) 
	  {
        printf("element at [%d][%d][%d] : ",i,j,k);
        scanf("%d",&arr[i][j][k]);
      }
    }
  }
  printf("Printing 3D Array:\n");
  for(i=0;i<block;i++) 
  {
    for(j=0;j<row;j++) 
	{
      for(k=0;k<column;k++) 
	  {
        printf("%.2d ",arr[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

}
int main(int argc, char* argv[]) //command line arguments
{
    static3darray();
    dynamic3dArray();
  return 0;
}

