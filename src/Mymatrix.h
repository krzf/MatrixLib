#ifndef MyMATRIX
#define MyMATRIX

// def errrs
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// eq

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// 11 matric
// base
int Mycreate_matrix(int rows, int columns, matrix_t *result);
void Myremove_matrix(matrix_t *A);

// sravn
int Myeq_matrix(matrix_t *A, matrix_t *B);

// Arith
int Mysum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int Mysub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int Mymult_number(matrix_t *A, double number, matrix_t *result);
int Mymult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//???
int Mytranspose(matrix_t *A, matrix_t *result);
int Mycalc_complements(matrix_t *A, matrix_t *result);
int Mydeterminant(matrix_t *A, double *result);
int Myinverse_matrix(matrix_t *A, matrix_t *result);

// help
int is_ok(matrix_t *A);

#endif  // MyMATRIX