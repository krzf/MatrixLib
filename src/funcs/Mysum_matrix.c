#include "../Mymatrix.h"
// aaaaaaaaaaaaaaaaaaaaaaaaaaa

int Mysum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!is_ok(A) || !is_ok(B) || !result) {
    return 1;
  }
  if (A->columns != B->columns || A->rows != B->rows) {
    return 2;
  }
  if (A->matrix == NULL || B->matrix == NULL) {
    return 1;
  }
  if (Mycreate_matrix(A->rows, A->columns, result) != 0) {
    return 1;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return 0;
}