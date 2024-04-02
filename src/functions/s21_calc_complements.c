#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  out returned_value = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    returned_value = INCORRECT_MATRIX;
  }

  if (returned_value == OK && (A->rows != A->columns || A->rows == 1)) {
    returned_value = ERROR_CALC;
  }

  if (returned_value == OK &&
      s21_create_matrix(A->rows, A->columns, result) != OK) {
    returned_value = ERROR_CALC;
  }

  for (int i = 0; i < A->rows && returned_value == OK; i++) {
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor;
      double temp_res = 0;

      s21_get_minor(A, i, j, &minor);

      s21_determinant(&minor, &temp_res);
      if ((i + j) % 2 == 0) {
        result->matrix[i][j] = temp_res;
      } else {
        result->matrix[i][j] = -temp_res;
      }

      s21_remove_matrix(&minor);
    }
  }

  return returned_value;
}