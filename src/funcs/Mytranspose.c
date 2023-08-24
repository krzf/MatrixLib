#include "../Mymatrix.h"

int Mytranspose(matrix_t *A, matrix_t *result) {
  if (!is_ok(A) || !result) {
    return 1;
  }

  if (A->matrix == NULL) {
    return 1;
  }
  if (Mycreate_matrix(A->columns, A->rows, result) != 0) {
    return 1;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return 0;
}