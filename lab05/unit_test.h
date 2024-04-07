#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status test_push_back(char* buffer, int length);

Status test_pop_back(char* buffer, int length);

Status test_pop_back_return_FAILURE(char* buffer, int length);

Status test_push_back_return_FAILURE(char* buffer, int length);

Status test_my_string_insertion_return_FAILURE(char* buffer, int length);

Status test_my_string_insertion_return_SUCCESS(char* buffer, int length);

Status test_my_string_extraction_return_SUCCESS(char* buffer, int length);

Status test_my_string_extraction_return_FAILURE(char* buffer, int length);

Status test_my_string_init_default(char* buffer, int length);

Status test_my_string_destroy(char* buffer, int length);

Status test_my_string_extraction(char* buffer, int length);

Status test_my_string_insertion(char* buffer, int length);

Status test_my_string_get_size(char* buffer, int length);

Status test_my_string_get_capacity(char* buffer, int length);

Status test_my_string_push_back(char* buffer, int length);

Status test_my_string_pop_back(char* buffer, int length);

Status test_my_string_at(char* buffer, int length);

Status test_my_string_c_str(char* buffer, int length);

Status test_my_string_concat(char* buffer, int length);

Status test_my_string_empty(char* buffer, int length);

Status test_my_string_print(char* buffer, int length);

Status test_my_string_init_default_NULL(char* buffer, int length);


#endif
