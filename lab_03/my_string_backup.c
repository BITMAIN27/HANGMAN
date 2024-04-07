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

    if (pMy_string == NULL)
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

void print_string(My_string* hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	printf("String in the object is: %s\n",pMy_string->data);
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{	

	My_string* pMy_string = (My_string*)hMy_string;

	if(pMy_string == NULL)
	{
		return FAILURE;
	}
	fprintf(fp,"%s",pMy_string->data);
	return SUCCESS;
	
}


void my_string_destroy(MY_STRING* hpMy_string)
{

	My_string* pMy_string = (My_string*)(*hpMy_string);
	free(pMy_string->data);
	free(pMy_string);
	hpMy_string = NULL;

}







