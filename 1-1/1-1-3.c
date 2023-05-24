#include<stdio.h>

/* 関数のプロトタイプ宣言 */
double menseki(double, double, double);
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

	/* 積算値 ans の初期化 */
	ans = 0;

	/* 繰り返し計算で面積を積算 */
	for(int i = 0;i < n;i++){
		ans+= menseki(h, func(x1 + h * i), func(x1 + h * (i+1)));
	}

	printf("Answer = %lf\n", ans);
	return (0);
}

double menseki(double h, double f1, double f2){
	return (f1 + f2) * h / 2.0;
}

double func(double x){
	return x * x + 2;
}
