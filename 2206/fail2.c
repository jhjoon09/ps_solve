#include <stdio.h>
#include <limits.h>

int N,M;
char board[1001][1001];
int dp[2][1000][1000];

int move(int, int, int);
int break_move(int, int, int);

int main(void)
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i)
	{
		scanf("%s", board[i]);

		for(int j = 0; j < M; ++j)
		{
			dp[0][i][j] = INT_MAX;
			dp[1][i][j] = INT_MAX;
		}
	}

	move(0, 0, 1);

	if(dp[1][N-1][M-1] == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", dp[1][N-1][M-1]);

	return 0;
}

int check_bound(int x, int y)
{
	if(x < 0 || x >= N || y < 0 || y >= M)
		return -1;


	return 1;
}

int move(int x, int y, int count)
{
	if(check_bound(x, y) != 1)
		return -1;

	if(board[x][y] == '1')
	{
		board[x][y] = '0';
		break_move(x, y, count);
		board[x][y] = '1';
		return 1;
	}

	if(dp[0][x][y] <= count)
		return -1;

	dp[0][x][y] = count;

	int dxy[] = {0, 1, 0, -1};

	for(int i = 0; i < 4; ++i)
	{
		move(x + dxy[i], y + dxy[3-i], count+1);
	}

	return 0;
}

int break_move(int x, int y, int count)
{
	if(check_bound(x, y) != 1)
		return -1;

	if(board[x][y] == '1')
		return -1;

	if(dp[1][x][y] <= count)
		return -1;

	dp[1][x][y] = count;

	int dxy[] = {0, 1, 0, -1};

	for(int i = 0; i < 4; ++i)
	{
		break_move(x + dxy[i], y + dxy[3-i], count+1);
	}

	return 0;
}
