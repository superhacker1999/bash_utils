#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_cat main

#define B_OPTION 1
#define E_OPTION 2
#define N_OPTION 3
#define S_OPTION 4
#define T_OPTION 5
#define T_up_OPTION 6
#define V_OPTION 7
#define zero_string 0x00000000

int s21_parse_opt(char** argv);
void s21_file_output(char* filepath, int parse_option);
int s21_default_output(char* file_path);
int s21_b_output(char* file_path);
int s21_e_output(char* file_path);
int s21_n_output(char* file_path);
int s21_s_output(char* file_path);
int s21_t_output(char *file_path);
int s21_T_output(char *file_path);
int s21_v_output(char* file_path);
int s21_long_parse(char* long_option);
void v_func_ch(int *ch, char *c);
void v_func(char *c);
#endif  // SRC_CAT_S21_CAT_H_
