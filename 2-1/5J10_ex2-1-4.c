#include <stdio.h>

const int N = 20;
const double T0 = 0.0;
const double TN = 2.0;
const double G = 9.80665;
const double M = 1.0;
const double C = 0.01;

int main(void)
{
	int i;
	double t, x, v, dt;

	dt = (TN - T0) / (double)N;
	x = 0;
	v = 0;
	for(i = 0; i <= N; i++)
	{
		t = T0 + dt * i;
		printf("%f %f %f\n", t, x, v);
		x = x + v * dt;
		v = v + (G - (C*v*v/M)) * dt;
	}
	return (0);
}
