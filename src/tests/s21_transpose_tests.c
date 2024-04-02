#include "s21_matrix_tests.h"

START_TEST(s21_transpose_1) {
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
  int result = s21_transpose(&A, &R);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 3);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_int_eq(R.matrix[0][0], 1);
  ck_assert_int_eq(R.matrix[0][1], 4);
  ck_assert_int_eq(R.matrix[0][2], 7);
  ck_assert_int_eq(R.matrix[1][0], 2);
  ck_assert_int_eq(R.matrix[1][1], 5);
  ck_assert_int_eq(R.matrix[1][2], 8);
  ck_assert_int_eq(R.matrix[2][0], 3);
  ck_assert_int_eq(R.matrix[2][1], 6);
  ck_assert_int_eq(R.matrix[2][2], 9);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t A;
  int rows = 3;
  int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  matrix_t R;
  int result = s21_transpose(&A, &R);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 2);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_int_eq(R.matrix[0][0], 1);
  ck_assert_int_eq(R.matrix[0][1], 2);
  ck_assert_int_eq(R.matrix[0][2], 3);
  ck_assert_int_eq(R.matrix[1][0], 4);
  ck_assert_int_eq(R.matrix[1][1], 5);
  ck_assert_int_eq(R.matrix[1][2], 6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t A;
  int rows = 0;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t R;
  int result = s21_transpose(&A, &R);

  ck_assert_int_eq(result, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

void test_s21_transpose(Suite *s) {
  TCase *tc = tcase_create("s21_transpose");
  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);
  tcase_add_test(tc, s21_transpose_3);

  suite_add_tcase(s, tc);
}