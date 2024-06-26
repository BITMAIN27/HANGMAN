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

Status test_my_string_compare_return_negetive(char* buffer, int length);

Status test_my_string_compare_return_positive(char* buffer, int length);

Status test_my_string_compare_return_zero(char* buffer, int length);

Status test_my_string_concat_RETURN_SUCCESS(char* buffer, int length);

Status test_my_string_concat_RETURN_FAILURE(char* buffer, int length);

Status test_my_string_empty_TRUE(char* buffer, int length);

Status test_my_string_empty_FALSE(char* buffer, int length);

Status test_my_string_at_return_value(char* buffer, int length);

Status test_my_string_at_return_NULL(char* buffer, int length);

Status test_my_string_c_str_Terminating_SUCCESS(char* buffer, int length);

Status test_my_string_c_str_Terminating_FAILURE(char* buffer, int length);

Status test_my_string_get_size_return_Garbage(char* buffer, int length);


#endif
