#include <stdio.h>
#include <math.h>

const int N = 100;
const int T0 = 0.0;
const int TN = 1.0;
const int X0 = 1.0;

double exact(double t)
{
	return(exp(t));
}

double f(double x, double t)
{
	return(x);
}

double euler(double x, double t, double dt)
{
	return(f(x, t) * dt);
}

int main(void)
{
	int i;
	double t, x, dt;

	dt = (TN - T0) / (double)N;
	x = X0;
	for(i = 0; i <= N; i++)
	{
		t = T0 + dt * i;
		printf("%f %.15f %e\n", t, x, fabs(x - exact(t)));
		x = x + euler(x, t, dt);
	}

	return 0;
}

