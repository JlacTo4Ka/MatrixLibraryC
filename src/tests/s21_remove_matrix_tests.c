#include "s21_matrix_tests.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

void test_s21_remove_matrix(Suite *s) {
  TCase *tc = tcase_create("s21_remove_matrix");
  tcase_add_test(tc, s21_remove_matrix_1);

  suite_add_tcase(s, tc);
}