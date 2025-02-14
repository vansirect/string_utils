#ifndef STRING_UTILS
#define STRING_UTILS

#include <unistd.h>
#include <stdarg.h>
int print_str(char *str)

int my_printf(const char* format,...)

char* chardup(const char c);
unsigned int strlen(const char* c);
int puts(const char* str);

#endif 
