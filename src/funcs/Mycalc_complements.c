#include "../Mymatrix.h"

int Mycalc_complements(matrix_t *A, matrix_t *result) {
  if (!is_ok(A) || !result) {
    return 1;
  }
  if (A->matrix == NULL) {
    return 1;
  }
  if (A->rows != A->columns) {
    return 2;
  }
  if (Mycreate_matrix(A->columns, A->rows, result) != 0) {
    return 1;
  }
  matrix_t B;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(A->rows - 1, A->columns - 1, &B);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double c = 0;
      for (int iB = 0; iB < A->rows - 1; iB++) {
        for (int jB = 0; jB < A->columns - 1; jB++) {
          B.matrix[iB][jB] = A->matrix[iB][jB];
          if (iB >= i && jB >= j)
            B.matrix[iB][jB] = A->matrix[iB + 1][jB + 1];
          else if (iB >= i)
            B.matrix[iB][jB] = A->matrix[iB + 1][jB];
          else if (jB >= j)
            B.matrix[iB][jB] = A->matrix[iB][jB + 1];
        }
      }
      Mydeterminant(&B, &c);
      if (((i + j) % 2) != 0) c *= -1;
      result->matrix[i][j] = c;
    }
  }
  Myremove_matrix(&B);
  return 0;
}