#include "s21_string.h"
#include "helpers.h"
#include <check.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

void get_specifiers(Specifiers_t *specifiers, const char* restrict format, va_list args);
void handle_character(Specifiers_t *specifiers, const char* restrict format);
typedef unsigned char byte;

int main() {
	char arr[100];
	float x = 0.015;
	// s21_sprintf(arr,"sd: %s%d%f", "qwerty", 10, 233.007);
	sprintf(arr,"sd: %s\n%d\t%f\t%u", "qwerty", 10, 233.007, 10);

	printf("%s", arr);

	// byte b = 5;  // Или любое другое
	// for (int i = 0; i < 8; i++) {
	// 	printf("%c", (b & 0x80) ? '1' : '0');
	// 	b <<= 1;
	// }


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

void *s21_memcpy(void* restrict dest, const void* restrict src, size_t n) {
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

int s21_sprintf(char* restrict str, const char *restrict format, ...) {
	va_list argptr;
	va_start(argptr, format);
	Specifiers_t specifiers;
	s21_memset(&specifiers, false, sizeof(specifiers));
	get_specifiers(&specifiers, format, argptr);

	va_end(argptr);
}

void get_specifiers(Specifiers_t *specifiers, const char* restrict format, va_list argptr) {
	size_t i = 0;
	char prev = 0;
	char *result_string = calloc(base_size_of_string, sizeof(char));
	while(*format != '\0') {
		if(*format == SPECIAL_SYMBOL) {
			prev = *format;
			*format++;
			continue;
		}
		else if (prev == SPECIAL_SYMBOL && *format == 'c') {
			result_string[i] = va_arg(argptr, int);
			i++;
		} else if (prev == SPECIAL_SYMBOL && *format == 's') {
			strcat(result_string, va_arg(argptr, char*));
		} 
		else if (prev == SPECIAL_SYMBOL && *format == 'd') {
			int num = va_arg(argptr, int);
			char temp[32] = {0};
			int_to_str(num, temp, 0);
			strcat(result_string, temp);
		} 
		else if (prev == SPECIAL_SYMBOL && *format == 'f') {
			double num = va_arg(argptr, double);
			char temp[15] = {0};
			ftoa(num, temp, 6);
			strcat(result_string, temp);
		}
		else {
			// printf("%ld", strlen(result_string));
			i = (strlen(result_string));
			result_string[i] = *format;
		}
		prev = *format;
		*format++;
	}
	printf("%s", result_string);
	free(result_string);
}


