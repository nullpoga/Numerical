#ifndef _JORDAN_H_
#define _JORDAN_H_

#define N 10

void print_matrix(int, double[][N]);
void print_result(int, double[]);
int load_filedata(char *, double[][N], int *);
void get_filename(char *);
void input_matrix(int *, double[][N]);
int calc_jordan(int, double[][N], double[]);
void jordan_main(int, double[][N], double[]);


#endif // _JORDAN_H_
