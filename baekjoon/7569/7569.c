#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct _pos {
	int x;
	int y;
	int z;
	int day;
}Pos;

int m, n, h;
int tomato[100][100][100];

int check(int, int, int);

int main(void)
{
	scanf("%d %d %d", &m, &n, &h);

	Pos* que = (Pos*)malloc(sizeof(Pos) * m * n * h);

	int count = 0;
	int end = 0;

	for (int k = 0; k < h; ++k)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < m; ++i)
			{
				scanf("%d", (*(*(tomato + i) + j)) + k);

				if (tomato[i][j][k] == 0)
					++count;

				if (tomato[i][j][k] == 1)
				{
					que[end].x = i;
					que[end].y = j;
					que[end].z = k;
					que[end].day = 0;
					++end;
				}
			}
		}
	}

	if (count == 0)
	{
		printf("0\n");
		return 0;
	}

	int start = 0;

	while (start < end)
	{
		int i = que[start].x;
		int j = que[start].y;
		int k = que[start].z;

		if (check(i + 1, j, k))
		{
			tomato[i+1][j][k] = 1;
			que[end].x = i + 1;
			que[end].y = j;
			que[end].z = k;
			que[end].day = que[start].day + 1;

			++end;
		}

		if (check(i - 1, j, k))
		{
			tomato[i-1][j][k] = 1;
			que[end].x = i - 1;
			que[end].y = j;
			que[end].z = k;
			que[end].day = que[start].day + 1;

			++end;
		}

		if (check(i, j + 1, k))
		{
			tomato[i][j+1][k] = 1;
			que[end].x = i;
			que[end].y = j + 1;
			que[end].z = k;
			que[end].day = que[start].day + 1;

			++end;
		}

		if (check(i, j - 1, k))
		{
			tomato[i][j-1][k] = 1;
			que[end].x = i;
			que[end].y = j - 1;
			que[end].z = k;
			que[end].day = que[start].day + 1;

			++end;
		}

		if (check(i, j, k + 1))
		{
			tomato[i][j][k+1] = 1;
			que[end].x = i;
			que[end].y = j;
			que[end].z = k + 1;
			que[end].day = que[start].day + 1;

			++end;
		}

		if (check(i, j, k - 1))
		{
			tomato[i][j][k-1] = 1;
			que[end].x = i;
			que[end].y = j;
			que[end].z = k - 1;
			que[end].day = que[start].day + 1;

			++end;
		}


		++start;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < h; ++k)
			{
				if (tomato[i][j][k] == 0)
				{
					printf("-1\n");
					return 0;
				}
			}
		}
	}

	printf("%d\n", que[end - 1].day);
	free(que);

	return 0;
}

int check(int x, int y, int z)
{
	if (x >= m || y >= n || z >= h || x < 0 || y < 0 || z < 0)
		return 0;

	if (tomato[x][y][z] != 0)
		return 0;

	return 1;
}
