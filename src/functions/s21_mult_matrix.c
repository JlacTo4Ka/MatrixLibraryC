#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  out returned_value = OK;

  if (A == NULL || B == NULL || A->rows <= 0 || A->columns <= 0 ||
      B->rows <= 0 || B->columns <= 0)
    returned_value = INCORRECT_MATRIX;

  if (returned_value == OK && A->columns != B->rows)
    returned_value = ERROR_CALC;

  if (s21_create_matrix(A->rows, B->columns, result) != OK &&
      returned_value == OK)
    returned_value = INCORRECT_MATRIX;

  for (int i = 0; i < A->rows && returned_value == OK; i++) {
    for (int j = 0; j < B->columns && returned_value == OK; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return returned_value;
}