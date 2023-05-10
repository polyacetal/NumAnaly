#include <stdio.h>

/* 関数のプロトタイプ宣言 */
double func(double);

int main(void){
	double x1;
	double x2;
	int n;
	double h;
	double ans;

	printf("x1 = "); scanf("%lf", &x1);
	printf("x2 = "); scanf("%lf", &x2);
	printf("n  = "); scanf("%d", &n);

	/* 計算幅 h の算出 */
	h = (x2 - x1) / (double)n;

	/* 積算値 ansに両端の値f(x0)とf(xn)を積算 */
	ans = func(x1) + func(x2);
	/* f(x1)からf(xn-1)の積算 */
	for(int i = 1;i < n;i++){
										
		ans+= 2 * func(x1 + h * i);
	}
	ans *= h / 2.0;

	printf("Answer = %lf\n", ans);
	return (0);
}

double func(double x){
	return x * x + 2;
}
