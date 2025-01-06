#include <stdio.h>
#include <limits.h>

int N, M;
int map[8][8];
int virus[8][8];
int que[64][2];
int que_pos;

int build_wall(int, int, int);
int spread_virus(int, int);
int delete_virus(void);

int main(void)
{
	que_pos = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1)
				virus[i][j] = 1;
			else if (map[i][j] == 2)
			{
				que[que_pos][0] = i;
				que[que_pos][1] = j;
				++que_pos;
			}
		}
	}

	int min = build_wall(0, 0, 0);

	printf("%d\n", N * M - min);

	return 0;
}

int build_wall(int x, int y, int count)
{
	if (count == 3)
	{
		for (int i = 0; i < que_pos; ++i)
			spread_virus(que[i][0], que[i][1]);

		return delete_virus();
	}

	if (x == N)
		return INT_MAX;

	int next_y = y + 1;
	int next_x = x;

	if (next_y == M)
	{
		next_y = 0;
		++next_x;
	}

	int a = build_wall(next_x, next_y, count);

	if (map[x][y] != 0)
		return a;

	virus[x][y] = 1;
	int b = build_wall(next_x, next_y, count + 1);
	virus[x][y] = 0;

	return a < b ? a : b;
}

int spread_virus(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;

	if (virus[x][y] != 0)
		return 0;

	virus[x][y] = 2;

	int spread_list[4] = { 0, 1, 0, -1 };

	for (int i = 0; i < 4; ++i)
		spread_virus(x + spread_list[i], y + spread_list[3 - i]);

	return 1;
}

int delete_virus(void)
{
	int temp = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (virus[i][j] == 2)
			{
				++temp;
				virus[i][j] = 0;
			}
			else if (virus[i][j] == 1)
				++temp;

		}
	}

	return temp;
}
