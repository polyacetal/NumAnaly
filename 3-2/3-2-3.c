#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 100   /*　繰り返しの最大値　　*/

double FUNC(double);  /* 関数プロトタイプ */
double dFUNC(double);  /* 関数プロトタイプ */

int main(void)
{
	double x0, dx, eps;
	int icount = 0;

	/* 各設定値の読み込み */
	printf("解の初期推定値 = ");
	scanf("%lf",&x0);
	printf("収束条件に使用する微少数 = ");
	scanf("%lf",&eps);

	do{
		icount++;
		dx = FUNC(x0) / dFUNC(x0);
		x0 = x0 - dx;
		
		if(icount > NMAX){  /* NMAX 回繰り返しても収束しなかった． */
			printf("Not Convergence");
			break;
		}
	}while(fabs(dx) > eps);      /* 解が得られるまでの繰り返し */

	printf("Iterations = %d  ", icount);
	printf("x = %.16e  eps = %.16e  dx = %.16e  ", x0, eps, dx);

	return(0);
}

double FUNC(double x)  /* 関数 f(x)の設定 */
{
	return(log(x) + exp(x));
}

double dFUNC(double x)  /* その導関数 f'(x)の設定 */
{
	return(1/x + exp(x));
}
