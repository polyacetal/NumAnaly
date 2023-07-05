#include<stdio.h>
#include<math.h>
#define N 5

int main(void)
{
	double a[N][N] = {
		{-1, -1, -2, -1, 10},
		{-1, -2, -1, 10, -1},
		{-2, -1, 10, -1, -1},
		{-1, 10, -1, -1, -2},
		{10, -1, -1, -2, -1}
	};
	double pmax, buff;
	int p;

	for(int k=0; k < N-1; k++)
	{
		p = k;
		pmax = fabs(a[k][k]);
		for(int i=k+1; i < N; i++)
		{
			if(fabs(a[i][k]) > pmax) {
				p = i;
				pmax = fabs(a[i][k]);
			}
		}
		if(p != k) {
			for(int i=0; i < N; i++) {
				buff = a[k][i];
				a[k][i] = a[p][i];
				a[p][i] = buff;
			}
		}
	}
	for(int i=0; i < N; i++)
	{
		printf("| ");
		for(int j=0; j < N; j++)
		{
			printf("%4.2lf ", a[i][j]);
		}
		printf("|\n");
	}
	return 0;
}
