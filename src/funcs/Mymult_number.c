#include "../Mymatrix.h"

int Mymult_number(matrix_t *A, double number, matrix_t *result) {
  if (!is_ok(A) || !result) {
    return 1;
  }

  if (A->matrix == NULL) {
    return 1;
  }
  if (Mycreate_matrix(A->rows, A->columns, result) != 0) {
    return 1;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return 0;
}