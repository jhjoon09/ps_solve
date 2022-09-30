#include <stdio.h>

int board[500][500];
int dp[500][500];

int M, N;

int move_map(int, int);

int main(void)
{
	scanf("%d %d", &M, &N);

	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			scanf("%d", &board[i][j]);
			dp[i][j] = -1;
		}
	}

	int count = move_map(0, 0);

	printf("%d\n", count);

	return 0;
}

int move_map(int x, int y)
{
	if(x == M-1 && y == N-1)
		return 1;

	if(dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;

	int dxy[] = {0, -1, 0, 1};

	for(int i = 0; i < 4; ++i)
	{
		int nx = x + dxy[i];
		int ny = y + dxy[3-i];

		if(nx >= 0 && ny >= 0 && nx < M && ny < N)
		{
			if(board[x][y] > board[nx][ny])
				dp[x][y] += move_map(nx, ny);
	
		}
	}
	return dp[x][y];
}
