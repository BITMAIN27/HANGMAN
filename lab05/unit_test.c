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
test_my_string_extraction,
test_my_string_insertion,
test_my_string_get_size,
test_my_string_get_capacity,
test_my_string_push_back,
test_my_string_pop_back,
test_my_string_at,
test_my_string_c_str,
test_my_string_concat,
test_my_string_empty,
test_my_string_print,
test_my_string_init_default_NULL
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
