#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int returned_value = SUCCESS;

  if ((A->rows != B->rows) || (A->columns != B->columns) || A == NULL ||
      B == NULL) {
    returned_value = FAILURE;  // ERROR_CALC?
  }

  for (int i = 0; i < A->rows && returned_value == SUCCESS; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        returned_value = FAILURE;
      }
    }
  }

  return returned_value;
}