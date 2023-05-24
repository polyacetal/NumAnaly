#include<stdio.h>
#include<math.h>

const int N = 100;         /* 分割数     */
const double T0 = 0.0;     /* 初期時刻(s)   */
const double TN = 1.0;     /* 終了時刻(s)   */
const double X0 = 1.0;     /* 重力加速度(m/s^2) */

double exact(double t)
{
	return exp(t);
}

double f(double x, double t)
{
	return x;
}

double rk(double x, double t, double dt)
{
	double x1, x2, x3;
	double k1, k2, k3, k4;

	k1 = f(x, t); 		/* 現時点における傾きを計算 */
	x1 = x + k1 * dt / 2.0; /* その傾きを使って中点における状態を計算 */
	k2 = f(x1, t + dt / 2.0); 		/* 中点における傾きを計算 */
	x2 = x + k2 * dt / 2.0; /* その傾きを使って中点における状態を再計算 */
	k3 = f(x2, t + dt / 2.0); 		/* 再計算した中点における傾きを計算 */
	x3 = x + k3 * dt;      	/* その傾きを使って次の時点の状態を計算 */
	k4 = f(x3, t + dt);    	/* 次の時点の状態における傾きを計算 */
	
	return (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0 * dt; /* シンプソン則による増分 */
}

int main(void)
{
	int i;
	double t, x, dt;

	dt = (TN - T0) / N;
	x = X0;
	for(i = 0; i <= N; i++){
		t = T0 + dt * i;
		printf("%f %.15f %e\n", t, x, fabs(x - exact(t))); /* 現在の時刻と状態 */
		x = x + rk(x, t, dt); /* Runge-Kutta 法で計算した増分を使って x を更新する */
	}

	return(0);
}
