#include<stdio.h>
#include<stdlib.h>

double *jacobi(int rank,double augmentedmatrix[rank][rank+1],double accuracy) {
	double *solutionvectornew = (double *)malloc(rank * sizeof(double));
	double *solutionvectorold = (double *)malloc(rank * sizeof(double));
	int i = 1, j, k = 1, check;
	do
		solutionvectornew[i-1] = 0;
	while(++i <= rank);
	printf("JACOBI METHOD:\n\n");
	do {
		check = 0;
		i = 1;
		do
			solutionvectorold[i-1] = solutionvectornew[i-1];
		while(++i <= rank);
		i = 1;
		printf("%02d\t", k++);
		do {
			solutionvectornew[i-1] = augmentedmatrix[i-1][rank];
			j = 1;
			do
				if(i != j)
					solutionvectornew[i-1] -= augmentedmatrix[i-1][j-1] * solutionvectorold[j-1];
			while(++j <= rank);
			solutionvectornew[i-1] /= augmentedmatrix[i-1][i-1];
			check |= abslt(solutionvectornew[i-1] - solutionvectorold[i-1]) > accuracy;
			printf("%+09g\t",solutionvectornew[i-1]);
		} while(++i <= rank);
		printf("\n");
	} while(check);
	free(solutionvectorold);
	return solutionvectornew;
}


int main(void) {
	double jacobionly[3][4] = {{5, 1, -1, 10},{2, 8, -1, 11},{-1, 1, 4, 3}};
	jacobi(3,jacobionly,0.0001);
}


