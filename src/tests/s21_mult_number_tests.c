#include "s21_matrix_tests.h"

START_TEST(s21_mult_number_1) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  matrix_t R;
  int result = s21_mult_number(&A, 2, &R);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 3);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_int_eq(R.matrix[0][0], 2);
  ck_assert_int_eq(R.matrix[0][1], 4);
  ck_assert_int_eq(R.matrix[0][2], 6);
  ck_assert_int_eq(R.matrix[1][0], 8);
  ck_assert_int_eq(R.matrix[1][1], 10);
  ck_assert_int_eq(R.matrix[1][2], 12);
  ck_assert_int_eq(R.matrix[2][0], 14);
  ck_assert_int_eq(R.matrix[2][1], 16);
  ck_assert_int_eq(R.matrix[2][2], 18);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A;
  int rows = 0;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t R;
  int result = s21_mult_number(&A, 2, &R);

  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

void test_s21_mult_number(Suite *s) {
  TCase *tc = tcase_create("s21_mult_number");
  tcase_add_test(tc, s21_mult_number_1);
  tcase_add_test(tc, s21_mult_number_2);

  suite_add_tcase(s, tc);
}