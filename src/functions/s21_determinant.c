#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  out returned_value = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    returned_value = INCORRECT_MATRIX;
  }

  if (returned_value == OK && A->rows != A->columns) {
    returned_value = ERROR_CALC;
  }

  if (A->rows == 1 && returned_value == OK) {
    *result = A->matrix[0][0];
  }

  if (A->rows == 2 && returned_value == OK) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  }

  if (A->rows == 3 && returned_value == OK) {
    *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
              A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
              A->matrix[0][2] * A->matrix[1][0] * A->matrix[2][1] -
              A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
              A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2] -
              A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1];
  }

  if (A->rows > 3 && returned_value == OK) {
    *result = s21_find_determinant(A);
  }

  return returned_value;
}

double s21_find_determinant(matrix_t *A) {
  double res_determinant = 0;

  for (int j = 0; j < A->columns; j++) {
    matrix_t minor;
    double temp_res = 0;

    temp_res = s21_get_minor(A, 0, j, &minor);

    if ((0 + j) % 2 == 0) {
      res_determinant += A->matrix[0][j] * temp_res;
    } else {
      res_determinant -= A->matrix[0][j] * temp_res;
    }

    s21_remove_matrix(&minor);
  }

  return res_determinant;
}

double s21_get_minor(matrix_t *A, int i, int j, matrix_t *minor) {
  double res = 0;

  s21_create_matrix(A->rows - 1, A->columns - 1, minor);

  fill_minor(A, i, j, minor);

  s21_determinant(minor, &res);

  return res;
}

void fill_minor(matrix_t *A, int i, int j, matrix_t *minor) {
  int row_shift = 0;
  int col_shift = 0;

  for (int n = 0; n < minor->rows; n++) {
    if (n == i) {
      row_shift = 1;
    }

    for (int m = 0; m < minor->columns; m++) {
      if (m == j) {
        col_shift = 1;
      }
      minor->matrix[n][m] = A->matrix[n + row_shift][m + col_shift];
    }
    col_shift = 0;
  }
}
