#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  out returned_value = OK;

  if (isnan(number) || isinf(number)) returned_value = ERROR_CALC;

  if (A == NULL || A->rows <= 0 || A->columns <= 0)
    returned_value = INCORRECT_MATRIX;

  if (s21_create_matrix(A->rows, A->columns, result) != OK)
    returned_value = INCORRECT_MATRIX;

  for (int i = 0; i < A->rows && returned_value == OK; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return returned_value;
}