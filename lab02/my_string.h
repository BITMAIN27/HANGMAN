#pragma once

typedef void* MY_STRING;

MY_STRING my_string_init_default(void);

int my_string_get_capacity(MY_STRING hMy_string);

int my_string_get_size(MY_STRING hMy_string);

MY_STRING my_string_init_c_string(const char* c_string);

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

void my_string_destory(MY_STRING* phMy_string);
