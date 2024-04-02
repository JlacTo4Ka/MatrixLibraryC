#ifndef S21_MATRIX_H
#define S21_MATRIX_H

// Библиотеки
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* структура матрицы */
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum returned_value {
  OK = 0,
  INCORRECT_MATRIX = 1,
  ERROR_CALC = 2
} out;

// --------------------- создание матрицы ------------------------
int s21_create_matrix(int rows, int columns, matrix_t *result);

// --------------------- очистка матрицы -------------------------
void s21_remove_matrix(matrix_t *A);

// --------------------- создание матрицы ------------------------
#define SUCCESS 1
#define FAILURE 0
#define EPSILON 0.0000001

int s21_eq_matrix(matrix_t *A, matrix_t *B);

// --------------------- сложение и вычитание --------------------
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// --------------------- умножение на число ----------------------
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// --------------------- умножение матриц ------------------------
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// --------------------- транспонирование ------------------------
int s21_transpose(matrix_t *A, matrix_t *result);

// --------------------- минор и матрица алгебраических дополнений
// --------------------------
int s21_calc_complements(matrix_t *A, matrix_t *result);

void s21_copy_matrix(matrix_t *A, matrix_t *result);

// --------------------- определитель матрицы --------------------
int s21_determinant(matrix_t *A, double *result);

double s21_find_determinant(matrix_t *A);
double s21_get_minor(matrix_t *A, int i, int j, matrix_t *minor);
void fill_minor(matrix_t *A, int i, int j, matrix_t *minor);

// --------------------- обратная матрица ------------------------
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_calc_complements_without_create(matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX_H
