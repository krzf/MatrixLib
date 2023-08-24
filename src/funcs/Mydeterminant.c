#include "../Mymatrix.h"

int Mydeterminant(matrix_t *A, double *result) {
  if (!is_ok(A) || !result) {
    return 1;
  }
  if (A->matrix == NULL) {
    return 1;
  }
  if (A->rows != A->columns) {
    return 2;
  }
  double temp = 0;
  *result = 1;
  matrix_t B;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(A->rows, A->columns, &B);
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) B.matrix[i][j] = A->matrix[i][j];
  for (int k = 0; k < B.rows - 1; k++) {
    int max_row = k;
    for (int i = k + 1; i < B.rows; i++) {
      if (fabs(B.matrix[i][k]) > fabs(B.matrix[max_row][k])) {
        max_row = i;
      }
    }
    if (max_row != k) {
      *result *= -1;
      for (int j = 0; j < B.columns; j++) {
        double temp = B.matrix[k][j];
        B.matrix[k][j] = B.matrix[max_row][j];
        B.matrix[max_row][j] = temp;
      }
    }
    if (B.matrix[k][k] == 0) {
      *result = 0;
      break;
    }
    for (int i = k + 1; i < B.rows; i++) {
      temp = -(B.matrix[i][k]) / B.matrix[k][k];
      for (int j = 0; j < B.rows; j++) B.matrix[i][j] += B.matrix[k][j] * temp;
    }
  }
  for (int i = 0; i < B.rows; i++) *result *= B.matrix[i][i];
  if (fabs(*result) < 1e-8) *result = 0;
  Myremove_matrix(&B);
  return 0;
}
