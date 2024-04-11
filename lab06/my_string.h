#ifndef MY_STRING_H
#define MY_STRINH_H

#include "status.h"
#include <stdio.h>
typedef void* MY_STRING;

MY_STRING my_string_init_default();


MY_STRING init_c_string(char* string);


void my_string_destroy(MY_STRING* hMy_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);//done

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);//done

int my_string_get_size(MY_STRING* hMy_string); //done

int my_string_get_capacity(MY_STRING* hMy_string);//done

Status my_string_push_back(MY_STRING hMy_string, char item); //done

Status my_string_pop_back(MY_STRING hMy_string);//done

char* my_string_at(MY_STRING hMy_string, int index);

char* my_string_c_str(MY_STRING hMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

Boolean my_string_empty(MY_STRING hMy_string);


void my_string_print(MY_STRING hMy_string);


Status my_string_assignment(MY_STRING hLeft, MY_STRING hRight);

MY_STRING my_string_init_copy(MY_STRING hMy_string);

void my_string_swap(MY_STRING hLeft, MY_STRING hRight);

#endif
