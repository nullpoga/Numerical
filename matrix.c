/* matrix.c */
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void init_matrix(Matrix* mat, int cp_row, int cp_col)
{
	int i, j;

	mat->row = cp_row;
	mat->col = cp_col;

	for(i = 0; i  < (mat->row); i++){
		for(j = 0; j  < (mat->col); j++){		
			mat -> data[i][j] = 0;
		}
	}

}

void print_matrix(Matrix* mat)
{
	int i, j;

	for(i = 0; i  < (mat->row); i++){
		for(j = 0; j  < (mat->col); j++){		
			printf("%5.3lf ",mat -> data[i][j]);
		}
		puts("");
	}
	puts("");
}

void multi_matrix(Matrix* mat1, Matrix *mat2, Matrix *answer_mat)
{
	int i, j, k;	
	
	for(i = 0; i < (mat1 -> row); i++){
		for(j = 0; j < (mat2 -> col); j++){
			answer_mat -> data[i][j] = 0;
			for(k = 0; k < (mat1 -> col); k++){
				(answer_mat -> data[i][j]) += (mat1-> data[i][k] * mat2-> data[k][j]);
			}
		}
	}
}

void multi_to_term(Matrix* mat1, Matrix * to_mat, double value)
{
	int i;

	for(i = 0; i < mat1 -> row; i++){
		(to_mat -> data[i][0]) = (value * (mat1 -> data[i][0]));
	}

}

double calc_eigenvalue(Matrix* mat1, Matrix *mat2)
{
	int i, j;
	double answer_mat = 0.0;

	for(i = 0; i < (mat1 -> col); i++){
		for(j = 0; j < (mat2 -> row); j++){
			answer_mat += (mat1 -> data[i][j])*(mat2 -> data[j][i]);
		}
	}

	return answer_mat;
}

void transpose_matrix(Matrix* mat1, Matrix *ans_mat)
{
	int i, j;

	for(i = 0; i < (mat1 -> row); i++){
		for(j = 0; j < (mat1 -> col); j++){
			(ans_mat->data[j][i]) = (mat1->data[i][j]);
		}
	}

}

 
