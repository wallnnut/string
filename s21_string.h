#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__gnu_linux__)
    #define PLATFORM_NAME "linux" // Linux
#elif defined(__APPLE__)
	#define PLATFORM_NAME "apple" // Apple
#endif

#define SPECIAL_SYMBOL '%'
#define base_size_of_string 255

typedef struct Specifiers_t{
    bool CHARACTER;
    bool SIGNED_DECIMAL_INTEGER;
    bool SCIENTIFIC_NOTATION;
    bool DECIMAL_FLOATING_POINT;
    bool SHOR_DECIMAL_FLOATING_POINT;
    bool UNSIGNED_OCTAL;
    bool STRING_OF_CHARACTERS;
    bool UNSIGNED_DECIMAL_INTEGER;
    bool UNSIGNED_HEXADEMICAL_INTEGER;
    bool UNSIGNED_HEXADEMICAL_INTEGER_UPPERCASE;
    bool POINTER_ADDRESS;
    bool NUMBER_OF_CHARACTERS;
    } Specifiers_t;



void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void* restrict dest, const void* restrict src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char* restrict str, const char *restrict format, ...);
