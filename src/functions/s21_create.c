#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  out returned_value = OK;

  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
  } else {
    result->matrix = NULL;
    result->rows = 0;
    result->columns = 0;
    returned_value = INCORRECT_MATRIX;
  }

  // Выделение памяти под матрицу
  if (returned_value == OK) {
    result->matrix = (double **)malloc(result->rows * sizeof(double *));
  }

  if (result->matrix == NULL) returned_value = INCORRECT_MATRIX;

  for (int i = 0; i < result->rows && returned_value == OK; i++) {
    result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
    if (result->matrix[i] == NULL) returned_value = INCORRECT_MATRIX;
  }

  for (int i = 0; i < result->rows && returned_value == OK; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0;
    }
  }

  return returned_value;
}
