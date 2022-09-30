#include <stdio.h>
#include <limits.h>
#define MAX 500

int dp[MAX][MAX];
int input[MAX][2];

int mult(int, int);

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d %d", input[i] + 0, input[i] + 1);
	}

	mult(0, n-1);

	printf("%d\n", dp[0][n-1]);

	return 0;
}

int mult(int start, int end)
{
	if(start >= end)
		return 0;
	
	if(dp[start][end] != 0)
		return dp[start][end];

	if(start + 1 == end)
	{
		int ret = input[start][0] * input[start][1] * input[end][1];

		dp[start][end] = ret;

		return ret;
	}

	int min = INT_MAX;

	for(int i = start+1; i < end; ++i)
	{
		int temp = mult(start, i) + mult(i+1, end) + input[start][0] * input[i][1] * input[end][1];
		
		if(min > temp)
			min = temp;
	}

	dp[start][end] = min;

	return min;
}
