#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  out returned_value = OK;

  if (A == NULL || A->columns <= 0 || A->rows <= 0) {
    returned_value = INCORRECT_MATRIX;
  }

  if (s21_create_matrix(A->columns, A->rows, result) != OK &&
      returned_value == OK) {
    returned_value = INCORRECT_MATRIX;
  }

  for (int i = 0; i < result->rows && returned_value == OK; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return returned_value;
}
