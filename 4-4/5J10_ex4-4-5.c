#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 5
#define EPS 1.0e-6
#define IMAX 100

int main(void)
{
	//与式の定義
	double a[N][N] = {
		{2, -1, 0, 0, 0},
		{-1, 2, -1, 0, 0},
		{0, -1, 2, -1, 0},
		{0, 0, -1, 2, -1},
		{0, 0, 0, -1, 2}
	};
	double b[N] = {1, 0, 0, 0, 0};
	double x[N] = {};
	double x_tmp[N] = {};
	double expansion[N][N+1] = {0};	//拡大係数行列

	//拡大係数行列の作成
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			expansion[i][j] = a[i][j];
		}
		expansion[i][N] = b[i];
	}

	//変数の定義
	double tmp, err;
	int k;

	//拡大係数行列の表示
	for(int i=0; i < N; i++)
	{
		printf("{ ");
		for(int j=0; j < N; j++)
		{
			printf("%lf ", expansion[i][j]);
		}
		printf("| %lf }\n", expansion[i][5]);
	}

	//反復法
	k = 0;
	do{
		err = 0;
		printf("%3d:\n",k);

		for(int i = 0; i < N; i++)
		{
			x_tmp[i] = b[i];
			for(int j = 0; j < i; j++)
			{
				x_tmp[i] -= a[i][j] * x_tmp[j];
			}
			for(int j = i + 1; j < N; j++)
			{
				x_tmp[i] -= a[i][j] * x[j];
			}
			x_tmp[i] /= a[i][i];
		}

		for(int i = 0; i < N; i++)
		{
			err += fabs(x[i] - x_tmp[i]);
		}

		for(int i = 0; i < N; i++) x[i] = x_tmp[i];

		k++;
	}while((err > EPS) && (k < IMAX));

	//拡大係数行列の表示
	for(int i=0; i < N; i++)
	{
		printf("{ ");
		for(int j=0; j < N; j++)
		{
			printf("%lf ", expansion[i][j]);
		}
		printf("| %lf }\n", expansion[i][5]);
	}

	//解の表示
	for(int i=0; i<N; i++)
	{
		printf("x[%d] : %lf\n", i+1, x[i]);
	}

	return 0;
}
