#include <stdio.h>

#define N 10

void multi_matrix(double mat1[N][N], double mat2[N][N], double answer_mat[N][N], int count)
{
	int i, j;

	for(i = 0; i < count; i++){
		for(j = 0; j < count; j++){
			answer_mat[i][j] = mat1[i][j] * mat2[i][j];
		}
	}

}
