#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

const double EPS = 1.0e-10; /* 収束判定値 */

double func(double) ;	/* 関数のプロトタイプ宣言 */

int main(void) 
{
	double x1, x2, x3;
	int i = 0;			/* 整数型宣言とiの初期値設定 */ 

	printf("Lower limit = "); scanf("%lf", &x1); /* 初期値下限値の入力 */ 
	printf("Upper limit = "); scanf("%lf", &x2); /* 初期値上限値の入力 */ 
	if( func(x1) * func(x2) >= 0 || x1 >= x2) {
		printf("初期値が不適当です。\n");
		return(-1);		/* プロセスの強制終了 */
	}

	do{
		i++;
		x3 = (x1 + x2) / 2.0;
		if(func(x1) * func(x3) < 0.0)
		{
			x2 = x3;
		}else{
			x1 = x3;
		}
	}while(fabs(x2-x1) > EPS); /* 条件を満たす間繰り返す */ 
	printf("Iteration=%d x= %.10lf\n", i, x3); /* 結果の表示 */ 
	return(0); 
} 

double func(double x) 
{
	return(x * x * x + 2); /* 関数値を計算しメインに返す */ 
}
