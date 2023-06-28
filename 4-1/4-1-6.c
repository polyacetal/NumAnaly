#include<stdio.h>

int main(void)
{
	double a[3][3] = {
	{7.0, 6.0, 8.0},
	{5.0, 6.0, 5.0},
	{7.0, 9.0, 10.0}
	};
	double b[3][3] = {
		{1.0, 1.0, 1.0},
		{2.0, 2.0, 2.0},
		{3.0, 3.0, 3.0}
	};
	double ans[3][3] = {};
	double buff = 0;

	printf("| %3.1lf %3.1lf %3.1lf |   | %3.1lf %3.1lf %3.1lf |\n", a[0][0], a[0][1], a[0][2], b[0][0], b[0][1], b[0][2]);
	printf("| %3.1lf %3.1lf %3.1lf | * | %3.1lf %3.1lf %3.1lf |\n", a[1][0], a[1][1], a[1][2], b[1][0], b[1][1], b[1][2]);
	printf("| %3.1lf %3.1lf %3.1lf|   | %3.1lf %3.1lf %3.1lf |\n", a[2][0], a[2][1], a[2][2], b[2][0], b[2][1], b[2][2]);

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			buff = 0;
			for(int x = 0; x < 3; x++)
			{
				buff += a[i][x] * b[x][j];
			}
			ans[i][j] = buff;
		}
	}

	printf("\n");

	for(int i = 0; i < 3; i++)
	{
		printf("|");
		for(int j = 0; j < 3; j++)
		{
			printf(" %3.1lf ", ans[i][j]);
		}
		printf("|\n");
	}
}
