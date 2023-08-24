#include "../Mymatrix.h"

int Mymult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!is_ok(A) || !is_ok(B) || !result) {
    return 1;
  }
  if (A->columns != B->columns) {
    return 2;
  }
  if (A->matrix == NULL || B->matrix == NULL) {
    return 1;
  }
  result->rows = 0;
  result->columns = 0;
  result->matrix = NULL;
  if (Mycreate_matrix(A->rows, A->columns, result) != 0) {
    return 1;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      for (int k = 0; k < A->columns; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }

  return 0;
}
