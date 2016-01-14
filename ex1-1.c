#include <stdio.h>
#include <stdlib.h>
#include "jordan.h"

int main(void)
{
	int eq_unkwons = 0;
	double q_mat[N][N];
	double answer[N];

	jordan_main(eq_unkwons, q_mat, answer);

	return 0;
}


