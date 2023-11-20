#include "s21_string.h"
#include <string.h>
#include <check.h>


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

void *s21_memcpy(void *dest, const void *src, size_t n) {
	char *temp1 = dest;
	const char *temp2 = src;
	for (size_t i = n; i != 0; i--)
	{
			*temp1 = *temp2;
			*temp1++;
			*temp2++;
	}
}

void *s21_memset(void *str, int c, size_t n) {
	char *temp = str;
	for (size_t i = 0; i < n; i++)
	{
		*temp++ = c;
	}
}

char *s21_strncat(char *dest, const char *src, size_t n) {
char *temp = dest;
	while(*dest){
		*dest++;
	}
	for (size_t i = 0; i < n && src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	return temp;
}

char *s21_strchr(const char *str, int c) {
	const unsigned char* temp = str;
	while(*temp) {
		if ((char)c == *temp) {
			return (char*)temp;
		}
		temp++;
	}
	return NULL;
}


