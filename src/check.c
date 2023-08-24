#include <check.h>
#include <stdio.h>
#include <wchar.h>

#include "Mymatrix.h"

#define SUCCESS 1
#define FAILURE 0

#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define WHITE "\x1B[0m"

// create
START_TEST(create_matrix_1) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(16, 6, &my_matrix);
  ck_assert_int_eq(error, 0);
  Myremove_matrix(&my_matrix);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(0, 0, &my_matrix);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(-3, 8, &my_matrix);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(create_matrix_4) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(4, 54, &my_matrix);
  ck_assert_int_eq(error, 0);
  Myremove_matrix(&my_matrix);
}
END_TEST

START_TEST(create_matrix_5) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(-54, 0, &my_matrix);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(create_matrix_6) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(999, 999, &my_matrix);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(create_matrix_7) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(1410657, 1, &my_matrix);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(create_matrix_8) {
  matrix_t my_matrix;
  int error = Mycreate_matrix(1, 1410657, &my_matrix);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("Mycreate_matrix");
  TCase *tc = tcase_create("create_matrix");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);
  tcase_add_test(tc, create_matrix_6);
  tcase_add_test(tc, create_matrix_7);
  tcase_add_test(tc, create_matrix_8);

  suite_add_tcase(s, tc);
  return s;
}
// equal

START_TEST(eq_matrix_8) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  matrix_t B;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  int rowA = 1, rowB = 1, colA = 2, colB = 2;
  Mycreate_matrix(rowA, colA, &A);
  Mycreate_matrix(rowB, colB, &B);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) A.matrix[i][j] = i + j;
  for (int i = 0; i < B.rows; i++)
    for (int j = 0; j < B.columns; j++) B.matrix[i][j] = i + j;
  ck_assert_int_eq(Myeq_matrix(&A, &B), 1);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_9) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  matrix_t B;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  int rowA = 1, rowB = 1, colA = 2, colB = 2;
  Mycreate_matrix(rowA, colA, &A);
  Mycreate_matrix(rowB, colB, &B);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) A.matrix[i][j] = i + j;
  for (int i = 0; i < B.rows; i++)
    for (int j = 0; j < B.columns; j++) B.matrix[i][j] = i + j;
  A.matrix[0][0] = -1;
  ck_assert_int_eq(Myeq_matrix(&A, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_10) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  matrix_t B;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  int rowA = 1, rowB = 2, colA = 2, colB = 2;
  Mycreate_matrix(rowA, colA, &A);
  Mycreate_matrix(rowB, colB, &B);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) A.matrix[i][j] = i + j;
  for (int i = 0; i < B.rows; i++)
    for (int j = 0; j < B.columns; j++) B.matrix[i][j] = i + j;
  ck_assert_int_eq(Myeq_matrix(&A, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_11) { ck_assert_int_eq(Myeq_matrix(NULL, NULL), 0); }
END_TEST

START_TEST(eq_matrix_12) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Myeq_matrix(&A, NULL), 0);
}
END_TEST

START_TEST(eq_matrix_13) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  ck_assert_int_eq(Myeq_matrix(&A, &B), 0);
}
END_TEST

START_TEST(eq_matrix_14) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  Mycreate_matrix(2, 3, &B);
  ck_assert_int_eq(Myeq_matrix(&A, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_15) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  ck_assert_int_eq(Myeq_matrix(&A, &B), 0);
  Myremove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_16) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(3, 2, &A);
  Mycreate_matrix(2, 2, &B);
  ck_assert_int_eq(Myeq_matrix(&A, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

//
START_TEST(eq_matrix_1) {
  matrix_t matrix_1, matrix_2;
  Mycreate_matrix(4, 4, &matrix_1);
  Mycreate_matrix(4, 4, &matrix_2);
  int error = Myeq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(error, SUCCESS);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t matrix_1, matrix_2;
  Mycreate_matrix(3, 4, &matrix_1);
  Mycreate_matrix(4, 3, &matrix_2);
  int error = Myeq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(error, FAILURE);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t matrix_1, matrix_2;
  Mycreate_matrix(-3, 0, &matrix_1);
  Mycreate_matrix(-4, 3, &matrix_2);
  int error = Myeq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(error, FAILURE);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t matrix_1, matrix_2;
  Mycreate_matrix(2, 3, &matrix_1);
  Mycreate_matrix(2, 3, &matrix_2);
  for (int i = 0; i < 6; i++)
    matrix_1.matrix[i / 3][i % 3] = matrix_2.matrix[i / 3][i % 3] = i;
  int error = Myeq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(error, SUCCESS);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t matrix_1, matrix_2;
  Mycreate_matrix(3, 2, &matrix_1);
  Mycreate_matrix(2, 3, &matrix_2);
  for (int i = 0; i < 6; i++)
    matrix_1.matrix[i / 2][i % 2] = matrix_2.matrix[i / 3][i % 3] = i;
  int error = Myeq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(error, FAILURE);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_matrix_6) {
  matrix_t matrix_1, matrix_2;
  Mycreate_matrix(4, 4, &matrix_1);
  Mycreate_matrix(4, 4, &matrix_2);
  for (int i = 0; i < 16; i++)
    matrix_1.matrix[i / 4][i % 4] = matrix_2.matrix[i / 4][i % 4] = i;
  matrix_1.matrix[2][2] = 1.666667;
  matrix_2.matrix[2][2] = 1.666668;
  int error = Myeq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(error, FAILURE);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_matrix_7) {
  matrix_t matrix_1, matrix_2;
  Mycreate_matrix(4, 4, &matrix_1);
  Mycreate_matrix(4, 4, &matrix_2);
  for (int i = 0; i < 16; i++)
    matrix_1.matrix[i / 4][i % 4] = matrix_2.matrix[i / 4][i % 4] = i;
  matrix_1.matrix[2][2] = 1.66666667;
  matrix_2.matrix[2][2] = 1.66666668;
  int error = Myeq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(error, SUCCESS);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("Myeq_matrix");
  TCase *tc = tcase_create("case_eq");

  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);
  tcase_add_test(tc, eq_matrix_6);
  tcase_add_test(tc, eq_matrix_7);
  tcase_add_test(tc, eq_matrix_8);
  tcase_add_test(tc, eq_matrix_9);
  tcase_add_test(tc, eq_matrix_10);
  tcase_add_test(tc, eq_matrix_11);
  tcase_add_test(tc, eq_matrix_12);
  tcase_add_test(tc, eq_matrix_13);
  tcase_add_test(tc, eq_matrix_14);
  tcase_add_test(tc, eq_matrix_15);
  tcase_add_test(tc, eq_matrix_16);
  suite_add_tcase(s, tc);
  return s;
}
// make sum
START_TEST(sum_0) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  matrix_t B;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  matrix_t result;
  int rowA = 10, rowB = 10, colA = 2, colB = 2;
  Mycreate_matrix(rowA, colA, &A);
  Mycreate_matrix(rowB, colB, &B);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) A.matrix[i][j] = -10;
  for (int i = 0; i < B.rows; i++)
    for (int j = 0; j < B.columns; j++) B.matrix[i][j] = 25;
  A.matrix[0][0] = 100;
  Mysum_matrix(&A, &B, &result);
  ck_assert_double_eq(result.matrix[0][0], 125);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (j + i > 0) ck_assert_double_eq(result.matrix[i][j], 15);
    }
  }
  Myremove_matrix(&A);
  Myremove_matrix(&B);
  Myremove_matrix(&result);
}
END_TEST

START_TEST(sum_1) { ck_assert_int_eq(Mysum_matrix(NULL, NULL, NULL), 1); }
END_TEST

START_TEST(sum_2) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Mysum_matrix(&A, NULL, NULL), 1);
}
END_TEST

START_TEST(sum_3) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  ck_assert_int_eq(Mysum_matrix(&A, &B, &r), 1);
}
END_TEST

START_TEST(sum_4) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  Mycreate_matrix(2, 3, &B);
  ck_assert_int_eq(Mysum_matrix(&A, &B, &r), 2);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(sum_5) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  ck_assert_int_eq(Mysum_matrix(&A, &B, &r), 1);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(sum_6) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(3, 2, &A);
  Mycreate_matrix(2, 2, &B);
  ck_assert_int_eq(Mysum_matrix(&A, &B, &r), 2);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(sum_7) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  Mycreate_matrix(2, 2, &B);
  ck_assert_int_eq(Mysum_matrix(&A, &B, &r), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
  Myremove_matrix(&r);
}
END_TEST

START_TEST(sum_8) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(3, 2, &A);
  Mycreate_matrix(2, 2, &B);
  B.columns = 0;
  ck_assert_int_eq(Mysum_matrix(&A, &B, &r), 1);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("suite_sum");
  TCase *tc = tcase_create("case_sum");
  tcase_add_test(tc, sum_0);
  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  tcase_add_test(tc, sum_4);
  tcase_add_test(tc, sum_5);
  tcase_add_test(tc, sum_6);
  tcase_add_test(tc, sum_7);
  tcase_add_test(tc, sum_8);
  suite_add_tcase(s, tc);
  return s;
}
// sub
START_TEST(sub_matrix_1) {
  matrix_t matrix_1, matrix_2, res_sub, res_exmpl;
  Mycreate_matrix(4, 4, &matrix_1);
  Mycreate_matrix(4, 4, &matrix_2);
  Mycreate_matrix(4, 4, &res_exmpl);
  for (int i = 0; i < 16; i++) {
    matrix_1.matrix[i / 4][i % 4] = i + 5 * i;
    matrix_2.matrix[i / 4][i % 4] = i * 3;
    res_exmpl.matrix[i / 4][i % 4] = i + 2 * i;
  }

  int error = Mysub_matrix(&matrix_1, &matrix_2, &res_sub);
  ck_assert_int_eq(error, 0);
  error = Myeq_matrix(&res_sub, &res_exmpl);
  ck_assert_int_eq(error, SUCCESS);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
  Myremove_matrix(&res_sub);
  Myremove_matrix(&res_exmpl);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t matrix_1, matrix_2, res_sub, res_exmpl;
  Mycreate_matrix(4, 4, &matrix_1);
  Mycreate_matrix(4, 4, &matrix_2);
  Mycreate_matrix(4, 4, &res_exmpl);
  for (int i = 0; i < 16; i++) {
    matrix_1.matrix[i / 4][i % 4] = (i * 1.) / 3.;
    matrix_2.matrix[i / 4][i % 4] = (i * 1.);
    res_exmpl.matrix[i / 4][i % 4] = ((2 * i * 1.) / 3.);
  }

  int error = Mysub_matrix(&matrix_1, &matrix_2, &res_sub);
  ck_assert_int_eq(error, 0);
  error = Myeq_matrix(&res_sub, &res_exmpl);
  ck_assert_int_eq(error, FAILURE);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
  Myremove_matrix(&res_sub);
  Myremove_matrix(&res_exmpl);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t matrix_1, matrix_2, res_sub, res_exmpl;
  Mycreate_matrix(8, 2, &matrix_1);
  Mycreate_matrix(2, 8, &matrix_2);
  Mycreate_matrix(4, 4, &res_exmpl);
  for (int i = 0; i < 16; i++) {
    matrix_1.matrix[i / 2][i % 2] = matrix_2.matrix[i / 8][i % 8] =
        (i * 1.) / 3.;
    res_exmpl.matrix[i / 4][i % 4] = ((3 * i * 1.) / 3.);
  }

  int error = Mysub_matrix(&matrix_1, &matrix_2, &res_sub);
  ck_assert_int_eq(error, 2);
  error = Myeq_matrix(&res_sub, &res_exmpl);
  ck_assert_int_eq(error, FAILURE);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
  // Myremove_matrix(&res_sub);
  Myremove_matrix(&res_exmpl);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t matrix_1, matrix_2, res_sub, res_exmpl;
  Mycreate_matrix(1, 1, &matrix_1);
  Mycreate_matrix(1, 1, &matrix_2);
  Mycreate_matrix(1, 1, &res_exmpl);
  for (int i = 0; i < 1; i++) {
    matrix_1.matrix[i / 1][i % 1] = 23.522;
    matrix_2.matrix[i / 1][i % 1] = 11.12;
    res_exmpl.matrix[i / 1][i % 1] = 23.522 - 11.12;
  }

  int error = Mysub_matrix(&matrix_1, &matrix_2, &res_sub);
  ck_assert_int_eq(error, 0);
  error = Myeq_matrix(&res_sub, &res_exmpl);
  ck_assert_int_eq(error, SUCCESS);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
  Myremove_matrix(&res_sub);
  Myremove_matrix(&res_exmpl);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t matrix_1, matrix_2, res_sub, res_exmpl;
  Mycreate_matrix(3, 3, &matrix_1);
  Mycreate_matrix(3, 3, &matrix_2);
  Mycreate_matrix(3, 3, &res_exmpl);
  for (int i = 0; i < 9; i++) {
    matrix_1.matrix[i / 3][i % 3] = matrix_2.matrix[i / 3][i % 3] = 2.66 + i;
    res_exmpl.matrix[i / 3][i % 3] = 2 * (2.66 + i);
  }

  int error = Mysub_matrix(&matrix_1, &matrix_2, &res_sub);
  ck_assert_int_eq(error, 0);
  error = Myeq_matrix(&res_sub, &res_exmpl);
  ck_assert_int_eq(error, FAILURE);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
  Myremove_matrix(&res_sub);
  Myremove_matrix(&res_exmpl);
}
END_TEST

START_TEST(sub_matrix_6) {
  matrix_t matrix_1, matrix_2, res_sub, res_exmpl;
  Mycreate_matrix(33, 23, &matrix_1);
  Mycreate_matrix(33, 23, &matrix_2);
  Mycreate_matrix(33, 23, &res_exmpl);
  for (int i = 0; i < 23 * 33; i++) {
    matrix_1.matrix[i / 23][i % 23] = 2.66 + i;
    matrix_2.matrix[i / 23][i % 23] = 2.66 + i;
    res_exmpl.matrix[i / 23][i % 23] = 0;
  }

  int error = Mysub_matrix(&matrix_1, &matrix_2, &res_sub);
  ck_assert_int_eq(error, 0);
  error = Myeq_matrix(&res_sub, &res_exmpl);
  ck_assert_int_eq(error, 1);
  Myremove_matrix(&matrix_1);
  Myremove_matrix(&matrix_2);
  Myremove_matrix(&res_sub);
  Myremove_matrix(&res_exmpl);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("Mysub_matrix");
  TCase *tc = tcase_create("sub_matrix");

  tcase_add_test(tc, sub_matrix_1);
  tcase_add_test(tc, sub_matrix_2);
  tcase_add_test(tc, sub_matrix_3);
  tcase_add_test(tc, sub_matrix_4);
  tcase_add_test(tc, sub_matrix_5);
  tcase_add_test(tc, sub_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}

// MULTNUMBER

START_TEST(mulN_0) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  matrix_t result;
  int rowA = 10, colA = 3;
  Mycreate_matrix(rowA, colA, &A);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) A.matrix[i][j] = 25;
  A.matrix[0][0] = -10;
  Mymult_number(&A, -3, &result);
  ck_assert_double_eq(result.matrix[0][0], 30);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (j + i > 0) ck_assert_double_eq(result.matrix[i][j], -75);
    }
  }
  Myremove_matrix(&A);
  Myremove_matrix(&result);
}
END_TEST

START_TEST(mulN_1) { ck_assert_int_eq(Mymult_number(NULL, 0, NULL), 1); }
END_TEST

START_TEST(mulN_2) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Mymult_number(&A, 0, NULL), 1);
}
END_TEST

START_TEST(mulN_3) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Mymult_number(&A, 0, &B), 1);
}
END_TEST

START_TEST(mulN_4) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  ck_assert_int_eq(Mymult_number(&A, 0, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(mulN_5) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  ck_assert_int_eq(Mymult_number(&A, 0, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(mulN_6) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  Mycreate_matrix(3, 2, &A);
  ck_assert_int_eq(Mymult_number(&A, 0, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

Suite *test_mult_number_matrix(void) {
  Suite *s = suite_create("suite_mulN");
  TCase *tc = tcase_create("Mymult_numb");
  tcase_add_test(tc, mulN_0);
  tcase_add_test(tc, mulN_1);
  tcase_add_test(tc, mulN_2);
  tcase_add_test(tc, mulN_3);
  tcase_add_test(tc, mulN_4);
  tcase_add_test(tc, mulN_5);
  tcase_add_test(tc, mulN_6);
  suite_add_tcase(s, tc);
  return s;
}
// MM

END_TEST

START_TEST(mulM_1) { ck_assert_int_eq(Mymult_matrix(NULL, NULL, NULL), 1); }
END_TEST

START_TEST(mulM_2) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Mymult_matrix(&A, NULL, NULL), 1);
}
END_TEST

START_TEST(mulM_3) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  ck_assert_int_eq(Mymult_matrix(&A, &B, &r), 1);
}
END_TEST

START_TEST(mulM_4) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(1, 20, &A);
  Mycreate_matrix(2, 3, &B);
  ck_assert_int_eq(Mymult_matrix(&A, &B, &r), 2);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(mulM_5) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  ck_assert_int_eq(Mymult_matrix(&A, &B, &r), 1);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(mulM_6) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(3, 2, &A);
  Mycreate_matrix(1, 4, &B);
  ck_assert_int_eq(Mymult_matrix(&A, &B, &r), 2);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(mulM_7) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  Mycreate_matrix(2, 2, &B);
  ck_assert_int_eq(Mymult_matrix(&A, &B, &r), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
  Myremove_matrix(&r);
}
END_TEST

START_TEST(mulM_8) {
  matrix_t A, B, r;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(3, 2, &A);
  Mycreate_matrix(2, 2, &B);
  B.columns = 0;
  ck_assert_int_eq(Mymult_matrix(&A, &B, &r), 1);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("suite_mulM");
  TCase *tc = tcase_create("Mymult_matrix");

  tcase_add_test(tc, mulM_1);
  tcase_add_test(tc, mulM_2);
  tcase_add_test(tc, mulM_3);
  tcase_add_test(tc, mulM_4);
  tcase_add_test(tc, mulM_5);
  tcase_add_test(tc, mulM_6);
  tcase_add_test(tc, mulM_7);
  tcase_add_test(tc, mulM_8);
  suite_add_tcase(s, tc);
  return s;
}
// transpose
START_TEST(transpose_0) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  matrix_t result;
  int rowA = 10, colA = 3;
  Mycreate_matrix(rowA, colA, &A);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) A.matrix[i][j] = 25;
  A.matrix[0][0] = -10;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 2;
  Mytranspose(&A, &result);
  ck_assert_double_eq(result.matrix[0][0], -10);
  ck_assert_double_eq(result.matrix[1][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 2);
  for (int i = 0; i < A.columns; i++) {
    for (int j = 0; j < A.rows; j++) {
      if (j + i > 1) ck_assert_double_eq(result.matrix[i][j], 25);
    }
  }
  Myremove_matrix(&A);
  Myremove_matrix(&result);
}
END_TEST

START_TEST(transpose_1) { ck_assert_int_eq(Mytranspose(NULL, NULL), 1); }
END_TEST

START_TEST(transpose_2) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Mytranspose(&A, NULL), 1);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Mytranspose(&A, &B), 1);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(2, 2, &A);
  ck_assert_int_eq(Mytranspose(&A, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(transpose_5) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  Mycreate_matrix(2, 3, &A);
  ck_assert_int_eq(Mytranspose(&A, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

START_TEST(transpose_6) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  Mycreate_matrix(3, 2, &A);
  ck_assert_int_eq(Mytranspose(&A, &B), 0);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
}
END_TEST

Suite *test_transpose_matrix(void) {
  Suite *s = suite_create("suite_transpose");
  TCase *tc = tcase_create("case_transpose");
  tcase_add_test(tc, transpose_0);
  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);
  tcase_add_test(tc, transpose_5);
  tcase_add_test(tc, transpose_6);
  suite_add_tcase(s, tc);
  return s;
}
// calc complem
START_TEST(complements_0) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  matrix_t result;
  int rowA = 3, colA = 3;
  Mycreate_matrix(rowA, colA, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  Mycalc_complements(&A, &result);
  ck_assert_double_eq(result.matrix[0][0], 0);
  ck_assert_double_eq(result.matrix[0][1], 10);
  ck_assert_double_eq(result.matrix[0][2], -20);
  ck_assert_double_eq(result.matrix[1][0], 4);
  ck_assert_double_eq(result.matrix[1][1], -14);
  ck_assert_double_eq(result.matrix[1][2], 8);
  ck_assert_double_eq(result.matrix[2][0], -8);
  ck_assert_double_eq(result.matrix[2][1], -2);
  ck_assert_double_eq(result.matrix[2][2], 4);
  Myremove_matrix(&A);
  Myremove_matrix(&result);
}
END_TEST

START_TEST(complements_1) {
  ck_assert_int_eq(Mycalc_complements(NULL, NULL), 1);
}
END_TEST

START_TEST(complements_2) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(Mycalc_complements(NULL, &A), 1);
}
END_TEST

START_TEST(complements_3) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  ck_assert_int_eq(Mycalc_complements(&A, &B), 1);
}
END_TEST

Suite *test_calc_complements_matrix(void) {
  Suite *s = suite_create("suite_complements");
  TCase *tc = tcase_create("case_complements");
  tcase_add_test(tc, complements_0);
  tcase_add_test(tc, complements_1);
  tcase_add_test(tc, complements_2);
  tcase_add_test(tc, complements_3);
  suite_add_tcase(s, tc);
  return s;
}

// det
START_TEST(determinant_0) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  int rowA = 3, colA = 3, t = 1;
  double det = 0;
  Mycreate_matrix(rowA, colA, &A);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) A.matrix[i][j] = t++;
  Mydeterminant(&A, &det);
  Myremove_matrix(&A);
  ck_assert_double_eq(det, 0);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  int rowA = 6, colA = 6;
  double det = 0;
  Mycreate_matrix(rowA, colA, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 1;
  A.matrix[0][4] = 1;
  A.matrix[0][5] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;
  A.matrix[1][4] = 0;
  A.matrix[1][5] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 1;
  A.matrix[2][4] = 1;
  A.matrix[2][5] = 1;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 1;
  A.matrix[3][3] = 1;
  A.matrix[3][4] = 0;
  A.matrix[3][5] = 1;
  A.matrix[4][0] = 0;
  A.matrix[4][1] = 1;
  A.matrix[4][2] = 0;
  A.matrix[4][3] = 1;
  A.matrix[4][4] = 0;
  A.matrix[4][5] = 0;
  A.matrix[5][0] = 0;
  A.matrix[5][1] = 0;
  A.matrix[5][2] = 1;
  A.matrix[5][3] = 0;
  A.matrix[5][4] = 0;
  A.matrix[5][5] = 0;
  Mydeterminant(&A, &det);
  Myremove_matrix(&A);
  ck_assert_double_eq(det, 0);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  int rowA = 4, colA = 4;
  double det = 0;
  Mycreate_matrix(rowA, colA, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 2;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 1;
  A.matrix[3][3] = 1;
  Mydeterminant(&A, &det);
  Myremove_matrix(&A);
  ck_assert_int_eq(fabs(det + 2) < 1e-7, 1);
}
END_TEST

Suite *test_determinant_matrix(void) {
  Suite *s = suite_create("suite_determinant");
  TCase *tc = tcase_create("case_determinant");
  tcase_add_test(tc, determinant_0);
  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  suite_add_tcase(s, tc);
  return s;
}

// case1
START_TEST(case3) {
  matrix_t A, B, C;
  Mycreate_matrix(3, 3, &A);
  Mycreate_matrix(3, 3, &C);
  C.matrix[0][0] = 44300.0 / 367429.0;
  C.matrix[0][1] = -236300.0 / 367429.0;
  C.matrix[0][2] = 200360.0 / 367429.0;
  C.matrix[1][0] = 20600.0 / 367429.0;
  C.matrix[1][1] = 56000.0 / 367429.0;
  C.matrix[1][2] = -156483.0 / 367429.0;
  C.matrix[2][0] = 30900.0 / 367429.0;
  C.matrix[2][1] = 84000.0 / 367429.0;
  C.matrix[2][2] = -51010.0 / 367429.0;
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  Myinverse_matrix(&A, &B);
  int res = Myeq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
  Myremove_matrix(&C);
}

END_TEST

START_TEST(case2) {
  matrix_t A, C;
  Mycreate_matrix(3, 3, &A);
  Mycreate_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  Myinverse_matrix(&A, &B);
  int res = Myeq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  Myremove_matrix(&A);
  Myremove_matrix(&B);
  Myremove_matrix(&C);
}
END_TEST

START_TEST(case6) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = Mycreate_matrix(1, 1, &m);
  if (!codec) {
    int code = Myinverse_matrix(&m, &result);
    ck_assert_int_eq(code, 2);
    Myremove_matrix(&m);
  }
}
END_TEST

START_TEST(case7) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = Myinverse_matrix(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(case5) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = Mycreate_matrix(1, 4, &m);
  if (!codec) {
    int code = Myinverse_matrix(&m, &result);
    ck_assert_int_eq(code, 2);
    Myremove_matrix(&m);
  }
}
END_TEST

START_TEST(case4) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = Mycreate_matrix(3, 3, &m);
  if (!codec1) codec2 = Mycreate_matrix(3, 3, &expected);

  if (!codec1 && !codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = Myinverse_matrix(&m, &result);

    ck_assert_int_eq(Myeq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, 0);

    Myremove_matrix(&m);
    Myremove_matrix(&result);
    Myremove_matrix(&expected);
  }
}
END_TEST

START_TEST(case1) {
  /* const int size = rand() % 100 + 1; */
  const int size = 3;
  matrix_t m = {0};
  Mycreate_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  Myinverse_matrix(&m, &res);

  matrix_t expected = {0};
  Mycreate_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(Myeq_matrix(&expected, &res), SUCCESS);

  Myremove_matrix(&expected);
  Myremove_matrix(&res);
  Myremove_matrix(&m);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("suite_Mycase1_matrix");
  TCase *tc = tcase_create("test_inverse_matrix");

  tcase_add_test(tc, case1);
  tcase_add_test(tc, case2);
  tcase_add_test(tc, case3);

  tcase_add_test(tc, case4);
  tcase_add_test(tc, case5);
  tcase_add_test(tc, case6);
  tcase_add_test(tc, case7);

  suite_add_tcase(s, tc);
  return s;
}
int main(void) {
  int failed = 0;
  Suite *Mymatrix_test[] = {test_create_matrix(),
                              test_eq_matrix(),
                              test_sum_matrix(),
                              test_sub_matrix(),
                              test_mult_number_matrix(),
                              test_mult_matrix(),
                              test_transpose_matrix(),
                              test_calc_complements_matrix(),
                              test_determinant_matrix(),
                              test_inverse_matrix(),
                              NULL

  };

  for (int i = 0; Mymatrix_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(Mymatrix_test[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);

    if (failed == 0)
      printf(GREEN "Success\n" WHITE);
    else
      printf(RED "Failed\n" WHITE);

    failed = 0;
  }

  return 0;
}