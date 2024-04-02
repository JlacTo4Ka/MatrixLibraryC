#include "s21_matrix_tests.h"

Suite *s21_matrix_suite(void) {
  Suite *s = suite_create("s21_matrix");

  test_s21_create_matrix(s);
  test_s21_remove_matrix(s);
  test_s21_eq_matrix(s);
  test_s21_sum_matrix(s);
  test_s21_sub_matrix(s);
  test_s21_mult_number(s);
  test_s21_mult_matrix(s);
  test_s21_transpose(s);
  test_s21_calc_complements(s);
  test_s21_determinant(s);
  test_s21_inverse_matrix(s);

  return s;
}

int main(void) {
  int number_faild = 0;
  Suite *s = s21_matrix_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_faild = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_faild == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}