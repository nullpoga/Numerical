#include <stdio.h>
#include <stdlib.h>

#define N 10

void print_matrix(int count, double mat[][N])
{
	int i, j;
	
	for(i = 0; i < count; i++){
		for(j = 0; j <= count; j++){
			if(j == count){
				printf(" %4.2lf \n", mat[i][j] );
			}else{
				printf(" %4.2lf", mat[i][j] );
			}
		}
	}

}

void print_result(int count, double answer[])
{
	int i;

	printf("count = %d\n", count);

	for(i = 0; i < count; i++){
		printf("answer[%d] = %4.2lf\n", count, answer[i]);
	}
}

int load_filedata(char *filename, double mat[][N], int *eq_unkwons)
{
	int i, j;
	int input_count;
	FILE *fp;

	if((fp = fopen(filename, "r")) == NULL){
		printf("file not found.\n");
		exit(EXIT_FAILURE);
	}

	//行数の読み込み
	fscanf(fp, "%d", eq_unkwons);
	input_count = *eq_unkwons;

	printf("input = %d\n", input_count);
	
	//ファイルから数字を読み込み
	for(i = 0; i < input_count; i++){
		for(j = 0; j <= input_count; j++){
			fscanf(fp, "%lf", &mat[i][j]);
		}
	}

	fclose(fp);

	return input_count;
}

void get_filename(char *filename)
{
	system("ls");
	printf("入力に使うファイルを入力してください:");
	scanf("%s", filename);
}

void input_matrix(int *eq_unkwons, double mat[][N])
{
	int input_count;
	char *filename;

	filename = (char *)malloc(100);

	get_filename(filename);
	input_count = load_filedata(filename, mat, eq_unkwons); //返り値は行数
	print_matrix(input_count, mat);

	free(filename);
}

int calc_jordan(int eq_unkwons,	double q_mat [N][N], double answer [N])
{
	int i, j, k;
	double mat_d;

	for(k = 0; k < eq_unkwons; k++){
		for(i = 0; i < eq_unkwons; i++){
			if(i != k){
				mat_d = (q_mat[i][k] / q_mat[k][k]);
				for(j = k; j < (eq_unkwons+1); j++){
					q_mat[i][j] = (q_mat[i][j] - q_mat[k][j] * mat_d);
				}
			}
		}
	}

	for(i = 0; i < eq_unkwons; i++){
		answer[i] = (q_mat[i][eq_unkwons] / q_mat[i][i]);

	}
		
	return 0;
}

void jordan_main(int eq_unkwons, double q_mat[][N], double answer[N])
{

	input_matrix(&eq_unkwons, q_mat);
	calc_jordan(eq_unkwons, q_mat, answer);
	print_result(eq_unkwons, answer);

}
