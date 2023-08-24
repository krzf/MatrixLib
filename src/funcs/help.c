#include "../Mymatrix.h"

int is_ok(matrix_t *A) { return A && A->rows > 0 && A->columns > 0; }