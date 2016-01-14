#include <stdio.h>
#include <stdlib.h>

#include "load_file.h"

void print_file_matrix(int *row_count, int *cal_count, double mat[][10])
{
	int i, j;
	
	for(i = 0; i < *row_count; i++){
		for(j = 0; j < *cal_count; j++){
				printf(" %5.3lf", mat[i][j] );
		}
		puts("");
	}

}

void load_filedata(char *filename, int *row_count, int *cal_count, double mat[][10])
{
	int i, j;
	FILE *fp;

	if((fp = fopen(filename, "r")) == NULL){
		printf("file not found.\n");
		exit(EXIT_FAILURE);
	}

	//行数・列の読み込み
	fscanf(fp, "%d", row_count);
	fscanf(fp, "%d", cal_count);

	printf("\n row = %d\n cal = %d\n", *row_count, *cal_count);
	
	//ファイルから数字を読み込み
	for(i = 0; i < *row_count; i++){
		for(j = 0; j < *cal_count; j++){
			fscanf(fp, "%lf", &mat[i][j]);
		}
	}

	fclose(fp);
}

void get_filename(char *filename)
{
	//system("ls");
	printf("入力に使うファイルを入力してください:");
	scanf("%s", filename);
}

void input_matrix(int *row_count, int *cal_count, double mat[][10])
{
	char *filename;

	filename = (char *)malloc(100);

	get_filename(filename);
	load_filedata(filename, row_count, cal_count, mat); 
	print_file_matrix(row_count, cal_count, mat);

	free(filename);
}

