#include "../s21_string.h"
#include <stdlib.h>
#include <check.h>
#include <string.h>

START_TEST(string_with_numbers) {
	// Arrange
	char* str = (char*)malloc(15 * sizeof(char));
	str = "1234567890";
	char* s21_result = (char*)malloc(15 * sizeof(char));
	char* string_result = (char*)malloc(15 * sizeof(char));
	// Act
	s21_result = s21_memchr(str, '4', 10);
	string_result = memchr(str, '4', 10);
	// Assert 
	ck_assert_ptr_eq(s21_result, string_result);
	ck_assert_str_eq(s21_result, string_result);
	// free(s21_result);
	// free(string_result);
	// free(str);
} END_TEST

START_TEST(random_string) {
	// Arrange
	char* str = (char*)malloc(100 * sizeof(char));
	str = "But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain! 32.";
	char* s21_result = (char*)malloc(100 * sizeof(char));
	char* string_result = (char*)malloc(100 * sizeof(char));
	// Act
	s21_result = s21_memchr(str, '!', 100);
	string_result = memchr(str, '!', 100);
	// Assert 
	ck_assert_ptr_eq(s21_result, string_result);
	ck_assert_str_eq(s21_result, string_result);
	// free(s21_result);
	// free(string_result);
	// free(str);
} END_TEST

START_TEST(empty_string) {
	// Arrange
	char* str = (char*)malloc(5 * sizeof(char));
	str = "";
	char* s21_result = (char*)malloc(5 * sizeof(char));
	char* string_result = (char*)malloc(5 * sizeof(char));
	// Act
	s21_result = s21_memchr(str, '\0', 5);
	string_result = memchr(str, '\0', 5);
	// Assert 
	ck_assert_ptr_eq(s21_result, string_result);
	ck_assert_str_eq(s21_result, string_result);
	// free(s21_result);
	// free(string_result);
	// free(str);
} END_TEST

START_TEST(non_printable_characters) {
	// Arrange
	char* str = (char*)malloc(10 * sizeof(char));
	str = "\n\t\r\e\f";
	char* s21_result = (char*)malloc(10 * sizeof(char));
	char* string_result = (char*)malloc(10 * sizeof(char));
	// Act
	s21_result = s21_memchr(str, '\r', 5);
	string_result = memchr(str, '\r', 5);
	// Assert 
	ck_assert_ptr_eq(s21_result, string_result);
	ck_assert_str_eq(s21_result, string_result);
	// free(s21_result);
	// free(string_result);
	// free(str);
} END_TEST

START_TEST(overlap) {
	// Arrange
	char* str = (char*)malloc(15 * sizeof(char));
	str = "1234567891011";
	char* s21_result = (char*)malloc(15 * sizeof(char));
	s21_result = str + 2;
	char* string_result = (char*)malloc(15 * sizeof(char));
	string_result = str + 2;
	// Act
	s21_result = s21_memchr(str, '9',15);
	string_result = memchr(str, '9', 15);
	// Assert 
	ck_assert_ptr_eq(s21_result, string_result);
	ck_assert_str_eq(s21_result, string_result);
	// free(s21_result);
	// free(string_result);
	// free(str);
} END_TEST

Suite *memchr_suite(void) {
	Suite *s;
	TCase *with_numbers, *random, *empty, *non_printable, *overlapping;
	s = suite_create("Root");

	with_numbers = tcase_create("with_numbers");
	tcase_add_test(with_numbers, string_with_numbers);
	suite_add_tcase(s, with_numbers);

	random = tcase_create("random");
	tcase_add_test(random, random_string);
	suite_add_tcase(s, random);

	empty = tcase_create("empty");
	tcase_add_test(empty, empty_string);
	suite_add_tcase(s, empty);

	non_printable = tcase_create("non_printable");
	tcase_add_test(non_printable, non_printable_characters);
	suite_add_tcase(s, non_printable);

	overlapping = tcase_create("overlapping");
	tcase_add_test(overlapping, overlap);
	suite_add_tcase(s, overlapping);

	return s;

}

int main () {
	int no_failed = 0;
	Suite *s;
	SRunner *runner;

	s = memchr_suite();
	runner = srunner_create(s);

	srunner_run_all(runner, CK_VERBOSE);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return no_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

