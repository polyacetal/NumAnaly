#include<stdio.h>

double simpson(double, double, double, double);
double func(double);

int main(void)
{
	double x1;
	double x2;
	int n;
	double h;
	double ans;

	printf("x1 = "); scanf("%lf", &x1);
	printf("x2 = "); scanf("%lf", &x2);
	while(1)
	{
		printf("n = "); scanf("%d", &n);
		if(n % 2 == 1)
		{
			printf("!! Bunkatsu su ha gu-su- desu !!\n");
		} else {
			break;
		}
	}
	h = (x2 - x1) / (double)n;
	ans = 0;

	for(int i = 0; i < n/2; i++)
	{
		ans += 4 * func(x1 + h * (i * 2 + 1));
		if(i > 0)
		{
			ans += 2 * func(x1 + h * i * 2);
		}
	}
	ans += func(x1) + func(x2);
	ans *= h / 3.0;
	printf("Anser = %lf\n", ans);
	return(0);
}

double func(double x)
{
	return x * x + 2;
}
