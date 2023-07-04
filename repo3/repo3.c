#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define NMAX 100   /*　繰り返しの最大値　　*/
const double EPS = 1.0e-12; /* 収束判定値 */
const double ANS = pow(10, 1.0/3.0);	/* 真値 */

double func(double) ;	/* 関数のプロトタイプ宣言 */
double dfunc(double);  /* 関数プロトタイプ */
void split(double, double);
void newton(double);

int main(void)
{
	printf("split : \n");
	split(2,3);
	printf("\n");
	printf("newton : \n");
	newton(2.5);
	return 0;
}

void split(double x1, double x2) 
{
	double x3;
	int i = 0;			/* 整数型宣言とiの初期値設定 */ 

	do{
		i++;
		x3 = (x1 + x2) / 2.0;
		if(func(x1) * func(x3) < 0.0)
		{
			x2 = x3;
		}else{
			x1 = x3;
		}
		printf("%d , %.12lf\n", i, fabs(x3 - ANS));
	}while(fabs(x2-x1) > EPS); /* 条件を満たす間繰り返す */ 
} 

void newton(double x0)
{
	double dx;
	int i = 0;

	do{
		i++;
		dx = func(x0) / dfunc(x0);
		x0 = x0 - dx;
		
		if(i > NMAX){  /* NMAX 回繰り返しても収束しなかった． */
			printf("Not Convergence");
			break;
		}
		printf("%d , %.12lf\n", i, fabs(x0 - ANS));
	}while(fabs(dx) > EPS);      /* 解が得られるまでの繰り返し */
}

double func(double x) 
{
	return(x * x * x - 10); /* 関数値を計算しメインに返す */ 
}

double dfunc(double x)  /* その導関数 f'(x)の設定 */
{
	return(2 * x * x);
}
