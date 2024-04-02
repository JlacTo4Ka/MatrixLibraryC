#include "s21_matrix_tests.h"

START_TEST(s21_eq_matrix_1) {  // утечка
  // printf("\n\ns21_eq_matrix_1\n\n");
  matrix_t A;
  int rows = 3;
  int columns = 3;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  matrix_t B;
  int rows2 = 3;
  int columns2 = 3;
  int result2 = s21_create_matrix(rows2, columns2, &B);
  ck_assert_int_eq(result2, OK);
  ck_assert_int_eq(B.rows, rows2);
  ck_assert_int_eq(B.columns, columns2);
  int result3 = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result3, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  // printf("\n\ns21_eq_matrix_1\n\n");
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  // printf("\n\ns21_eq_matrix_2\n\n");
  matrix_t A;
  int rows = 4;
  int columns = 3;
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  matrix_t B;
  int rows2 = 3;
  int columns2 = 3;
  int result2 = s21_create_matrix(rows2, columns2, &B);
  ck_assert_int_eq(result2, OK);
  ck_assert_int_eq(B.rows, rows2);
  ck_assert_int_eq(B.columns, columns2);
  int result3 = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result3, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("\n\ns21_eq_matrix_2\n\n");
}
END_TEST

START_TEST(s21_eq_matrix_3) {  // утечка
  // printf("\n\ns21_eq_matrix_3\n\n");
  matrix_t A;
  int rows = 4;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 1;
  A.matrix[2][0] = 1;
  A.matrix[3][0] = 1;
  matrix_t B;
  int rows2 = 4;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 1;
  B.matrix[2][0] = 1;
  B.matrix[3][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("\n\ns21_eq_matrix_3\n\n");
}
END_TEST

START_TEST(s21_eq_matrix_4) {  // утечка
  // printf("\n\ns21_eq_matrix_4\n\n");
  matrix_t A;
  int rows = 4;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 1;
  A.matrix[2][0] = 1;
  A.matrix[3][0] = 1;
  matrix_t B;
  int rows2 = 4;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 1;
  B.matrix[2][0] = 0;
  B.matrix[3][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("\n\ns21_eq_matrix_4\n\n");
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  // printf("\n\ns21_eq_matrix_5\n\n");
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
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("\n\ns21_eq_matrix_5\n\n");
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  // printf("\n\ns21_eq_matrix_6\n\n");
  matrix_t A;
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2.2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  matrix_t B;
  int rows2 = 2;
  int columns2 = 3;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2.2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("\n\ns21_eq_matrix_6\n\n");
}
END_TEST

void test_s21_eq_matrix(Suite *s) {
  TCase *tc = tcase_create("s21_eq_matrix");
  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);
  tcase_add_test(tc, s21_eq_matrix_5);
  tcase_add_test(tc, s21_eq_matrix_6);

  suite_add_tcase(s, tc);
}