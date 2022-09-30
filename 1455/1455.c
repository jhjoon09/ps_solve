#include <stdio.h>

int board[100][100];
int rev(int x, int y);

int main(void)
{
	int n,m;
	int count = 0;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	for(int i = n-1; i >= 0; --i)
	{
		for(int j = m-1; j >= 0; --j)
		{
			if(board[i][j] != 0)
			{
				rev(i,j);
				++count;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}

int rev(int x, int y)
{
	for(int i = 0; i <= x; ++i)
	{
		for(int j = 0; j <= y; ++j)
		{
			if(board[i][j] == 0)
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}

	return 0;
}
