#ifndef MY_STRING_H
#define MY_STRINH_H

#include "status.h"

typedef void* MY_STRING;

MY_STRING my_string_init_default();

void my_string_destroy(MY_STRING* hMy_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

int my_string_get_size(MY_STRING* hMy_string);

#endif
