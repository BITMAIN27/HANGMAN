#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define SIZE 99

int main(int argc,char* argv[])
{
	
	int i;
    printf("INIT BEGIN\n");
    MY_STRING* items = malloc(sizeof(MY_STRING) * SIZE);
    for (i = 0; i < SIZE; i++) {
        items[i] = NULL;
    }
    printf("INIT COMPLETE\n");

    items[0] = init_c_string("COPY ME!");
	
	printf("INIT COPY\n");
	for(i = 1; i < SIZE ;i++)
	{
		items[i] = my_string_init_copy(items[0]);
	}
	printf("COPY COMPLETE\n");
	
	my_string_destroy(&items[0]);
	items[0] = init_c_string("FIRST FIFTY");

	printf("INIT ASSIGNMENT\n");
	for(i = 1; i<SIZE/2;i++)
	{
		my_string_assignment(items[i],items[0]);
	}
	printf("ASSIGMENT COMPLETE\n");

	printf("SWAP INIT\n");
	for(i = 0;i< SIZE/2 ;i++)
	{
		my_string_swap(items[i],items[SIZE - i- 1]);
	
	}
	printf("SWAP COMPLETE\n");
	

	for(i = 0;i< SIZE;i++)
	{
		my_string_insertion(items[i],stdout);
	}
	
	for(i = 0;i<SIZE;i++)
	{
		my_string_destroy(items+i);
	}
	free(items);

 	return 0;

}
