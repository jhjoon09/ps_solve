#include <stdio.h>
#include <limits.h>
#define MAX 1000

int mars[MAX][MAX];
int dp[MAX][MAX][3];
int N,M;

int move_robot(int, int, int);

int main(void)
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			scanf("%d", mars[i] + j);
			dp[i][j][0] = INT_MIN;
			dp[i][j][1] = INT_MIN;
			dp[i][j][2] = INT_MIN;
		}
	}
	int ret = move_robot(0, 0, 2);

	printf("%d\n", ret);

	return 0;
}

int move_robot(int x, int y, int dir)
{
	if(x < 0 || x >= N || y < 0 || y >= M)
		return INT_MIN;

	if(x == N-1 && y == M-1)
		return mars[x][y];

	if(dp[x][y][dir] != INT_MIN)
		return dp[x][y][dir];

	int max = move_robot(x+1, y, 2);
	int temp;

	if(dir == 2)
	{
		temp = move_robot(x, y+1, 1);
		if(temp > max)
			max = temp;

		temp = move_robot(x, y-1, 0);

		if(temp > max)
			max = temp;
	}
	else if(dir == 0)
	{
		temp = move_robot(x, y-1, 0);

		if(temp > max)
			max = temp;
	}
	else
	{
		temp = move_robot(x, y+1, 1);
		if(temp > max)
			max = temp;
	}

	if(max == INT_MIN)
		return max;

	dp[x][y][dir] = max + mars[x][y];

	return max + mars[x][y];
}
