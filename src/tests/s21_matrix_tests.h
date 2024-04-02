#ifndef SRC_TESTS_S21_MATRIX_TESTS_H
#define SRC_TESTS_S21_MATRIX_TESTS_H

#include <check.h>

#include "../s21_matrix.h"

void test_s21_create_matrix(Suite *s);
void test_s21_remove_matrix(Suite *s);
void test_s21_eq_matrix(Suite *s);
void test_s21_sum_matrix(Suite *s);
void test_s21_sub_matrix(Suite *s);
void test_s21_mult_number(Suite *s);
void test_s21_mult_matrix(Suite *s);
void test_s21_transpose(Suite *s);
void test_s21_calc_complements(Suite *s);
void test_s21_determinant(Suite *s);
void test_s21_inverse_matrix(Suite *s);

#endif  // SRC_TESTS_S21_MATRIX_TESTS_H