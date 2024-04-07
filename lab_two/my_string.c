#include <stdio.h>
#include <stdlib.h>
#include "string.h"


MY_STRING my_string_init_default(void);

int my_string_get_capacity(MY_STRING hMy_string);

int my_string_get_size(MY_STRING hMy_string);

MY_STRING my_string_init_c_string(const char* c_string);

void my_string_destory(MY_STRING* phMy_string);

struct my_string 
{
	int size;
	int capacity;
	int* data;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
	My_string* pMy_string = (My_string*)(malloc(sizeof(My_string)));
	if (pMy_string != NULL)
	{
		printf("Successfuly created an object\n");
		pMy_string->capacity = 7;
		pMy_string->size = 0;
		pMy_string->data = (char*)malloc(sizeof(char*) * pMy_string->capacity);
		if (pMy_string->data == NULL)
		{
			free(pMy_string);
			return NULL;
		}

	}

	return (MY_STRING)pMy_string;
}


int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->size;
}


MY_STRING my_string_init_c_string(const char* c_string)
{
	
	My_string* pMy_string = (My_string*)(malloc(sizeof(My_string)));
	if (pMy_string != NULL)
	{
		//printf("%d\n", strlen(c_string));
		//allocate memory for the string
		pMy_string->size = strlen(c_string);
		pMy_string->capacity = pMy_string->size + 1;


		pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
		if (pMy_string->data == NULL)
		{
			free(pMy_string);
			return NULL;
		}
		//pMy_string->data = (char*)c_string;
		strcpy(pMy_string->data, (char*)c_string);

		
		
	}
	return (MY_STRING)pMy_string;
	
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	My_string* pLeft_string = (My_string*)hLeft_string;
	My_string* pRight_string = (My_string*)hRight_string;

	if (strlen(pLeft_string->data) < strlen(pRight_string->data))
	{
		return -1;
	}
	if (strlen(pLeft_string->data) > strlen(pRight_string->data))
	{
		return 1;
	}
	if (strlen(pLeft_string->data) == strlen(pRight_string->data))
	{
		return 0;
	}

}

/*
Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string* pString = (My_string*)hMy_string;
	if (pString->data == NULL || fp == NULL)
	{
		return FAILURE;
	}
	char c;
	int noc;
	int i = 0;
	int j;
	noc = fscanf(fp, "%c", &c);
	if (noc == 1 && c != feof(fp))
	{
		while (c != ' ' && c != feof(fp) && c != '\n')
		{
			pString->data[i] = c;
			pString->size = i + 1;
			i++;

			if(pString->size >= pString->capacity)
			{
				char* temp = (char*)malloc(sizeof(char) * (pString->capacity * 2));
				if (temp == NULL)
				{
					//free(temp);
					return FAILURE;
				}
				for (j = 0; j < pString->size; j++)
				{
					temp[j] = pString->data[j];
				}
				free(pString->data);
				pString->data = NULL;
				pString->data = temp;
				//free(temp);
				temp = NULL;
				pString->capacity *= 2;
			}
			noc = fscanf(fp, "%c", &c);
		}
		c = (char)ungetc(c, fp);
		return SUCCESS;
	}

}

*/

void my_string_destory(MY_STRING* phMy_string)
{
	My_string* pString = (My_string*)*phMy_string;

	
	free(pString->data);
	free(pString);

	*phMy_string = NULL;
}
