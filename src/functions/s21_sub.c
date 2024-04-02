#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  out returned_value = OK;

  if (A == NULL || B == NULL || A->rows <= 0 || B->rows <= 0 ||
      A->columns <= 0 || B->columns <= 0)
    returned_value = INCORRECT_MATRIX;

  if (returned_value == OK &&
      ((A->rows != B->rows) || (A->columns != B->columns))) {
    returned_value = ERROR_CALC;
  }

  if (s21_create_matrix(A->rows, A->columns, result) != OK &&
      returned_value == OK) {
    returned_value = INCORRECT_MATRIX;
  }

  for (int i = 0; i < A->rows && returned_value == OK; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return returned_value;
}