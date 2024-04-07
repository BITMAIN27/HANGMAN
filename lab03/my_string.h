#include <stdio.h>

typedef enum { FAILURE, SUCCESS } Status;

typedef void* MY_STRING;

//Precondition: c_string is a valid null terminated c-string.
//Postcondition: Allocate space for a string object thata represents a string with the same value as the given c-string.
//The capacity of the string object will be set to be one greater than is required to hold the string.
//As an example, the string "the" would set capacity at 4 instead of 3.
//A copy of the address of the opaque object will be returned on success and NULL on failure.
MY_STRING my_string_init_c_string(const char* c_string);

//Precondition: None
//Postcondition: Allocate space for a string object that represents the empty string.
//The string will have capacity 7 and size 0 by default.
//A copy of the address of the opaque object will be returned on success and NULL on failure.
MY_STRING my_string_init_default(void);

//Precondition: phMy_string holds the address of a valid handle to a MY_STRING object.
//Postcondition: The memory used for the MY_STRING object has been reclaimed by the system.
//The handle referred to by the pointer phMy_string has been set to NULL.
void my_string_destroy(MY_STRING* phMy_string);

//Precondition: hMy_string is the handle of a valid My_string object.
//Postcondition: Returns a copy of the integer value of the object's capacity.
int my_string_get_capacity(MY_STRING hMy_string);

//Precondition: hMy_string is the handle of a valid My_string object.
//Postcondition: Returns a copy of the integer value of the object's size.
int my_string_get_size(MY_STRING hMy_string);

//Precondition: hLeft_string and hRight_string are valid My_string objects.
//Postcodition: Returns an integer less than zero if the string represented by hLeft_string is lexicographically smaller than the string represented by hRight_string, returns 0 if they are the same and returns an integer greater than zero if left is greater than right.
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

