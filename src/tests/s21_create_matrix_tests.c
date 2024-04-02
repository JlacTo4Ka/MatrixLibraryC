#include "s21_matrix_tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A;
  int rows = 2;
  int columns = 2;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A;
  int rows = 0;
  int columns = 0;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t A;
  int rows = -1;
  int columns = -1;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t A;
  int rows = 5;
  int columns = 5;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t A;
  int rows = 6;
  int columns = 6;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t A;
  int rows = 15;
  int columns = 15;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  matrix_t A;
  int rows = 1;
  int columns = 8;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_10) {
  matrix_t A;
  int rows = 8;
  int columns = 1;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_11) {
  matrix_t A;
  int rows = 3;
  int columns = 9;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_12) {
  matrix_t A;
  int rows = 9;
  int columns = 3;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_13) {
  matrix_t A;
  int rows = 4;
  int columns = 4;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

void test_s21_create_matrix(Suite *s) {
  TCase *tc = tcase_create("s21_create_matrix");
  tcase_add_test(tc, s21_create_matrix_1);
  tcase_add_test(tc, s21_create_matrix_2);
  tcase_add_test(tc, s21_create_matrix_3);
  tcase_add_test(tc, s21_create_matrix_4);
  tcase_add_test(tc, s21_create_matrix_5);
  tcase_add_test(tc, s21_create_matrix_6);
  tcase_add_test(tc, s21_create_matrix_7);
  tcase_add_test(tc, s21_create_matrix_8);
  tcase_add_test(tc, s21_create_matrix_9);
  tcase_add_test(tc, s21_create_matrix_10);
  tcase_add_test(tc, s21_create_matrix_11);
  tcase_add_test(tc, s21_create_matrix_12);
  tcase_add_test(tc, s21_create_matrix_13);

  suite_add_tcase(s, tc);
}