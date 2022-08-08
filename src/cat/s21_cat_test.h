#ifndef SRC_CAT_S21_CAT_TEST_H_
#define SRC_CAT_S21_CAT_TEST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define RESET "\e[0m"
void test_no_option();
void test_v();
void test_b();
void test_e();
void test_E();
void test_n();
void test_s();
void test_t();
void test_number_non_blank();
void test_number();
void test_squeeze_blank();
#endif  // SRC_CAT_S21_CAT_TEST_H_
