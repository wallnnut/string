#include "s21_string.h"
#include <string.h>

int main () {
	char arr[15] = "1234567895";
	char arr1[15] = "1234567890";

	int symb;
	symb = s21_memcmp(arr, arr1, 10);
	printf("%d", symb);
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

int s21_memcmp(const void *str1, const void *str2, size_t n) {
	const unsigned char *temp1 = str1;
	const unsigned char *temp2 = str2;
	int result = 0;

	for (size_t i = n; i != 0 || (*temp1 != *temp2); i--)
	{
		if (*temp1 > *temp2 )  {
			result = *temp1 - *temp2;
		} else if (*temp1 < *temp2) {
			result = *temp1 - *temp2;
		}
		*temp1++;
		*temp2++;
	}
	return result;
}
	