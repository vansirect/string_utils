#include <unistd.h>
#include<x86args.h>
char* chardup(const char c) {
	// chardup is converting  a character to a string 
	static char buf[2;
	buf[0] = c;
	buf[1] = '\0'
	return buf
}
unsigned int strlen(const char* c) {
	unsigned int  n;
	char* p =c; // we will be using p to loop through c  and n as a counter
	while (*p) {
		n++;
		p++;
	}
	return n;
}
int puts(const char* str) {
	unsigned int n = strlen(str);
	// checking if it is exactly n bytes
	if (write(1, str, n) != n) {

		return -1; 
	}

	// basically appending a new line to the str
	if (write(1, "\n", 1) != 1) {
		return -1;
	}
}

