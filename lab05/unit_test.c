#include <stdio.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{


 Status (*tests[])(char*, int) =
 {
 test_init_default_returns_nonNULL,
 test_get_size_on_init_default_returns_0,
 test_get_capacity_on_init_default_returns_7,
 test_push_back,
 test_pop_back,
 test_pop_back_return_FAILURE,
 test_push_back_return_FAILURE,
 test_my_string_insertion_return_FAILURE,
 test_my_string_insertion_return_SUCCESS,
 test_my_string_extraction_return_FAILURE,
 test_my_string_extraction_return_SUCCESS,
 test_my_string_init_default,
test_my_string_destroy,
test_my_string_compare_return_negetive,
test_my_string_compare_return_positive,
test_my_string_compare_return_zero,
test_my_string_concat_RETURN_SUCCESS,
test_my_string_concat_RETURN_FAILURE,
test_my_string_empty_TRUE,
test_my_string_empty_FALSE,
test_my_string_at_return_value,
test_my_string_at_return_NULL,
test_my_string_c_str_Terminating_SUCCESS,
test_my_string_c_str_Terminating_FAILURE,
test_my_string_get_size_return_Garbage
 };


 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;

 for(i=0; i<number_of_functions; i++)
 {
 if(tests[i](buffer, 500) == FAILURE)
 {
 printf("FAILED: Test %d failed miserably\n", i);
 printf("\t%s\n", buffer);
 failure_count++;
 }
 else
 {
// printf("PASS: Test %d passed\n", i);
// printf("\t%s\n", buffer);
 success_count++;
 }
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}
