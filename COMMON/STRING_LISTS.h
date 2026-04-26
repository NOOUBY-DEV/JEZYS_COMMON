#ifndef STRING_LISTS
#define STRING_LISTS

#include <stdlib.h>



int STRING_LIST_SETUP(char*** STRING_LIST, const unsigned long long LIST_SIZE, const unsigned long long STRING_SIZE);

void FREE_STRING_LIST(char*** STRING_LIST);

void STRING_LIST_APPEND(char*** STRING_LIST, const char* APPEND_STRING);

unsigned long long STRING_LIST_SIZE(char*** STRING_LIST);





#endif
