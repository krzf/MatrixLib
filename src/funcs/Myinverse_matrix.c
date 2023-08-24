#include "../Mymatrix.h"

int Myinverse_matrix(matrix_t *A, matrix_t *result) {
  if (!is_ok(A) || !result) {
    return 1;
  }
  if (A->matrix == NULL) {
    return 1;
  }
  if (A->rows != A->columns) {
    return 2;
  }
  double d = 0;
  Mydeterminant(A, &d);
  if (d == 0) return 2;
  matrix_t temp;
  Mycalc_complements(A, result);
  Mytranspose(result, &temp);
  Myremove_matrix(result);
  Mymult_number(&temp, 1.0 / d, result);
  Myremove_matrix(&temp);
  return 0;
}
