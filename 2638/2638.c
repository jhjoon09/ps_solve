#include <stdio.h>

int N, M;
int board[100][100];
int que[10000][2];

int check_cheese(int, int);
int spread_air(int, int);

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			scanf("%d", board[i] + j);
	}

	int count = 0;
	int flag = 1;
	int point = 0;

	board[0][0] = -1;
	spread_air(0, 0);

	while (flag != 0)
	{
		flag = 0;
		point = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (board[i][j] == 1)
				{
					if (check_cheese(i, j) == 1)
					{
						que[point][0] = i;
						que[point][1] = j;
						++point;

						flag = 1;
					}
				}
			}
		}


		for (int i = 0; i < point; ++i)
		{
			board[que[i][0]][que[i][1]] = -1;
			spread_air(que[i][0], que[i][1]);
		}
		++count;
	}

	printf("%d\n", count - 1);

	return 0;
}

int check_cheese(int x, int y)
{
	int count = 0;

	if (x - 1 >= 0)
	{
		if (board[x - 1][y] == -1)
			++count;
	}

	if (x + 1 < N)
	{
		if (board[x + 1][y] == -1)
			++count;
	}

	if (y - 1 >= 0)
	{
		if (board[x][y - 1] == -1)
			++count;
	}

	if (y + 1 < M)
	{
		if (board[x][y + 1] == -1)
			++count;
	}

	if (count >= 2)
	{
		return 1;
	}

	return -1;
}

int spread_air(int x, int y)
{
	if (x - 1 >= 0)
	{
		if (board[x - 1][y] == 0)
		{
			board[x - 1][y] = -1;

			spread_air(x - 1, y);
		}
	}

	if (x + 1 < N)
	{
		if (board[x + 1][y] == 0)
		{
			board[x + 1][y] = -1;

			spread_air(x + 1, y);
		}
	}

	if (y - 1 >= 0)
	{
		if (board[x][y - 1] == 0)
		{
			board[x][y - 1] = -1;

			spread_air(x, y - 1);
		}

	}

	if (y + 1 < M)
	{
		if (board[x][y + 1] == 0)
		{
			board[x][y + 1] = -1;

			spread_air(x, y + 1);
		}
	}

	return 1;
}
