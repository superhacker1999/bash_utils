#include "s21_cat.h"

int s21_cat(int argc, char** argv) {
    if (argc < 2) return EXIT_FAILURE;
    int option = s21_parse_opt(argv);
    int i = 1;
    while (argv[i]) {
        if (argv[i][0] != '-') s21_file_output(argv[i], option);
        i++;
    }
    return EXIT_SUCCESS;
}

int s21_parse_opt(char** argv) {
    int i = 0;
    int res = 0;
    while (argv[i]) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'b':
                    res = B_OPTION;
                    break;
                case 'e':
                    res = E_OPTION;
                    break;
                case 'E':
                    res = E_OPTION;
                    break;
                case 'n':
                    res = N_OPTION;
                    break;
                case 's':
                    res = S_OPTION;
                    break;
                case 't':
                    res = T_OPTION;
                    break;
                case 'T':
                    res = T_up_OPTION;
                    break;
                case 'v':
                    res = V_OPTION;
                    break;
                case '-':
                    if ((res = s21_long_parse(argv[i])) == 0) {
                        printf("s21_cat: illegal option\nusage: s21_cat [-benstuv] [file ...]\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("s21_cat: illegal option\nusage: s21_cat [-benstuv] [file ...]\n");
                    exit(1);
            }
        }
        i++;
    }
    return res;
}

void s21_file_output(char* file_path, int parse_option) {
    switch (parse_option) {
        case 0:
            if (s21_default_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // def output
            break;
        case B_OPTION:
            if (s21_b_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // b_output
            break;
        case E_OPTION:
            if (s21_e_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // e_output
            break;
        case N_OPTION:
            if (s21_n_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // n_output
            break;
        case S_OPTION:
            if (s21_s_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // s_output
            break;
        case T_OPTION:
            if (s21_t_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // t_output
            break;
        case T_up_OPTION:
            if (s21_T_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // T_output
            break;
        case V_OPTION:
            if (s21_v_output(file_path))
                printf("%s: No such file or directory\n", file_path);  // T_output
            break;
    }
}

int s21_default_output(char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) return EXIT_FAILURE;
    char file_buffer[1000];
    memset(file_buffer, 0, 1000);
    while (!feof(file)) {
        fgets(file_buffer, 1000, file);
        if (file_buffer[0] == zero_string) break;
        printf("%s", file_buffer);
        file_buffer[0] = zero_string;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_b_output(char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000];
    int n = 1;
    while (!feof(file)) {
        fgets(file_buffer, 1000, file);
        if (file_buffer[0] == zero_string) break;
        if (*file_buffer == '\n') printf("\n");
        else
            printf("%6d\t%s", n++, file_buffer);
        file_buffer[0] = zero_string;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_e_output(char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    while (!feof(file)) {
        char a = fgetc(file);
        if (a == '\n') {
            printf("$\n");
        } else if (a == (char)EOF) {
        } else {
            v_func(&a);
            printf("%c", a);
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_n_output(char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000];
    int n = 1;
    while (!feof(file)) {
        fgets(file_buffer, 1000, file);
        if (file_buffer[0] == zero_string) break;
        printf("%6d\t%s", n++, file_buffer);
        file_buffer[0] = zero_string;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_s_output(char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000];
    while (!feof(file)) {
        fgets(file_buffer, 1000, file);
        if (file_buffer[0] == zero_string) break;
        if (file_buffer[0] == '\n') {
            printf("%s", file_buffer);
            while (file_buffer[0] == '\n') {
                fgets(file_buffer, 1000, file);
            }
        }
        printf("%s", file_buffer);
        file_buffer[0] = zero_string;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_t_output(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    while (!feof(file)) {
        char a = fgetc(file);
        if (a == '\t') {
            printf("^I");
        } else if (a == (char)EOF) {
        } else {
            v_func(&a);
            printf("%c", a);
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_T_output(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    while (!feof(file)) {
        char a = fgetc(file);
        if (a == '\t') printf("^I");
        else if (a == (char)EOF);
        else
            printf("%c", a);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_long_parse(char* long_option) {
    int option = 0;
    if (!strcmp(long_option, "--number-nonblank")) option = B_OPTION;
    else if (!strcmp(long_option, "--number")) option = N_OPTION;
    else if (!strcmp(long_option, "--squeeze-blank")) option = S_OPTION;
    return option;
}

void v_func_ch(int *ch, char *c) {
    if (*c < 0) {
        *c &= 127;
        *ch = (int)*c;
        *ch += 128;
    }
}

void v_func(char *c) {
        int ch = (int)*c;
        v_func_ch(&ch, c);
        if (ch != 9 && ch != 10 && ch < 32) {
            printf("^");
            *c += 64;
        } else if (ch == 127) {
            printf("^");
            *c = '?';
        } else if (ch > 127 && ch < 160) {
            printf("M-^");
            *c = ch - 64;
        } else if (ch > 160 && ch <= 255) {
            *c -= 128;
        }
}

int s21_v_output(char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    while (!feof(file)) {
        char a = fgetc(file);
        if (a != (char)EOF) {
            v_func(&a);
            printf("%c", a);
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}
