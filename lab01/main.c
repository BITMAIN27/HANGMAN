#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	int** arr2d = (int**)malloc(sizeof(int*) * 20); //dynamically allocated a 2D array
	int i,o;
	for(i = 0;i< 20;i++)
	{
		arr2d[i]	= (int*)(malloc(sizeof(int) * 30));
		
	}
	int num = 0;
	for(i = 0;i< 20;i++)
	{
		for(o = 0;o < 30;o++)
		{
			arr2d[i][o] = num++;		
		}	
		num -= 29;
	}
	
	printf("I created a 2D array \n");
	
	for(i = 0;i< 20;i++)
	{
		for(int o = 0;o< 30;o++)
		{
			printf("%4d",arr2d[i][o]);		
		}	
		printf("\n");
	}
	
	for(i = 0;i< 20;i++)
	{
		free(arr2d[i]);	
	}
	free(arr2d);
 
  return 0;
}
