#include "s21_matrix_tests.h"

START_TEST(s21_sum_matrix_1) {
  matrix_t A;
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  matrix_t B;
  int rows2 = 2;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  matrix_t R;
  int result_sum = s21_sum_matrix(&A, &B, &R);

  matrix_t expected;
  int rows_expected = 2;
  int columns_expected = 3;
  s21_create_matrix(rows_expected, columns_expected, &expected);
  expected.matrix[0][0] = 2;
  expected.matrix[0][1] = 4;
  expected.matrix[0][2] = 7;
  expected.matrix[1][0] = 8;
  expected.matrix[1][1] = 10;
  expected.matrix[1][2] = 12;

  int result = s21_eq_matrix(&R, &expected);
  ck_assert_int_eq(result_sum, OK);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A;
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.2;
  A.matrix[0][2] = 4.4;
  A.matrix[1][0] = 4.4;
  A.matrix[1][1] = 5.5;
  A.matrix[1][2] = 6.6;

  matrix_t B;
  int rows2 = 2;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  matrix_t R;
  int result_sum = s21_sum_matrix(&A, &B, &R);

  matrix_t expected;
  int rows_expected = 2;
  int columns_expected = 3;
  s21_create_matrix(rows_expected, columns_expected, &expected);
  expected.matrix[0][0] = 2.1;
  expected.matrix[0][1] = 4.2;
  expected.matrix[0][2] = 7.4;
  expected.matrix[1][0] = 8.4;
  expected.matrix[1][1] = 10.5;
  expected.matrix[1][2] = 12.6;

  int result = s21_eq_matrix(&R, &expected);
  ck_assert_int_eq(result_sum, OK);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t A;
  int rows = 2;
  int columns = 4;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[0][3] = 5;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 7;

  matrix_t B;
  int rows2 = 2;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  matrix_t R;
  int result_sum = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(result_sum, ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t A;
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

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
  int result_sum = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(result_sum, ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A;
  int rows = 0;
  int columns = 3;
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
  int result_sum = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(result_sum, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
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
  int columns2 = 0;
  s21_create_matrix(rows2, columns2, &B);

  matrix_t R;
  int result_sum = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(result_sum, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

void test_s21_sum_matrix(Suite *s) {
  TCase *tc = tcase_create("s21_sum_matrix");
  tcase_add_test(tc, s21_sum_matrix_1);
  tcase_add_test(tc, s21_sum_matrix_2);
  tcase_add_test(tc, s21_sum_matrix_3);
  tcase_add_test(tc, s21_sum_matrix_4);
  tcase_add_test(tc, s21_sum_matrix_5);
  tcase_add_test(tc, s21_sum_matrix_6);

  suite_add_tcase(s, tc);
}