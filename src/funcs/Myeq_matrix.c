#include "../Mymatrix.h"

#define SUCCESS 1
#define FAILURE 0

//Сравнение должно происходить вплоть до 7 знака после запятой включительно.
int Myeq_matrix(matrix_t *A, matrix_t *B) {
  int error = 0;
  if (!A || !B) {
    error = FAILURE;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = FAILURE;
  } else if (A->rows < 1 || B->rows < 1 || A->columns < 1 || B->columns < 1) {
    error = FAILURE;
  } else if (A->matrix == NULL || B->matrix == NULL) {
    error = FAILURE;
  } else if (A->rows == B->rows && A->columns == B->columns) {
    error = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
          error = FAILURE;
        }
      }
    }
  }

  return error;
}
