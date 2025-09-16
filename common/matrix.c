
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix mtx_new(int rows, int cols)
{
  int *data = (int*)malloc(rows * cols * sizeof(int));
  if (!data) {
    printf("could not allocate %d by %d matrix...", rows, cols);
    exit(1);
  }

  Matrix mat = {
    .rows = rows,
    .cols = cols,
    .data = data
  };
  return mat;
}

int mtx_get(Matrix *matrix, int i, int j)
{
  return matrix->data[i * matrix->cols + j];
}

void mtx_set(Matrix *matrix, int i, int j, int val)
{
  matrix->data[i * matrix->cols + j] = val;
}

void mtx_free(Matrix *matrix)
{
  free(matrix->data);
}
