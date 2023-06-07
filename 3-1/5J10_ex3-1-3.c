#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

const double EPS = 1.0e-10; /* 収束判定値 */

double func( double ) ;	/* 関数のプロトタイプ宣言 */

int main(void) 
{
	double 			;
	int 	;			/* 整数型宣言とiの初期値設定 */ 

	printf("Lower limit = "); scanf(		); /* 初期値下限値の入力 */ 
	printf("Upper limit = "); scanf(		); /* 初期値上限値の入力 */ 
	if( func(x1) * func(x2) >=     ||    >=   ) {
		printf("初期値が不適当です。\n");
				;		/* プロセスの強制終了 */
	}

	do{
		/* 前問と同じ，省略 */

	}while( 		); /* 条件を満たす間繰り返す */ 
	printf("Iteration=%d x= %.10lf\n", i, x3); /* 結果の表示 */ 
	return(0); 
} 

double func(double x) 
{
	return( 		 ); /* 関数値を計算しメインに返す */ 
}