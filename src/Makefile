CC = gcc
FILES = functions/*.c
FLAGS = -Wall -Werror -Wextra -std=c11 
TESTS = tests/*.c tests/*.h
GCOVFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)
MAC_X86 := $(shell uname -a | grep -o _X86_64)
MAC_M1 := $(shell uname -a | grep -o _ARM64)

ifeq ($(OS),Linux)
	TEST_LIBS =-lcheck -lm -lsubunit
else
	TEST_LIBS =-lcheck
endif

ifeq ($(MAC_M1), _ARM64)
	TEST_LIBS := -I/opt/homebrew/opt/check/include -L/opt/homebrew/opt/check/lib -lcheck
	OPEN = open
endif

ifeq ($(MAC_X86), _X86_64)
	TEST_LIBS = $(shell pkg-config --libs --cflags check) -lm
	OPEN = open
endif

all: clean s21_matrix.a test gcov_report

s21_matrix.a: clean 
	$(CC) $(FLAGS) -c $(FILES)
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

s21_matrix_gcov.a: clean
	$(CC) $(FLAGS) $(GCOVFLAGS) -c $(FILES)
	ar rc s21_matrix_gcov.a *.o
	ranlib s21_matrix_gcov.a

test:
	$(CC) $(FLAGS) tests/*.c s21_matrix.a $(TEST_LIBS) -o s21_matrix_test
	./s21_matrix_test

gcov_report: s21_matrix_gcov.a
	$(CC) $(FLAGS) $(GCOVFLAGS) tests/*.c s21_matrix_gcov.a $(TEST_LIBS) -o s21_matrix_gcov
	./s21_matrix_gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcda *.gcno
	open report/index.html

style:
	clang-format -i	*.h $(FILES) $(TESTS)

clean:
	rm -rf report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt s21_matrix_test s21_matrix_gcov

.PHONY: all clean
