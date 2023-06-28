#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double T0 = 0.0;
const double DT = 0.02;
const double G = 9.880665;
const double C = 0.005;
const double M = 2.0;

double exact(double t, double v0)
{
	return(-sqrt(G/C) * tan(sqrt(C*G)*t-atan(v0*sqrt(C/G))));
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

void eFindV(const int v0, double *e40x)
{
	int i = 0;
	double t, ev;
	bool end = false;
	double eXbuff;

	ev = v0;
	while(1)
	{
		t = T0 + DT * i;
		ev = ev - euler(ev, t, DT);
		i++;
		if(end) break;
		if(ev > 0){
			eXbuff = ev * t + v0;
			end = true;
		}
	}
	(*e40x) = (double)((ev * t + v0) + eXbuff) / 2.0;
}

void rFindV(const int v0, double *r40x)
{
	int i = 0;
	double t, rv, rx, dx, dv;
	bool end = false;
	double rXbuff;

	rx = 0.0;
	rv = v0;
	dv = 0.0;
	dx = 0.0;
	while(1)
	{
		t = T0 + DT * i;
		rk4(t, rx, rv, DT, &dx, &dv);
		rx += dx;
		rv += dv;
		i++;
		if(end) break;
		if(rv > 0){
			rXbuff = rx;
			end = true;
		}
	}
	(*r40x) = (double)(rx + rXbuff) / 2.0;
}

int main(void)
{
	int i = 0;
	double v0 = 1.000;
	double e40x, r40x;

	while(1)
	{
		eFindV(v0, &e40x);
		if(e40x > 40){
			printf("euler\n");
			printf("%f %.15f\n", v0, e40x);
			break;
		}
		v0 += 0.001;
	}

	i = 0;
	v0 = 1.000;

	while(1)
	{
		rFindV(v0, &r40x);
		if(r40x > 40){
			printf("runge-kutta\n");
			printf("%f %.15f\n", v0, r40x);
			break;
		}
		v0 += 0.001;
	}
	return 0;
}
