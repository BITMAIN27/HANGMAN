#include "my_string.h"
#include <string.h>
Status test_init_default_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 if(hString == NULL)
 {
 strncpy(buffer, "test_init_default_returns_nonNULL\n"
 "my_string_init_default returns NULL", length);
 return FAILURE;
 }
 else
 {
 my_string_destroy(&hString);
 strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
 return SUCCESS;
 }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 if(my_string_get_size(hString) != 0)
 {
 status = FAILURE;
 printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
 strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
 "Did not receive 0 from get_size after init_default\n", length);
 }
 else
 {
 status = SUCCESS;
 strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
 , length);
 }
 my_string_destroy(&hString);
 return status;
}



Status test_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	if (my_string_get_capacity(hString) != 7)
	{
		status = FAILURE;
		printf("Expected a capacity of 7 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
			"Did not receive 7 from get_capacity after init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}


Status test_push_back(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	if(my_string_push_back(hString, 'A') == FAILURE)
	{
		status = FAILURE;
		printf("Expected a SUCCESS got FAILURE\n");
		strncpy(buffer, "test_push_back\n"
			"Got back failure\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_push_back\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_pop_back(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	my_string_push_back(hString, 'A');
	if(my_string_pop_back(hString) == FAILURE)
	{
		status = FAILURE;
		printf("Expected a SUCCESS got FAILURE\n");
		strncpy(buffer, "test_pop_back\n"
			"Got back failure\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_pop_back\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_pop_back_return_FAILURE(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;


	if(my_string_pop_back(hString) != FAILURE)
	{
		status = FAILURE;
		printf("Expected a FAILER did NOT get FAILURE\n");
		strncpy(buffer, "test_pop_back_return_FAILURE\n"
			"Did not get back FAILURE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_pop_back_return_FAILURE\n"
			, length);
	}
	//my_string_destroy(&hString);
	return status;
}

Status test_push_back_return_FAILURE(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;


	if (my_string_push_back(hString,'A') != FAILURE)
	{
		status = FAILURE;
		printf("Expected a FAILURE did NOT get FAILURE\n");
		strncpy(buffer, "test_push_back_return_FAILURE\n"
			"Did not get back FAILURE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_push_back_return_FAILURE\n"
			, length);
	}
	//my_string_destroy(&hString);
	return status;
}

Status test_my_string_insertion_return_SUCCESS(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	//FILE* fp;
	//fp = fopen("simple.txt", "r");
	//fp = stdout;
	hString = my_string_init_default();
	my_string_push_back(hString, 'A');
	if(my_string_insertion(hString,stdout) == FAILURE)
	{
		status = FAILURE;
		printf("Expected a SUCCESS did got FAILURE\n");
		strncpy(buffer, "test_my_string_insertion_return_SUCCESS\n"
			"Got back FAILURE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_insertion_return_SUCCESS\n"
			, length);
	}
	my_string_destroy(&hString);
	//fclose(fp);
	
	return status;
}

Status test_my_string_insertion_return_FAILURE(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	FILE* fp;
	//fp = fopen("simple.txt", "r");
	fp = NULL;
	hString = my_string_init_default();
	my_string_push_back(hString, 'A');
	if (my_string_insertion(hString,fp) != FAILURE)
	{
		status = FAILURE;
		printf("Expected a FAILURE did not getFAILURE\n");
		strncpy(buffer, "test_my_string_insertion_return_FAILURE\n"
			"Did not get back FAILURE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_insertion_return_FAILURE\n"
			, length);
	}
	my_string_destroy(&hString);
	//fclose(fp);
	return status;
}

Status test_my_string_extraction_return_SUCCESS(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	FILE* fp;
	fp = fopen("simple.txt", "r");
	hString = my_string_init_default();
	my_string_push_back(hString, 'A');
	if(my_string_extraction(hString,fp) == FAILURE)
	{
		status = FAILURE;
		printf("Expected a SUCCESS did got FAILURE\n");
		strncpy(buffer, "test_my_string_extraction_return_SUCCESS\n"
			"Got back FAILURE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_extraction_return_SUCCESS\n"
			, length);
	}
	my_string_destroy(&hString);
	fclose(fp);
	return status;
}

Status test_my_string_extraction_return_FAILURE(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	FILE* fp;
	fp = NULL;
	//fp = fopen("simple.txt", "r");
	hString = my_string_init_default();
	my_string_push_back(hString, 'A');
	if (my_string_extraction(hString, fp) != FAILURE)
	{
		status = FAILURE;
		printf("Expected a SUCCESS did got FAILURE\n");
		strncpy(buffer, "test_my_string_extraction_return_SUCCESS\n"
			"Got back FAILURE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_extraction_return_SUCCESS\n"
			, length);
	}
	my_string_destroy(&hString);
	//fclose(fp);
	return status;
}




Status test_my_string_init_default(char* buffer, int length) 
{ 

	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if (hString == NULL)
	{
		status = FAILURE;
		printf("Got back NULL\n");
		strncpy(buffer, "test_my_string_init_default\n"
			"Got back NULL\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_init_default\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_my_string_destroy(char* buffer, int length) 
{ 

	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	//printf("Memeory before destroy %p\n",hString);
	my_string_destroy(&hString);
	//printf("Memory after destroy %p\n",hString);
	hString = NULL;

	if (hString != NULL)
	{
		//printf("%d",hString);
		status = FAILURE;
		printf("Failed to destory string object\n");
		strncpy(buffer, "test_my_string_destroy\n"
			"did not get NULL\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_destroy\n"
			, length);
	}
	return status;
}



Status test_my_string_compare_return_negetive(char* buffer, int length)
{
	MY_STRING hStringOne = NULL;
	MY_STRING hStringTwo = NULL;
	Status status;

	hStringOne = my_string_init_default();
	hStringTwo = my_string_init_default();

	my_string_push_back(hStringOne, 'A');

		if (my_string_compare(hStringOne,hStringTwo) != 1)
		{
			printf("got %d\n", my_string_compare(hStringOne, hStringTwo));
			status = FAILURE;
			printf("Expected 1\n");
			strncpy(buffer, "test_my_string_compare_return_negetive\n"
				"did not get 1\n", length);
		}
		else
		{
			status = SUCCESS;
			strncpy(buffer, "test_my_string_compare_return_negetive\n"
				, length);
		}
	my_string_destroy(&hStringOne);
	my_string_destroy(&hStringTwo);
	return status;
}

Status test_my_string_compare_return_positive(char* buffer, int length)
{
	MY_STRING hStringOne = NULL;
	MY_STRING hStringTwo = NULL;
	Status status;

	hStringOne = my_string_init_default();
	hStringTwo = my_string_init_default();

	my_string_push_back(hStringTwo, 'A');

	if (my_string_compare(hStringOne, hStringTwo) != -1)
	{
		printf("got %d\n", my_string_compare(hStringOne, hStringTwo));
		status = FAILURE;
		printf("Expected -1\n");
		strncpy(buffer, "test_my_string_compare_return_positive\n"
			"did not get -1\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_compare_return_positive\n"
			, length);
	}
	my_string_destroy(&hStringOne);
	my_string_destroy(&hStringTwo);
	return status;
}

Status test_my_string_compare_return_zero(char* buffer, int length)
{
	MY_STRING hStringOne = NULL;
	MY_STRING hStringTwo = NULL;
	Status status;

	hStringOne = my_string_init_default();
	hStringTwo = my_string_init_default();


	my_string_push_back(hStringOne,'A');
	my_string_push_back(hStringTwo,'A');

//	int one = my_string_get_size(hStringOne);
//	int two = my_string_get_size(hStringTwo);
//	printf("Sizes %d %d\n",one,two);
	if (my_string_compare(hStringOne, hStringTwo) != 0)
	{
		printf("got %d\n", my_string_compare(hStringOne, hStringTwo));
		status = FAILURE;
		printf("Expected 1\n");
		strncpy(buffer, "test_my_string_compare_return_zero\n"
			"did not get 0\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_compare_return_zero\n"
			, length);
	}
	my_string_destroy(&hStringOne);
	my_string_destroy(&hStringTwo);
	return status;
}

Status test_my_string_concat_RETURN_SUCCESS(char* buffer, int length) 
{ 
	MY_STRING hStringOne = NULL;
	MY_STRING hStringTwo = NULL;
	Status status;

	hStringOne = my_string_init_default();
	hStringTwo = my_string_init_default();

	my_string_push_back(hStringOne,'A');
	my_string_push_back(hStringTwo,'B');

	if (my_string_concat(hStringOne, hStringTwo) == FAILURE)
	{
		status = FAILURE;
		printf("Got back FAILURE expected SUCCESS\n");
		strncpy(buffer, "test_my_string_concat_RETURN_SUCCESS\n"
			"did not get SUCCESS\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_concat_RETURN_SUCCESS\n"
			, length);
	}
	my_string_destroy(&hStringOne);
	my_string_destroy(&hStringTwo);
	return status;
}

Status test_my_string_concat_RETURN_FAILURE(char* buffer, int length)
{
	MY_STRING hStringOne = NULL;
	MY_STRING hStringTwo = NULL;
	Status status;

	hStringOne = my_string_init_default();
	//hStringTwo = my_string_init_default();

	my_string_push_back(hStringOne, 'A');
	//my_string_push_back(hStringTwo, 'B');

	if (my_string_concat(hStringOne, hStringTwo) != FAILURE)
	{
		status = FAILURE;
		printf("Did not get back FAILURE\n");
		strncpy(buffer, "test_my_string_concat_RETURN_FAILURE\n"
			"did not get FAILURE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_concat_RETURN_FAILURE\n"
			, length);
	}
	my_string_destroy(&hStringOne);
	//my_string_destroy(&hStringTwo);
	return status;

}


Status test_my_string_empty_TRUE(char* buffer, int length)
{
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;

	//my_string_push_back(hString,'A');
	//printf("Value: -> %d\n",my_string_empty(hString));
	if (my_string_empty(hString) != TRUE)
	{
		status = FAILURE;
		printf("Did not get back TRUE\n");
		strncpy(buffer, "test_my_string_empty_TRUE\n"
			"did not get TRUE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_empty_TRUE\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_my_string_empty_FALSE(char* buffer, int length)
{
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;

	my_string_push_back(hString, 'A');

	if (my_string_empty(hString) != FALSE)
	{
		status = FAILURE;
		printf("Did not get back FALSE\n");
		strncpy(buffer, "test_my_string_empty_FALSE\n"
			"did not get FALSE\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_empty_FALSE\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_my_string_at_return_value(char* buffer, int length) 
{

	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;

	my_string_push_back(hString, 'A');

	if (my_string_at(hString,0) == NULL)
	{
		status = FAILURE;
		printf("Did not get back a vlue\n");
		strncpy(buffer, "test_my_string_at_return_value\n"
			"Got back NULL\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_return_value\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_my_string_at_return_NULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;

	//my_string_push_back(hString, 'A');

	if (my_string_at(hString, 1) != NULL)
	{
		status = FAILURE;
		printf("Did not get back NULL\n");
		strncpy(buffer, "test_my_string_at_return_NULL\n"
			"did not get back NULL\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_return_NULL\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}


Status test_my_string_c_str_Terminating_SUCCESS(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	hMy_string = my_string_init_default();
	Status status;

	char* string = my_string_c_str(hMy_string);
	
	
	int len = strlen(string);

	if (len == NULL)
	{
		status = FAILURE;
		printf("String is not NULL terminated\n");
		strncpy(buffer, "test_my_string_c_str_Terminating_SUCCESS\n"
			"Did not find the null terminator\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_c_str_Terminating_SUCCESS\n"
			, length);
	}
	my_string_destroy(&hMy_string);
	return status;



}

Status test_my_string_c_str_Terminating_FAILURE(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	hMy_string = my_string_init_default();
	Status status;

	char* string = my_string_c_str(hMy_string);

	int i;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (i >= my_string_get_size(hMy_string))
		{
			break;
		}
	}

	if (string[i] == '\0')
	{
		status = FAILURE;
		printf("String is NULL  terminated\n");
		strncpy(buffer, "test_my_string_c_str_Terminating_FAILURE\n"
			"Found the NULL terminator\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_c_str_Terminating_FAILURE\n"
			, length);
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_my_string_get_size_return_Garbage(char* buffer, int length) 
{ 
	MY_STRING hMy_string = NULL;
	//hMy_string = my_string_init_default();
	Status status;

	if (my_string_get_size(hMy_string) != -1)
	{
		status = FAILURE;
		printf("String has not size\n");
		strncpy(buffer, "test_my_string_get_size\n"
			"Size inccorect\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_get_size\n"
			, length);
	}

	return status;
}
