#include "s21_matrix_tests.h"

START_TEST(s21_inverse_matrix_1) {
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
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, ERROR_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t A;
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, ERROR_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t A;
  int rows = -1;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, OK);

  ck_assert_int_eq(R.rows, 1);
  ck_assert_int_eq(R.columns, 1);
  ck_assert_double_eq_tol(R.matrix[0][0], 0.5, 0.0001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  matrix_t A;
  int rows = 2;
  int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, OK);

  ck_assert_int_eq(R.rows, 2);
  ck_assert_int_eq(R.columns, 2);
  ck_assert_double_eq_tol(R.matrix[0][0], -2, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][1], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][0], 1.5, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][1], -0.5, 0.0001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, OK);

  ck_assert_int_eq(R.rows, 3);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_double_eq_tol(R.matrix[0][0], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][1], -2, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][2], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][0], -2, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][1], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][2], 0, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][0], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][1], (2.0 / 3.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][2], (-2.0 / 3.0), 0.0001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_7) {
  matrix_t A;
  int rows = 4;
  int columns = 4;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 11;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 2;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, OK);

  ck_assert_int_eq(R.rows, 4);
  ck_assert_int_eq(R.columns, 4);
  ck_assert_double_eq_tol(R.matrix[0][0], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][1], -2, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][2], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][3], 0, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][0], -2, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][1], (33.0 / 28.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][2], (-3.0 / 28.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][3], (-1.0 / 14.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][0], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][1], (9.0 / 14.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][2], (-11.0 / 14.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][3], (1.0 / 7.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[3][0], 0, 0.0001);
  ck_assert_double_eq_tol(R.matrix[3][1], (-1.0 / 14.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[3][2], (1.0 / 7.0), 0.0001);
  ck_assert_double_eq_tol(R.matrix[3][3], (-1.0 / 14.0), 0.0001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_8) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, ERROR_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_9) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 3);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_double_eq_tol(R.matrix[0][0], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][1], -1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][2], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][0], -38, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][1], 41, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][2], -34, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][0], 27, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][1], -29, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][2], 24, 0.0001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_10) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  matrix_t R;
  int result = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 3);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_double_eq_tol(R.matrix[0][0], -1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][1], 1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[0][2], -1, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][0], 38, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][1], -35, 0.0001);
  ck_assert_double_eq_tol(R.matrix[1][2], 42, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][0], -27, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][1], 25, 0.0001);
  ck_assert_double_eq_tol(R.matrix[2][2], -30, 0.0001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

void test_s21_inverse_matrix(Suite *s) {
  TCase *tc = tcase_create("s21_inverse_matrix");
  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);
  tcase_add_test(tc, s21_inverse_matrix_4);
  tcase_add_test(tc, s21_inverse_matrix_5);
  tcase_add_test(tc, s21_inverse_matrix_6);
  tcase_add_test(tc, s21_inverse_matrix_7);
  tcase_add_test(tc, s21_inverse_matrix_8);
  tcase_add_test(tc, s21_inverse_matrix_9);
  tcase_add_test(tc, s21_inverse_matrix_10);

  suite_add_tcase(s, tc);
}