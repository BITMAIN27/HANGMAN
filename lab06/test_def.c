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

	FILE* fp;
	//fp = fopen("simple.txt", "r");
	fp = stdout;
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
	if(status == SUCCESS)
	{
	printf("SUCCESS!!\n");
	}
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




Status test_my_string_init_default(char* buffer, int length){return SUCCESS;}

Status test_my_string_destroy(char* buffer, int length) {return SUCCESS;}

Status test_my_string_extraction(char* buffer, int length){return SUCCESS;}

Status test_my_string_insertion(char* buffer, int length){return SUCCESS;}

Status test_my_string_get_size(char* buffer, int length){return SUCCESS;}

Status test_my_string_get_capacity(char* buffer, int length){return SUCCESS;}

Status test_my_string_push_back(char* buffer, int length){return SUCCESS;}

Status test_my_string_pop_back(char* buffer, int length){return SUCCESS;}

Status test_my_string_at(char* buffer, int length){return SUCCESS;}

Status test_my_string_c_str(char* buffer, int length){return SUCCESS;}

Status test_my_string_concat(char* buffer, int length){return SUCCESS;}

Status test_my_string_empty(char* buffer, int length){return SUCCESS;}

Status test_my_string_print(char* buffer, int length){return SUCCESS;}

Status test_my_string_init_default_NULL(char* buffer, int length){return SUCCESS;}



