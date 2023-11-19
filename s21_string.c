#include "s21_string.h"
#include <string.h>

int main () {
	char arr[15] = "1234567890";
	char *symb;
	symb = s21_memchr(arr, '4', 10);
	printf("%s", symb);
}

void *s21_memchr(const void *str, int c, size_t n) {
	const unsigned char *ch = str;
	for (size_t i = n; i != 0; i--)
	{
		if ((unsigned char)c == *ch) {
			return (void *) ch;
		}
		*ch++;
	}
	return NULL;
	
	}
	