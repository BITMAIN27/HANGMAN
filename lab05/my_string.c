#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
#include <string.h>
#include <ctype.h>


struct my_string
{
	char* data;
	int capacity;
	int size;

};

typedef struct my_string My_string;


MY_STRING my_string_init_default()
{

	My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
	if(pMy_string == NULL)
	{
		printf("Failed to allocate space");
		exit(1);
	}
	pMy_string->capacity = 7;
	pMy_string->size = 0;
	char* temp = (char*)malloc(sizeof(char) * (pMy_string->capacity));
	if(temp == NULL)
	{
		printf("failed to allocate array\n");
		free(pMy_string);
	}

	pMy_string->data = temp;

	return pMy_string;

}



Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    My_string* pMy_string = (My_string*)hMy_string;

    if (pMy_string == NULL || fp == NULL)
    {
        return FAILURE;
    }
	
	//clearn object array
	int k;
	for(k = 0;k<pMy_string->capacity;k++)
	{
		pMy_string->data[k] = ' ';
	}

    char c;
    int i = 0;
    int noc = fscanf(fp, "%c", &c);

	if(noc != 1 || c == EOF || c == ' ' || c == '\n' )
	{
		return FAILURE;
	}

    while (noc == 1 && c != EOF && c != ' ' && c != '\n')
    {
        if (pMy_string->size >= pMy_string->capacity)
        {
            // Resize data array
            char* temp = malloc(sizeof(char) * pMy_string->capacity * 2);
            if (temp == NULL)
            {
                return FAILURE;
            }

            for (int j = 0; j < pMy_string->size; j++)
            {
                temp[j] = pMy_string->data[j];
            }

            free(pMy_string->data);
            pMy_string->data = temp;
            pMy_string->capacity = pMy_string->capacity * 2;
        }

        pMy_string->data[i] = c;
        i++;
        pMy_string->size = i;

        noc = fscanf(fp, "%c", &c);

        if (c == ' ')
        {
            ungetc(c, fp);
        }
    }

    return SUCCESS;
}




int my_string_get_size(MY_STRING* hMy_string)
{

	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->size;

}

int my_string_get_capacity(MY_STRING* hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->capacity;
}

void my_string_print(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;
	printf("Full string is %s\n",pString->data);

}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{	

	My_string* pMy_string = (My_string*)hMy_string;

	if(pMy_string == NULL || fp == NULL)
	{
		return FAILURE;
	}
	//fprintf(fp,"%s",pMy_string->data);
	return SUCCESS;
	
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_string* pString = (My_string*)hMy_string;
	if(pString == NULL)
	{
		printf("Failed\n");
		return FAILURE;
	}
	if(pString->size >= pString->capacity)
	{
		
		//resize
		char* temp = malloc(sizeof(char)*(pString->capacity *2));

		if(temp == NULL)
		{
			printf("Failed to allocate memory\n");
			return FAILURE;
		}
		pString->capacity = pString->capacity *2;//culd cause error
		//copy data 
		int i;
		for(i = 0; i < (pString->size);i++)
		{
			temp[i] = pString->data[i];
		}
		temp[pString->size] = item;
		free(pString->data);
		pString->data = temp;
		pString->size++;

	}
	else
	{
		pString->data[pString->size] = item;
		pString->size++;
	}
	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
	if(hMy_string == NULL)
	{
		return FAILURE;
	}
	My_string* pString= (My_string*)hMy_string;
	//make a smaller array
	char* temp = malloc(sizeof(char)* pString->size-1);
	int i;

	for(i=0;i<pString->size-1;i++)
	{
		temp[i] = pString->data[i];
	}
	free(pString->data);
	pString->data = temp;
	pString->size--;
	return SUCCESS;
	
}


char* my_string_at(MY_STRING hMy_string, int index)
{
	My_string* pString = (My_string*)hMy_string;
	if(index >= pString->size)
	{
		return NULL;
	}

	return &(pString->data[index]);

}


char* my_string_c_str(MY_STRING hMy_string)
	
	//if shit breaks, might be here
{
	My_string* pString = (My_string*)hMy_string;
	char* temp = malloc(sizeof(pString->size));
	if(temp == NULL)
	{
		return NULL;
	}

	int i;
	for(i=0;i<pString->size;i++)
	{
		temp[i] = pString->data[i];
	}
	temp[pString->size] = '\n';

	free(pString->data);
	pString->data = temp;

	return pString->data;
}


Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	My_string* pStringOne = (My_string*)hResult;
	My_string* pStringTwo = (My_string*)hAppend;

	if(pStringOne == NULL || pStringTwo == NULL)
	{
		return FAILURE;
	}
	strcat(pStringOne->data,pStringTwo->data);
	return SUCCESS;	

}

Boolean my_string_empty(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;
	if(pString !=  NULL)
	{
		if(pString->size == 0)
		{
		return TRUE;
		}
	}
	return FALSE;
}

void my_string_destroy(MY_STRING* hpMy_string)
{

	My_string* pMy_string = (My_string*)(*hpMy_string);
	free(pMy_string->data);
	free(pMy_string);
	hpMy_string = NULL;

}







