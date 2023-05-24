#include<stdio.h>

const int N = 20;          /* 分割数     */
const double T0 = 0.0;     /* 初期時刻(s)   */
const double TN = 2.0;     /* 終了時刻(s)   */
const double G = 9.80665;  /* 重力加速度(m/s^2) */
const double M = 1.0;      /* 質量(kg) */
const double C = 0.01;     /* 抵抗力に関する定数（kg/s） */

double f(double t, double x, double v)
{
	return v;
}

double g(double t, double x, double v)
{
	return G - (C / M) * v * v;
}

void rk4(double t, double x, double v, double dt, double *dx, double *dv )
{
	double x1, x2, x3;
	double kx1, kx2, kx3, kx4;
	double v1, v2, v3;
	double kv1, kv2, kv3, kv4;

	kx1 = f(t, x, v); 		/* 現時点における傾きを計算 */
	kv1 = g(t, x, v); 		/* 現時点における傾きを計算 */
	x1 = x + kx1 * dt / 2.0; 	/* その傾きを使って中点における状態を計算 */
	v1 = v + kv1 * dt / 2.0; 	/* その傾きを使って中点における状態を計算 */
	kx2 = f(t + dt / 2.0, x1, v1); 		/* 中点における傾きを計算 */
	kv2 = g(t + dt / 2.0, x1, v1); 		/* 中点における傾きを計算 */
	x2 = x + kx2 * dt / 2.0; 	/* その傾きを使って中点における状態を再計算 */
	v2 = v + kv2 * dt / 2.0; 	/* その傾きを使って中点における状態を再計算 */
	kx3 = f(t + dt / 2.0, x2, v2); 		/* 再計算した中点における傾きを計算 */
	kv3 = g(t + dt / 2.0, x2, v2); 		/* 再計算した中点における傾きを計算 */
	x3 = x + kx3 * dt;      	/* その傾きを使って次の時点の状態を計算 */
	v3 = v + kv3 * dt;      	/* その傾きを使って次の時点の状態を計算 */
	kx4 = f(t + dt, x3, v3 );    	/* 次の時点の状態における傾きを計算 */
	kv4 = g(t + dt, x3, v3 );    	/* 次の時点の状態における傾きを計算 */
	*dx = (kx1 + 2.0 * kx2 + 2.0 * kx3 + kx4) / 6.0 * dt; /* シンプソン則による増分 */
	*dv = (kv1 + 2.0 * kv2 + 2.0 * kv3 + kv4) / 6.0 * dt; /* シンプソン則による増分 */
}


int main(void)
{
	int i;
	double t, x, v, dt;
	double dx = 0.0;  /* 変数xにおけるシンプソン則による増分 */
	double dv = 0.0;  /* 変数vにおけるシンプソン則による増分 */

	dt = (TN - T0) / (double)N;
	x = 0.0;
	v = 0.0;
	for(i = 0; i <= N; i++){
		t = T0 + dt * i;
		printf("%f %.15f %.15f\n", t, x, v);
		rk4( t, x, v, dt, &dx, &dv );
		x += dx;
		v += dv;
	}
	return(0);
}

