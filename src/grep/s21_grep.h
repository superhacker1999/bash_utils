#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#define s21_grep main

#define no_option 0
#define e_option 1
#define i_option 2
#define v_option 3
#define c_option 4
#define l_option 5
#define n_option 6
#define h_option 7
#define s_option 8
#define f_option 9
#define o_option 10
#define zero_string 0x000000000
#if defined (__APPLE__)
    #define cflag_def REG_BASIC
#elif defined (__linux__)
    #define cflag_def 0
#endif
#define cflag_i REG_ICASE

int s21_parse_option(const char* argv);
regex_t s21_get_regex(char* sample_from_argv, int option);
int s21_processing(regex_t new_regex, int option, char* file_path, int file_counter, char* sample, int* flag);
int s21_def_processing(regex_t new_regex, char* file_path, int file_counter, int* flag);
int s21_v_processing(regex_t new_regex, char* file_path, int file_counter, int* flag);
int s21_c_processing(regex_t new_regex, char* file_path, int file_counter);
int s21_l_processing(regex_t new_regex, char* file_path);
int s21_n_processing(regex_t new_regex, char* file_path, int file_counter);
int s21_h_processing(regex_t new_regex, char* file_path, int* flag);
int s21_o_processing(regex_t new_regex, char* file_path, int file_counter, char* sample);
int s21_f_processing(char* file_path, int file_counter, char* sample);
regex_t s21_get_f_regex(char* sample_buffer);
#endif  // SRC_GREP_S21_GREP_H_
