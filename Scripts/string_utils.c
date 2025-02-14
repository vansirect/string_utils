#include "string_utils.h"

char* chardup(const char c) {
    static char buf[2];
    buf[0] = c;
    buf[1] = '\0';
    return buf;
}

unsigned int strlen(const char* c) {
    unsigned int n = 0;
    const char* p = c;
    while (*p) {
        n++;
        p++;
    }
    return n;
}

int puts(const char* str) {
    unsigned int n = strlen(str);
    if (write(1, str, n) != n) {
        return -1;
    }
    if (write(1, "\n", 1) != 1) {
        return -1;
    }
    return n + 1;
}
int print_str(char* str) {
    int count = 0;
    while (*str) {
        write(1, str++, 1);
    }
}

int my_printf(const char* format, ...) {
    const char * p;
    int temp = 0;
    va_list args;
    va_start(args, format);
    while (*p != '\0') {
        if (*p == '%' && *(p + 1) == 's') {
            char* str = va_arg(args, char*);
            temp += print_str(str);
            p += 2;
        }
        else {
            write(1, p, 1);
            temp++;
            p++;
        }
    }
    va_end(args); 
    return temp;
}


