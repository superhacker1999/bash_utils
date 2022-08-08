#include "s21_grep.h"

/*
-e  явное указание на шаблон, если их несколько
-i  игнорирует различия регистра
-v  инвертирует смысл поиска соответствий, выводит только те строки, в которых не встречается подстрока
-c  выводит только количество совпадающих строк
-l  выводит только совпадающиие файлы
-n  предваряет каждую строку вывода номером строки из файла ввода
-h  выводит совпадающие строки, не предваряя их именами файлов
-s  Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах
-f  Получает регулярные выражения из файла
-o  Печатает только совпадающие (непустые) части совпавшей строки
*/

int s21_grep(int argc, char** argv) {
    if (argc < 3) return EXIT_FAILURE;
    int option = no_option;
    regex_t new_regex;
    int file_iterator;
    int file_counter;
    if (argv[1][0] == '-') {  // files start from [3]
        option = s21_parse_option(argv[1]);  // getting option
        if (option != f_option) new_regex = s21_get_regex(argv[2], option);  // getting regex
        file_iterator = 3;
        file_counter = argc - 3;
    } else {  // files start from [2]
        new_regex = s21_get_regex(argv[1], option);
        file_iterator = 2;
        file_counter = argc - 2;
    }
    int flag = file_counter;
    while (argv[file_iterator]) {  // processing
        s21_processing(new_regex, option, argv[file_iterator], file_counter, argv[2], &flag);
        file_iterator++;
    }
    regfree(&new_regex);
    return EXIT_SUCCESS;
}

int s21_parse_option(const char* argv) {
    int res = no_option;
    if (argv[1] == 'e') res = e_option;
    else if (argv[1] == 'i') res = i_option;
    else if (argv[1] == 'v') res = v_option;
    else if (argv[1] == 'c') res = c_option;
    else if (argv[1] == 'l') res = l_option;
    else if (argv[1] == 'n') res = n_option;
    else if (argv[1] == 'h') res = h_option;
    else if (argv[1] == 's') res = s_option;
    else if (argv[1] == 'f') res = f_option;
    else if (argv[1] == 'o') res = o_option;
    return res;
}

regex_t s21_get_regex(char* sample_from_argv, int option) {
    regex_t new_regex;
    int comp_flag = cflag_def;
    if (option == i_option) comp_flag = cflag_i;
    regcomp(&new_regex, sample_from_argv, comp_flag);
    return new_regex;
}

int s21_processing(regex_t new_regex, int option, char* file_path,
int file_counter, char* sample, int* flag) {
    if (option == no_option) {
        if (s21_def_processing(new_regex, file_path, file_counter, flag))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == s_option) {
        s21_def_processing(new_regex, file_path, file_counter, flag);
    } else if (option == e_option) {
        if (s21_def_processing(new_regex, file_path, file_counter, flag))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == i_option) {
        if (s21_def_processing(new_regex, file_path, file_counter, flag))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == v_option) {
        if (s21_v_processing(new_regex, file_path, file_counter, flag))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == c_option) {
        if (s21_c_processing(new_regex, file_path, file_counter))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == l_option) {
        if (s21_l_processing(new_regex, file_path))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == n_option) {
        if (s21_n_processing(new_regex, file_path, file_counter))
        printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == h_option) {
        if (s21_h_processing(new_regex, file_path, flag))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == f_option) {
        if (s21_f_processing(file_path, file_counter, sample))
            printf("s21_grep: %s: No such file or directory", file_path);
    } else if (option == o_option) {
        if (s21_o_processing(new_regex, file_path, file_counter, sample))
            printf("s21_grep: %s: No such file or directory", file_path);
    }
    return EXIT_SUCCESS;
}

int s21_def_processing(regex_t new_regex, char* file_path, int file_counter, int* flag) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};
    int value = 1;
    while (!feof(file)) {
        fgets(file_buffer, 1000, file);
        if (file_buffer[0] == zero_string) break;
        value = regexec(&new_regex, file_buffer, 0, NULL, 0);
        if (value == 0 && file_counter == 1) printf("%s", file_buffer);
        else if (value == 0 && file_counter > 1) printf("%s:%s", file_path, file_buffer);
        file_buffer[0] = zero_string;
    }
    fclose(file);
    *flag -= 1;
    if (value == 0 && file_buffer[0] == zero_string) printf("\n");
    return EXIT_SUCCESS;
}

int s21_v_processing(regex_t new_regex, char* file_path, int file_counter, int* flag) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};
    while (!feof(file)) {
        int value;
        fgets(file_buffer, 1000, file);
        if (file_buffer[0] == zero_string) break;
        value = regexec(&new_regex, file_buffer, 0, NULL, 0);
        if (value == REG_NOMATCH && file_counter == 1) printf("%s", file_buffer);
        else if (value == REG_NOMATCH && file_counter > 1) printf("%s:%s", file_path, file_buffer);
        file_buffer[0] = zero_string;
    }
    *flag -= 1;
    if (*flag != 0) printf("\n");
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_c_processing(regex_t new_regex, char* file_path, int file_counter) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};
    int string_counter = 0;
    while (!feof(file)) {
        int value;
        fgets(file_buffer, 1000, file);
        value = regexec(&new_regex, file_buffer, 0, NULL, 0);
        if (value == 0) string_counter++;
    }
    fclose(file);
    if (file_counter == 1) printf("%d", string_counter);
    else if (file_counter > 1) printf("%s:%d", file_path, string_counter);
    printf("\n");
    return EXIT_SUCCESS;
}

int s21_l_processing(regex_t new_regex, char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};
    int file_flag = 0;
    while (!feof(file)) {
        int value;
        fgets(file_buffer, 1000, file);
        value = regexec(&new_regex, file_buffer, 0, NULL, 0);
        if (value == 0) file_flag = 1;
    }
    fclose(file);
    if (file_flag) printf("%s", file_path);
    printf("\n");
    return EXIT_SUCCESS;
}

int s21_n_processing(regex_t new_regex, char* file_path, int file_counter) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};
    int string_counter = 1;
    while (!feof(file)) {
        int value;
        fgets(file_buffer, 1000, file);
        value = regexec(&new_regex, file_buffer, 0, NULL, 0);
        if (value == 0 && file_counter == 1) printf("%d:%s", string_counter++, file_buffer);
        else if (value == 0 && file_counter > 1) printf("%s:%d:%s", file_path, string_counter++, file_buffer);
        else
            string_counter++;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_h_processing(regex_t new_regex, char* file_path, int* flag) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};
    int value = 1;
    while (!feof(file)) {
        fgets(file_buffer, 1000, file);
        value = regexec(&new_regex, file_buffer, 0, NULL, 0);
        if (value == 0 ) printf("%s", file_buffer);
    }
    fclose(file);
    *flag -= 1;
    if (*flag != 0 && value == 0) printf("\n");
    // if (file_buffer[strlen(file_buffer)] != '\n') printf("\n");
    return EXIT_SUCCESS;
}

int s21_o_processing(regex_t new_regex, char* file_path, int file_counter, char* sample) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};
    while (!feof(file)) {
        int value;
        fgets(file_buffer, 1000, file);
        value = regexec(&new_regex, file_buffer, 0, NULL, 0);
        if (value == 0 && file_counter == 1) printf("%s\n", sample);
        else if (value == 0 && file_counter > 1) printf("%s:%s\n", file_path, sample);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int s21_f_processing(char* file_path, int file_counter, char* sample) {
    FILE *file = fopen(file_path, "r");
    if (!file) return EXIT_FAILURE;
    char file_buffer[1000] = {'0'};

    FILE *sample_file = fopen(sample, "r");
    char sample_buffer[1000] = {'0'};
    regex_t regex_array[100];
    int i = 0;
    while (!feof(sample_file)) {
        fgets(sample_buffer, 1000, sample_file);
        if (*sample_buffer != EOF && sample_buffer[0] != '\n') {
            regex_array[i] = s21_get_f_regex(sample_buffer);
        }
        i++;
    }
    fclose(sample_file);

    int regex_counter = i;

    while (!feof(file)) {
        fgets(file_buffer, 1000, file);
        if (*file_buffer != EOF) {
            int j = 0;
            while (j <= regex_counter) {
            int value;
            value = regexec(&regex_array[j], file_buffer, 0, NULL, 0);
            if (value == 0 && file_counter == 1) printf("%s", file_buffer);
            else if (value == 0 && file_counter > 1) printf("%s:%s", file_path, file_buffer);
            j++;
        }
        }
    }
    fclose(file);
    for (i = 0; i < regex_counter; i++) {
        regfree(&regex_array[i]);
    }
    if (regex_counter > 1) printf("\n");
    return EXIT_SUCCESS;
}

regex_t s21_get_f_regex(char* sample_buffer) {
    regex_t new_regex;
    regcomp(&new_regex, sample_buffer, 0);
    return new_regex;
}
