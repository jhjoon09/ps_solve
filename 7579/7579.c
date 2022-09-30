#include <stdio.h>      
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define DATA 10000000

int byte_time[MAX][2];
int dp[DATA];
int N, M;
int min;

int compare(const void*, const void*);

int main(void)
{
	int pos = 0;
	min = INT_MAX;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		scanf("%d", byte_time[i] + 0);
	for (int i = 0; i < N; ++i)
		scanf("%d", byte_time[i] + 1);

	qsort(byte_time, N, sizeof(byte_time[0]), compare);

	while (byte_time[pos][1] == 0)
	{
		M -= byte_time[pos][0];
		++pos;
	}

	printf("%d\n", min);

	return 0;
}

int compare(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;

	if (x[1] > y[1])
		return 1;
	else if (x[1] < y[1])
		return -1;
	else
	{
		if (x[0] > y[0])
			return -1;
		else if (x[0] < y[0])
			return 1;
		else
			return 0;
	}
}
