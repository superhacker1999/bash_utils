#include "s21_cat_test.h"
int main(void) {
    test_no_option();
    test_v();
    test_b();
    test_e();
    test_E();
    test_n();
    test_s();
    test_t();
    test_number_non_blank();
    test_number();
    test_squeeze_blank();
    return 0;
}

void test_no_option() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " tmp1 > v1");
    strcat(command2, " tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_v() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -v tmp1 > v1");
    strcat(command2, " -v tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_b() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -b tmp1 tmp2 > v1");
    strcat(command2, " -b tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_e() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -e tmp1 > v1");
    strcat(command2, " -e tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_E() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -e tmp1 tmp2 tmp3 > v1");
    strcat(command2, " -E tmp1 tmp2 tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_n() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -n tmp1 tmp2 > v1");
    strcat(command2, " -n tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_s() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -s tmp2 > v1");
    strcat(command2, " -s tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_t() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -t tmp1 > v1");
    strcat(command2, " -t tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_number_non_blank() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -b tmp3 > v1");
    strcat(command2, " --number-nonblank tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_number() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -n tmp1 > v1");
    strcat(command2, " --number tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_squeeze_blank() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "cat");
    strcat(command2, "./s21_cat");
    strcat(command1, " -s tmp1 > v1");
    strcat(command2, " --squeeze-blank tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
