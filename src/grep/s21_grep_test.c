#include "s21_grep_test.h"
int main(void) {
    test_no_option1();
    test_no_option2();
    test_no_option3();
    test_e1();
    test_e2();
    test_e3();
    test_i1();
    test_i2();
    test_i3();
    test_v1();
    test_v3();
    test_c1();
    test_c2();
    test_l();
    test_n();
    test_h();
    test_s();
    test_f();
    test_o();
    return 0;
}

void test_no_option1() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " coronavirus tmp3 > v1");
    strcat(command2, " coronavirus tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_no_option2() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " cor tmp3 tmp2 tmp2 > v1");
    strcat(command2, " cor tmp3 tmp2 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_no_option3() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " co tmp1 tmp2 > v1");
    strcat(command2, " co tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_e1() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -e coronavirus tmp1 tmp2 > v1");
    strcat(command2, " -e coronavirus tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_e2() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -e cor tmp1 tmp2 > v1");
    strcat(command2, " -e cor tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_e3() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -e this tmp3 tmp2 > v1");
    strcat(command2, " -e this tmp3 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_i1() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i coronavirus tmp1 tmp2 > v1");
    strcat(command2, " -i coronavirus tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_i2() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i Oc tmp1 tmp2 > v1");
    strcat(command2, " -i Oc tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_i3() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i Oc tmp1 tmp3 tmp2 > v1");
    strcat(command2, " -i Oc tmp1 tmp3 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_v1() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -v health tmp1 tmp2 > v1");
    strcat(command2, " -v health tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_v3() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -v Thevet tmp3 tmp2 > v1");
    strcat(command2, " -v Thevet tmp3 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_c1() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -c health tmp1 tmp2 tmp3 > v1");
    strcat(command2, " -c health tmp1 tmp2 tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_c2() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -c is tmp3 > v1");
    strcat(command2, " -c is tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_l() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -l a tmp1 > v1");
    strcat(command2, " -l a tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_n() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -n coronavirus tmp1 tmp3 tmp2 > v1");
    strcat(command2, " -n coronavirus tmp1 tmp3 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_h() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -h cor tmp1 tmp2 > v1");
    strcat(command2, " -h cor tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_s() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -s coronavirus tmp5  tmp3> v1");
    strcat(command2, " -s coronavirus tmp5 tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_f() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -f all tmp1 > v1");
    strcat(command2, " -f all tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void test_o() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -o health tmp1 > v1");
    strcat(command2, " -o health tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
