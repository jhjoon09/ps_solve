#include <stdio.h>

int board[1000][1000];

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", (*(board+i))+j);
		}
	}

	for(int i = 1; i < n; ++i)
		board[i][0] += board[i-1][0];

	for(int j = 1; j < m; ++j)
		board[0][j] += board[0][j-1];

	for(int i = 1; i < n; ++i)
	{
		for(int j = 1; j < m; ++j)
		{
			int max = board[i-1][j-1];

			if(max < board[i][j-1])
				max = board[i][j-1];
			if(max < board[i-1][j])
				max = board[i-1][j];

			board[i][j] += max;
		}
	}

	printf("%d\n", board[n-1][m-1]);

	return 0;
}
