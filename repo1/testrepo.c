#include <stdio.h>
#include <math.h>
double trapezoid(double, double, int);
double simpson(double, double, int);
double func(double x);


int main(void)
{
	double tra, sim;
	for(int n = 8; n <= 128; n *= 2)
	{
		tra = trapezoid(0, 10, n);
		sim = simpson(0, 10, n);
		printf("%3d %10.10f %10.10f %10.10e %10.10f %10.10e\n", n, (10/(double)n), tra, fabs(tra - M_PI ), sim, fabs(sim - M_PI));
	}
	return(0);
}


double trapezoid(double x1, double x2, int n)
{
	double h;
	double ans;

	h = (x2 - x1) / (double)n;

	ans = func(x1) + func(x2);

	for(int i = 1; i < n; i++)
	{
		ans += 2 * func(x1 + h * i);
	}
	ans *= h / 2.0;

	return (ans);
}

double simpson(double x1, double x2, int n)
{
	double h;
	double ans;

	h = (x2 - x1) / (double)n;
	ans = func(x1) + func(x2);

	for(int i = 0; i < n/2; i++)
	{
		ans += 4 * func(x1 + h * (i * 2 + 1));
		if(i > 0){ans += 2 * func(x1 + h * i * 2);}
	}
	ans *= h / 3.0;
	return (ans);
}

double func(double x)
{
	return (40 / ((x * x) + (10 * 10)));
}
