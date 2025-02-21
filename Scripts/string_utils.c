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
int print_char(char c) {
    write(1, &c, 1);
    return 1;
} 
int print_num(int num) {
    char buf[20];
    int i = 0;
    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }
    while (num > 0) {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }
    while (i > 0) {
        write(1, &buf[--i], 1);
    }
    return i;
}
int print_float(double num) {
    char buf[40];
    int i = 0;
    if (num == 0.0) {
        write(1, "0.0", 3);
        return 3;
    }
    int int_part = (int)num;
    num -= int_part;
    i += write_num(int_part);
    write(1, ".", 1);
    for (int j = 0; j < 6; j++) {
        num *= 10;
        int frac_part = (int)num;
        write(1, &"0123456789"[frac_part], 1);
        num -= frac_part;
    }
    return i + 1 + 6;
}
int print_hex(int num) {
    char hex_chars[] = "0123456789abcdef";
    char buf[20];
    int i = 0;
    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }
    while (num > 0) {
        buf[i++] = hex_chars[num % 16];
        num /= 16;
    }
    while (i > 0) {
        write(1, &buf[--i], 1);
    }
    return i;
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
        else if (*p == '%' && *(p + 1) == 'c') {
            char c = va_arg(args, char);
            temp += print_char(c);
            p += 2;

        }
        else if (*p == '%' && *(p + 1) == 'd') {
            int num = va_arg(args, int);
            temp += print_num(num);
            p += 2;
        }
        else if (*p == '%' && *(p + 1) == 'f') {
            double num = va_arg(args, double);
            written += print_float(num);
            p += 2;
        }
            else if (*p == '%' && *(p + 1) == 'x') {
            int num = va_arg(args, int);
            written += print_hex(num);
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



