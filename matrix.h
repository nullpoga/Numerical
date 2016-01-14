/* matrix.h */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#define ARY_SIZE 10

typedef struct {
	int row; //行方向
	int col; //列方向
	double data[ARY_SIZE][ARY_SIZE];
}Matrix;

void init_matrix(Matrix *, int, int);
void print_matrix(Matrix *);
void multi_matrix(Matrix *, Matrix *, Matrix *);	
void transpose_matrix(Matrix *, Matrix *);
double calc_eigenvalue(Matrix *, Matrix *);
void multi_to_term(Matrix *, Matrix *, double);

#endif // _MATRIX_H_

