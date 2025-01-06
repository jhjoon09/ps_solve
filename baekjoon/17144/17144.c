#include <stdio.h>

int dust[2][50][50];
int R, C;

int spread_dust(void);
int divide_dust(int, int);
int check(int, int);
int move_dust(void);
int clean_up(int, int);
int clean_down(int, int);

int main(void)
{
	int T;

	scanf("%d %d %d", &R, &C, &T);

	int x, y;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			scanf("%d", dust[0][i] + j);

			if (dust[0][i][j] == -1)
			{
				x = i;
				y = j;
			}
		}
	}

	for (int i = 0; i < T; ++i)
	{
		spread_dust();

		clean_up(x - 1, y);
		clean_down(x, y);
	}

	int sum = 0;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
			sum += dust[0][i][j];
	}

	printf("%d\n", sum + 2);

	return 0;
}

int spread_dust(void)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (dust[0][i][j] > 0)
			{
				divide_dust(i, j);
			}
		}
	}

	move_dust();

	return 0;
}

int divide_dust(int x, int y)
{
	int temp = dust[0][x][y];

	int minus = temp / 5;

	dust[1][x][y] += dust[0][x][y];

	if (check(x - 1, y) == 1)
	{
		dust[1][x - 1][y] += minus;
		dust[1][x][y] -= minus;
	}

	if (check(x + 1, y) == 1)
	{
		dust[1][x + 1][y] += minus;
		dust[1][x][y] -= minus;
	}

	if (check(x, y - 1) == 1)
	{
		dust[1][x][y - 1] += minus;
		dust[1][x][y] -= minus;
	}

	if (check(x, y + 1) == 1)
	{
		dust[1][x][y + 1] += minus;
		dust[1][x][y] -= minus;
	}

	return 0;
}

int check(int x, int y)
{
	if (x < 0 || x >= R || y < 0 || y >= C)
		return 0;

	if (dust[0][x][y] == -1)
		return 0;

	return 1;
}

int move_dust(void)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			dust[0][i][j] = dust[1][i][j];
			dust[1][i][j] = 0;
		}
	}

	return 0;
}

int clean_up(int x, int y)
{
	for (int i = x; i >= 1; --i)
	{
		int temp = dust[0][i][y];
		dust[0][i][y] = dust[0][i - 1][y];
		dust[0][i - 1][y] = temp;
	}

	for (int i = 0; i < C - 1; ++i)
	{
		int temp = dust[0][0][i];
		dust[0][0][i] = dust[0][0][i + 1];
		dust[0][0][i + 1] = temp;
	}

	for (int i = 0; i < x; ++i)
	{
		int temp = dust[0][i][C - 1];
		dust[0][i][C - 1] = dust[0][i + 1][C - 1];
		dust[0][i + 1][C - 1] = temp;
	}

	for (int i = C - 1; i > 0; --i)
	{
		int temp = dust[0][x][i];
		dust[0][x][i] = dust[0][x][i - 1];
		dust[0][x][i - 1] = temp;
	}

	dust[0][x][y] = -1;
	dust[0][x][y + 1] = 0;

	return 1;
}

int clean_down(int x, int y)
{
	for (int i = x; i < R - 1; ++i)
	{
		int temp = dust[0][i][y];
		dust[0][i][y] = dust[0][i + 1][y];
		dust[0][i + 1][y] = temp;
	}

	for (int i = 0; i < C - 1; ++i)
	{
		int temp = dust[0][R - 1][i];
		dust[0][R - 1][i] = dust[0][R - 1][i + 1];
		dust[0][R - 1][i + 1] = temp;
	}

	for (int i = R - 1; i > x; --i)
	{
		int temp = dust[0][i][C - 1];
		dust[0][i][C - 1] = dust[0][i - 1][C - 1];
		dust[0][i - 1][C - 1] = temp;
	}

	for (int i = C - 1; i > 0; --i)
	{
		int temp = dust[0][x][i];
		dust[0][x][i] = dust[0][x][i - 1];
		dust[0][x][i - 1] = temp;
	}


	dust[0][x][y] = -1;
	dust[0][x][y + 1] = 0;

	return 1;
}

