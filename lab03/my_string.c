#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "my_string.h"

typedef struct string
{
	int capacity;
	int size;
	char* data;
}
My_string;

MY_STRING my_string_init_default(void)
{
	My_string* pMy_string = (My_string*)malloc(sizeof(My_string));

	pMy_string->size = 0;
	pMy_string->capacity = 10;
	pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);

	if (pMy_string->data == NULL)
	{
		printf("data: malloc failed.\n");
		free(pMy_string);
		return NULL;
	}

	return pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
	My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
	if (pMy_string != NULL)
	{
		
		pMy_string->size = 0;
		while (c_string[pMy_string->size] != '\0')
		{
			pMy_string->size++;
		}
		pMy_string->capacity = pMy_string->size + 1;
	
		pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
		if (pMy_string->data == NULL)
		{
			printf("data: malloc failed.\n");
			free(pMy_string);
			return NULL;
		}
	
		int i;
		for (i = 0; i < pMy_string->size; i++)
		{
			pMy_string->data[i] = c_string[i];
		}
	}
	return pMy_string;
}

void my_string_destroy(MY_STRING* phMy_string)
{
	My_string* pMy_string = (My_string*)*phMy_string;

	free(pMy_string->data);

	free(pMy_string); pMy_string = NULL;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;
	return pString->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;
	return pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	My_string* pLeft_string = (My_string*)hLeft_string;
	My_string* pRight_string = (My_string*)hRight_string;

	return strcmp(pLeft_string->data, pRight_string->data);
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string* pString = (My_string*)hMy_string;
	int c;
	char first_character;
	int noc;
	char* temp;
	int i;
	
	pString->size = 0;

	noc = fscanf(fp, " %c", &first_character);
	
	if (noc != 1) return FAILURE;

	pString->data[pString->size] = first_character;
	pString->size++;

	c = fgetc(fp);
	
	while (c != EOF && !isspace(c))
	{
		if (pString->size >= pString->capacity)
		{
			temp = (char*)malloc(sizeof(char) * pString->capacity * 2);
			
			if (temp == NULL) return FAILURE;

			for (i = 0; i < pString->size; i++) temp[i] = pString->data[i];

			free(pString->data);
			pString->data = temp;
			pString->capacity *= 2;
		}
		pString->data[pString->size] = c;
		pString->size++;
		c = fgetc(fp);
	}
	if (c != EOF) ungetc(c, fp);

	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_string* pString = (My_string*)hMy_string;
	int i;

	for (i = 0; i < pString->size; i++) if (fputc(pString->data[i], fp) == EOF) return FAILURE;

	return SUCCESS;
}

