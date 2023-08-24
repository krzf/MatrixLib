#include "../Mymatrix.h"

int Mycreate_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows <= 0 || columns <= 0)
    error = 1;
  else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    error = 1;
    if (result->matrix != NULL) {
      for (int i = 0; i < result->rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
      error = 0;
    }
  }

  return error;
}