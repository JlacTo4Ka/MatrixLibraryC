#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  out returned_value = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0)
    returned_value = INCORRECT_MATRIX;
  if (returned_value == OK && A->rows != A->columns)
    returned_value = ERROR_CALC;

  double determinant_A = 0;
  if (returned_value == OK) {
    int status_det = s21_determinant(A, &determinant_A);
    if (status_det != OK) returned_value = status_det;
  }

  if (returned_value == OK &&
      (fabs(determinant_A) < EPSILON ||
       (A->rows == 1 && fabs(A->matrix[0][0]) < EPSILON)))
    returned_value = ERROR_CALC;

  if (s21_create_matrix(A->rows, A->columns, result) != OK &&
      returned_value == OK)
    returned_value = INCORRECT_MATRIX;

  if (returned_value == OK && A->rows == 1) {
    result->matrix[0][0] = 1 / A->matrix[0][0];
  }

  if (returned_value == OK && A->rows != 1) {
    int status_complements = s21_calc_complements_without_create(A, result);
    if (status_complements != OK) returned_value = status_complements;
  }

  matrix_t transposed_matrix;
  if (returned_value == OK && A->rows != 1) {
    int status_transpose = s21_transpose(result, &transposed_matrix);
    if (status_transpose != OK) {
      returned_value = status_transpose;
    } else {
      s21_copy_matrix(&transposed_matrix, result);
    }

    s21_remove_matrix(&transposed_matrix);
  }

  if (returned_value == OK && A->rows != 1) {
    for (int i = 0; i < A->rows && returned_value == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] /= determinant_A;
      }
    }
  }

  return returned_value;
}

void s21_copy_matrix(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j];
    }
  }
}

int s21_calc_complements_without_create(matrix_t *A, matrix_t *result) {
  out returned_value = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    returned_value = INCORRECT_MATRIX;
  }

  if (returned_value == OK && (A->rows != A->columns || A->rows == 1)) {
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