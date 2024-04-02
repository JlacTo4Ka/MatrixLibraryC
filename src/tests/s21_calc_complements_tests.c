#include "s21_matrix_tests.h"

START_TEST(s21_calc_complements_1) {
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
  int result = s21_calc_complements(&A, &R);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 3);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_int_eq(R.matrix[0][0], -3);
  ck_assert_int_eq(R.matrix[0][1], 6);
  ck_assert_int_eq(R.matrix[0][2], -3);
  ck_assert_int_eq(R.matrix[1][0], 6);
  ck_assert_int_eq(R.matrix[1][1], -12);
  ck_assert_int_eq(R.matrix[1][2], 6);
  ck_assert_int_eq(R.matrix[2][0], -3);
  ck_assert_int_eq(R.matrix[2][1], 6);
  ck_assert_int_eq(R.matrix[2][2], -3);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_calc_complements_2) {
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
  int result = s21_calc_complements(&A, &R);
  ck_assert_int_eq(result, ERROR_CALC);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t A;
  int rows = 0;
  int columns = 0;
  s21_create_matrix(rows, columns, &A);

  matrix_t R;
  int result = s21_calc_complements(&A, &R);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  // printf("-----------%d\n", R.rows);
  s21_remove_matrix(&A);
  // s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;

  matrix_t R;
  int result = s21_calc_complements(&A, &R);
  ck_assert_int_eq(result, ERROR_CALC);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  matrix_t R;
  int result = s21_calc_complements(&A, &R);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 3);
  ck_assert_int_eq(R.columns, 3);
  ck_assert_int_eq(R.matrix[0][0], 0);
  ck_assert_int_eq(R.matrix[0][1], 10);
  ck_assert_int_eq(R.matrix[0][2], -20);
  ck_assert_int_eq(R.matrix[1][0], 4);
  ck_assert_int_eq(R.matrix[1][1], -14);
  ck_assert_int_eq(R.matrix[1][2], 8);
  ck_assert_int_eq(R.matrix[2][0], -8);
  ck_assert_int_eq(R.matrix[2][1], -2);
  ck_assert_int_eq(R.matrix[2][2], 4);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_calc_complements_6) {
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
  A.matrix[2][2] = 111;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;

  matrix_t R;
  int result = s21_calc_complements(&A, &R);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(R.rows, 4);
  ck_assert_int_eq(R.columns, 4);
  ck_assert_int_eq(R.matrix[0][0], -1600);
  ck_assert_int_eq(R.matrix[0][1], 2400);
  ck_assert_int_eq(R.matrix[0][2], 0);
  ck_assert_int_eq(R.matrix[0][3], -800);
  ck_assert_int_eq(R.matrix[1][0], 2400);
  ck_assert_int_eq(R.matrix[1][1], -3600);
  ck_assert_int_eq(R.matrix[1][2], 0);
  ck_assert_int_eq(R.matrix[1][3], 1200);
  ck_assert_int_eq(R.matrix[2][0], 0);
  ck_assert_int_eq(R.matrix[2][1], 0);
  ck_assert_int_eq(R.matrix[2][2], 0);
  ck_assert_int_eq(R.matrix[2][3], 0);
  ck_assert_int_eq(R.matrix[3][0], -800);
  ck_assert_int_eq(R.matrix[3][1], 1200);
  ck_assert_int_eq(R.matrix[3][2], 0);
  ck_assert_int_eq(R.matrix[3][3], -400);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

void test_s21_calc_complements(Suite *s) {
  TCase *tc = tcase_create("s21_calc_complements");
  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);
  tcase_add_test(tc, s21_calc_complements_4);
  tcase_add_test(tc, s21_calc_complements_5);
  tcase_add_test(tc, s21_calc_complements_6);

  suite_add_tcase(s, tc);
}