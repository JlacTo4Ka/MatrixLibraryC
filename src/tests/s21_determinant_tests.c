#include "s21_matrix_tests.h"

START_TEST(s21_determinant_1) {
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

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(det, 0, 0.0001);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 2;

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(det, 5, 0.0001);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t A;
  int rows = 0;
  int columns = 0;
  s21_create_matrix(rows, columns, &A);

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t A;
  int rows = 2;
  int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(det, -3, 0.0001);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
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
  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t A;
  int rows = 4;
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
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(det, 0, 0.0001);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t A;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 11;
  A.matrix[0][1] = 21;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = -8;
  A.matrix[1][3] = 9;
  A.matrix[1][4] = 10;
  A.matrix[2][0] = 11;
  A.matrix[2][1] = 12;
  A.matrix[2][2] = 13;
  A.matrix[2][3] = 14;
  A.matrix[2][4] = 15;
  A.matrix[3][0] = 16;
  A.matrix[3][1] = 17;
  A.matrix[3][2] = 18;
  A.matrix[3][3] = 19;
  A.matrix[3][4] = 20;
  A.matrix[4][0] = 21;
  A.matrix[4][1] = 22;
  A.matrix[4][2] = 23;
  A.matrix[4][3] = 24;
  A.matrix[4][4] = -25;

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(det, -148000, 0.0001);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_8) {
  matrix_t A;
  int rows = 4;
  int columns = 4;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -5;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = -11;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(det, -2112, 0.0001);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_9) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.2;

  double det;
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(det, 1.2, 0.0001);
  s21_remove_matrix(&A);
}
END_TEST

void test_s21_determinant(Suite *s) {
  TCase *tc = tcase_create("s21_determinant");
  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);

  suite_add_tcase(s, tc);
}