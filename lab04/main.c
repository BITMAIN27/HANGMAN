#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc,char* argv[])
{

	MY_STRING hMy_string = NULL;
	MY_STRING hAppend = NULL;
	MY_STRING hTest = NULL;
	hTest = my_string_init_default();
	hAppend = my_string_init_default();
 	hMy_string = my_string_init_default();
	

my_string_push_back(hAppend,'H');
my_string_push_back(hAppend,'E');
my_string_push_back(hAppend,'L');
my_string_push_back(hAppend,'L');
my_string_push_back(hAppend,'O');

	


	my_string_push_back(hMy_string,'A');

	my_string_print(hMy_string);

	my_string_push_back(hMy_string,'B');

	my_string_print(hMy_string);

	my_string_push_back(hMy_string,'C');

	my_string_print(hMy_string);


	my_string_pop_back(hMy_string);

	my_string_print(hMy_string);



	printf("Address of index provided is: %p\n",my_string_at(hMy_string,1));

	printf("Address of null terminated string is: %p\n",my_string_c_str(hMy_string));

	printf("hResult before:"); my_string_print(hMy_string);
	my_string_concat(hMy_string,hAppend);
	printf("hResult after:"); my_string_print(hMy_string);
	
	printf("\n");

	if(my_string_empty(hTest) == TRUE)
	{
		printf("String is empty\n");
	}
	else
	{
		printf("string is NOT empty\n");
	}
	
	my_string_destroy(&hTest);
	my_string_destroy(&hAppend);
 	my_string_destroy(&hMy_string);
 	



 	return 0;

}
