#include "s21_matrix_tests.h"

START_TEST(s21_mult_matrix_1) {
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

  matrix_t B;
  int rows2 = 3;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  matrix_t R;
  int result_mult = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(result_mult, OK);

  matrix_t expected;
  int rows_expected = 3;
  int columns_expected = 3;
  s21_create_matrix(rows_expected, columns_expected, &expected);
  expected.matrix[0][0] = 30;
  expected.matrix[0][1] = 36;
  expected.matrix[0][2] = 42;
  expected.matrix[1][0] = 66;
  expected.matrix[1][1] = 81;
  expected.matrix[1][2] = 96;
  expected.matrix[2][0] = 102;
  expected.matrix[2][1] = 126;
  expected.matrix[2][2] = 150;

  int result_compare = s21_eq_matrix(&expected, &R);
  ck_assert_int_eq(result_compare, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
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

  matrix_t B;
  int rows2 = 2;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  matrix_t R;
  int result_mult = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(result_mult, OK);

  matrix_t expected;
  int rows_expected = 3;
  int columns_expected = 3;
  s21_create_matrix(rows_expected, columns_expected, &expected);
  expected.matrix[0][0] = 9;
  expected.matrix[0][1] = 11;
  expected.matrix[0][2] = 17;
  expected.matrix[1][0] = 12;
  expected.matrix[1][1] = 13;
  expected.matrix[1][2] = 22;
  expected.matrix[2][0] = 15;
  expected.matrix[2][1] = 15;
  expected.matrix[2][2] = 27;

  int result_compare = s21_eq_matrix(&expected, &R);
  ck_assert_int_eq(result_compare, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A;
  int rows = 3;
  int columns = 0;
  s21_create_matrix(rows, columns, &A);

  matrix_t B;
  int rows2 = 3;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  matrix_t R;
  int result_mult = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(result_mult, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t A;
  int rows = 3;
  int columns = 4;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
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

  matrix_t B;
  int rows2 = 3;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  matrix_t R;
  int result_mult = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(result_mult, ERROR_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
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

  matrix_t B;
  int rows2 = 2;
  int columns2 = 2;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  matrix_t R;
  int result_mult = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(result_mult, ERROR_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

void test_s21_mult_matrix(Suite *s) {
  TCase *tc = tcase_create("s21_mult_matrix");
  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, s21_mult_matrix_5);

  suite_add_tcase(s, tc);
}