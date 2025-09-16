
#ifndef MTX_HEADER
#define MTX_HEADER

typedef struct Matrix_ {
  int rows;
  int cols;
  int *data;
} Matrix;

Matrix mtx_new(int row, int cols);

int mtx_get(Matrix *matrix, int i, int j);

void mtx_set(Matrix *matrix, int i, int j, int val);

void mtx_free(Matrix *matrix);

#endif
