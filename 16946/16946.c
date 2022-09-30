#include <stdio.h>

int board[1000][1000];
int count[1000000];
int mark;
int n, m;

int circuit(int, int, int*);
int sum(int, int);

int main(void)
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", board[i] + j);

			if (board[i][j] == 1)
				board[i][j] = -1;
		}
	}
	int move = 0;
	mark = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0)
			{
				move = 0;
				circuit(i, j, &move);
				++mark;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == -1)
				printf("%d", sum(i, j)%10);
			else
				printf("0");
		}
		printf("\n");
	}

	return 0;
}

int circuit(int x, int y, int* move)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;

	if (board[x][y] != 0)
		return 0;

	board[x][y] = mark;

	++(*move);

	int dxy[] = { 0, 1, 0, -1 };

	for (int i = 0; i < 4; ++i)
		circuit(x + dxy[i], y + dxy[3 - i], move);

	count[mark] = *move;

	return 0;
}

int sum(int x, int y)
{
	int name[4] = { 0 , };
	int ret = 1;

	if (x != 0)
	{
		if (board[x - 1][y] != -1)
		{
			name[0] = board[x - 1][y];
			ret += count[name[0]];
		}
	}

	if (y + 1 != m)
	{
		if (board[x][y + 1] != -1)
		{
			name[1] = board[x][y + 1];

			if (name[1] != name[0])
				ret += count[name[1]];
		}
	}

	if (x + 1 != n)
	{
		if (board[x + 1][y] != -1)
		{

			name[2] = board[x + 1][y];

			if (name[2] != name[0] && name[2] != name[1])
				ret += count[name[2]];
		}
	}
	if (y != 0)
	{
		if (board[x][y - 1] != -1)
		{

			name[3] = board[x][y - 1];

			if (name[3] != name[0] && name[3] != name[1] && name[3] != name[2])
				ret += count[name[3]];
		}
	}
	return ret;
}
