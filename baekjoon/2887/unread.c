#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100000

int plan[MAX][4];

int com_x(const void*, const void*);
int com_y(const void*, const void*);
int com_z(const void*, const void*);

int cal_dis(int, int);

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", plan[i] + 0, plan[i] + 1, plan[i] + 2);
		plan[i][3] = INT_MAX;
	}

	qsort(plan, n, sizeof(plan[0]), com_x);
	cal_dis(n - 1, 0);
	qsort(plan, n, sizeof(plan[0]), com_y);
	cal_dis(n - 1, 1);
	qsort(plan, n, sizeof(plan[0]), com_z);
	cal_dis(n - 1, 2);

	long long sum = 0;

	for (int i = 0; i < n; ++i)
		sum += plan[i][3];

	printf("%lld\n", sum);

	return 0;
}

int com_x(const void* x, const void* y)
{
	int* a = (int*)x;
	int* b = (int*)y;

	if (a[0] > b[0])
		return 1;
	if (a[0] == b[0])
		return 0;
	else
		return -1;

}

int com_y(const void* x, const void* y)
{
	int* a = (int*)x;
	int* b = (int*)y;

	if (a[1] > b[1])
		return 1;
	if (a[1] == b[1])
		return 0;
	else
		return -1;

}

int com_z(const void* x, const void* y)
{
	int* a = (int*)x;
	int* b = (int*)y;

	if (a[2] > b[2])
		return 1;
	if (a[2] == b[2])
		return 0;
	else
		return -1;

}

int cal_dis(int end, int col)
{
	if (plan[1][col] - plan[0][col] < plan[0][3])
		plan[0][3] = plan[1][col] - plan[0][col];

	for (int i = 1; i < end; ++i)
	{
		int temp = 0;
		if (plan[i][col] - plan[i - 1][col] > plan[i + 1][col] - plan[i][col])
			temp = plan[i + 1][col] - plan[i][col];
		else
			temp = plan[i][col] - plan[i - 1][col];


		if (plan[i][3] > temp)
			plan[i][3] = temp;
	}

	if (plan[end][col] - plan[end - 1][col] < plan[end][3])
		plan[end][3] = plan[end][col] - plan[end - 1][col];
}
