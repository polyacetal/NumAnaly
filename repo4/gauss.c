#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 5

int main(void)
{
	//与式の定義
	double a[N][N] = {
		{1, 0.3, 0.5, 0.7, 0.2},
		{0.8, 1, 0.4, -0.5, 0.3},
		{0.2, -0.5, 1, 0.6, 0.7},
		{0.1, 0.9, 0.3, 1, -0.4},
		{0.4, 0.2, 0.6, -0.8, 1}
	};
	double b[N] = {0.95, 0.80, 0.67, 0.70, 0.60};
	double x[N] = {};
	double expansion[N][N+1] = {0};	//拡大係数行列

	//拡大係数行列の作成
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			expansion[i][j] = a[i][j];
		}
		expansion[i][5] = b[i];
	}

	//変数の定義
	double mag, pmax, buff;
	double sum_ax;
	int p;

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

	//Gaussの消去法
	for(int k=0; k < N-1; k++)
	{

		//ピボットを確認して値の入れ替え
		if(expansion[k][k] == 0){
			p = k;
			pmax = fabs(expansion[k][k]);
			for(int i=k+1; i < N; i++)
			{
				if(fabs(expansion[i][k]) > pmax){
					p = i;
					pmax = fabs(expansion[i][k]);
				}
			}
			if(fabs(pmax) <1.0e-12){
			fprintf(stderr, "too small pivot!\n");
			exit(1);
			}
			if(p != k){
				for(int i=0; i < N+1; i++)
				{
					buff = expansion[p][i];
					expansion[p][i] = expansion[k][i];
					expansion[k][i] = buff;
				}
			}
		}

		for(int i=k+1; i < N; i++)
		{
			mag = expansion[i][k] /expansion[k][k];
			expansion[i][k] = 0.0;
			for(int j=k+1; j < N+1; j++)
			{
				expansion[i][j] = expansion[i][j] - expansion[k][j]*mag;
			}
		}
	}

	//後退代入
	for(int k=N-1; k >=0; k--)
	{
		sum_ax = 0.0;
		for(int j=N-1; j>k; j--)
		{
			sum_ax += expansion[k][j] * x[j];
		}
		x[k] = (expansion[k][N] - sum_ax) / expansion[k][k];
	}

	//解の表示
	for(int i=0; i<N; i++)
	{
		printf("x[i] : %lf\n", x[i]);
	}

	return 0;
}
