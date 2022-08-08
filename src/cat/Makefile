CC := gcc
CFLAGS :=-std=c11 -Wall -Werror -Wextra
GFLAGS :=-fprofile-arcs -ftest-coverage
TST_LIBS :=-lm

all: s21_cat test 

s21_cat: s21_cat.o
	$(CC) $(CFLAGS) s21_cat.o -o s21_cat
	$(CC) $(CFLAGS) -c s21_cat.c -o s21_cat.o

test: s21_cat s21_cat_test.o
	$(CC) $(CFLAGS) $(GFLAGS) s21_cat_test.c $(TST_LIBS) -o test --coverage
	./test

clean:
	rm *.o *.cfg *.info .info *.gcda *.gcno test s21_cat
	rm -rf report

gcov-report :
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check:
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@echo
	@echo ===CPPCHECK===
	@echo
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	@echo
	@echo ===STYLE TEST===
	@echo
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
	@echo
	@echo ===LEAKS TEST===
	@echo
	CK_FORK=no leaks -atExit -- ./test

rebuild :
	clean
	make
