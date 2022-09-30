#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct _pos {
	int x;
	int y;
	int time;
}Pos;

int tomato[1000][1000];
int M, N;

int check(int, int);

int main(void)
{
	scanf("%d %d", &M, &N);

	Pos* que = (Pos*)malloc(sizeof(Pos) * M * N);
	memset(que, 0, sizeof(Pos) * M * N);

	int end = 0;
	int count = 0;

	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < M; ++i)
		{
			scanf("%d", *(tomato + i) + j);

			if (tomato[i][j] == 0)
				++count;

			if (tomato[i][j] == 1)
			{
				que[end].x = i;
				que[end].y = j;
				que[end].time = 0;
				++end;
			}
		}
	}

	if (count == 0)
	{
		printf("%d\n", 0);
		free(que);
		return 0;
	}

	int start = 0;

	while (start < end)
	{
		int a = que[start].x;
		int b = que[start].y;

		if (check(a + 1, b))
		{
			tomato[a + 1][b] = 1;
			que[end].x = a + 1;
			que[end].y = b;
			que[end].time = que[start].time + 1;

			++end;
		}

		if (check(a - 1, b))
		{
			tomato[a - 1][b] = 1;
			que[end].x = a - 1;
			que[end].y = b;
			que[end].time = que[start].time + 1;

			++end;
		}

		if (check(a, b + 1))
		{
			tomato[a][b + 1] = 1;
			que[end].x = a;
			que[end].y = b + 1;
			que[end].time = (que[start].time) + 1;

			++end;
		}

		if (check(a, b - 1))
		{
			tomato[a][b - 1] = 1;
			que[end].x = a;
			que[end].y = b - 1;
			que[end].time = que[start].time + 1;

			++end;
		}
		++start;
	}

	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < M; ++i)
		{
			if (tomato[i][j] == 0)
			{
				printf("-1\n");
				free(que);
				return 0;
			}
		}
	}

	printf("%d\n", que[end - 1].time);

	free(que);

	return 0;
}

int check(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return 0;

	if (tomato[x][y] != 0)
		return 0;

	return 1;
}
