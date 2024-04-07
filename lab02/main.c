#include "my_string.h"	
#include <stdio.h>
#include <stdlib.h>	


	int main(int argc, char* argv[])
	{
		MY_STRING string;
		MY_STRING leftString;
		MY_STRING rightString;

		leftString = my_string_init_c_string("hello");
		rightString = my_string_init_c_string("hello There");

		printf("%d\n", my_string_compare(leftString, rightString));
		printf("%d\n", my_string_get_size(leftString));
		printf("%d\n", my_string_get_capacity(leftString));


		my_string_destory(&leftString);
		my_string_destory(&rightString);

		return 0;
	}
