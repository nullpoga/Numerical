#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "load_file.h"
#include "matrix.h"

#define EPS 1e-8

int calc_power(Matrix *q_mat, Matrix *eigen_value, double *answer_lambda)
{
	int k = 0;
	double before_lambda, lambda, temp;
	Matrix eigen_vectors, transpose, temp_mat;
	lambda = 1.0; before_lambda = 0;

	init_matrix(&temp_mat, 1, 1); //1行1列の行列の初期化
	init_matrix(&eigen_vectors, 4, 1);
	init_matrix(&transpose, (eigen_value->col), (eigen_value->row));

	do{
		before_lambda = lambda;
		multi_matrix(q_mat, eigen_value, &eigen_vectors);

		transpose_matrix(eigen_value, &transpose);
		lambda = calc_eigenvalue(&transpose, &eigen_vectors);
		transpose_matrix(&eigen_vectors, &transpose);

		temp = 1.0 / sqrt( calc_eigenvalue(&transpose, &eigen_vectors) );
		temp_mat.data[0][0] = temp;

		multi_to_term(&eigen_vectors, eigen_value, temp);

		printf("lambda = %lf\n", lambda);
		print_matrix(eigen_value);

		k++;
	
	}while(!(fabs(lambda - before_lambda) < EPS));

	return 0;
}

int main(void)
{
	Matrix q_mat, eigen_value;
	Matrix *sp;
	double answer_lambda;

	sp = &q_mat;
	input_matrix(&(sp->row), &(sp->col), sp->data);
	sp = &eigen_value;
	input_matrix(&(sp->row), &(sp->col), sp->data);

	calc_power(&q_mat, &eigen_value, &answer_lambda);



	return 0;
}
