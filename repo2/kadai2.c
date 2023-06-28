#include <stdio.h>
#include <math.h>

const double T0 = 0.0;
const double DT = 0.02;
const double V0 = 10.0;
const double G = 9.880665;
const double C = 0.005;
const double M = 2.0;

double exact(double t)
{
	return(-sqrt(G/C) * tan(sqrt(C*G)*t-atan(V0*sqrt(C/G))));
}

double f(double v, double t)
{
	return(G+C*v*v);
}

double euler(double v, double t, double dt)
{
	return(f(v, t) * dt);
}

double rf(double t, double x, double v)
{
	return v;
}

double rg(double t, double x, double v)
{
	return(-G -C * v * v);
}

void rk4(double t, double x, double v, double dt, double *dx, double *dv )
{
	double x1, x2, x3;
	double kx1, kx2, kx3, kx4;
	double v1, v2, v3;
	double kv1, kv2, kv3, kv4;

	kx1 = rf(t, x, v);
	kv1 = rg(t, x, v);
	x1 = x + kx1 * dt / 2.0;
	v1 = v + kv1 * dt / 2.0;
	kx2 = rf(t + dt / 2.0, x1, v1);
	kv2 = rg(t + dt / 2.0, x1, v1);
	x2 = x + kx2 * dt / 2.0;
	v2 = v + kv2 * dt / 2.0;
	kx3 = rf(t + dt / 2.0, x2, v2);
	kv3 = rg(t + dt / 2.0, x2, v2);
	x3 = x + kx3 * dt;
	v3 = v + kv3 * dt;
	kx4 = rf(t + dt, x3, v3 );
	kv4 = rg(t + dt, x3, v3 );
	*dx = (kx1 + 2.0 * kx2 + 2.0 * kx3 + kx4) / 6.0 * dt;
	*dv = (kv1 + 2.0 * kv2 + 2.0 * kv3 + kv4) / 6.0 * dt;
}

int main(void)
{
	int i = 0;
	double t, ev, rv, rx, dx, dv;

	ev = V0;
	rx = 0.0;
	rv = V0;
	dv = 0.0;
	dx = 0.0;
	do{
		t = T0 + DT * i;
		printf("%f %.15f %.15f %.15f\n", t, ev, rv, exact(t));
		ev = ev - euler(ev, t, DT);
		rk4(t, rx, rv, DT, &dx, &dv);
		rx += dx;
		rv += dv;
		i++;
	}while(ev > 0 && rv > 0);

	return 0;
}

