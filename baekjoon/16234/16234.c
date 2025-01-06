#include <stdio.h>
#include <string.h>
#define NON 10000000
#define ABS(x) ( (x) > 0 ) ? (x) : -(x)

int person[52][52];
int count[2500];
int team[52][52];
int N, L, R;

int make_union(int, int, int);

int main(void)
{
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%d", &person[i][j]);

	for (int i = 0; i <= N + 1; ++i)
	{
		person[i][0] = NON;
		person[0][i] = NON;
		person[N + 1][i] = NON;
		person[i][N + 1] = NON;
	}

	int name = 0;
	int time = 0;
	while (name != N * N)
	{
		memset(count, 0, sizeof(count));
		name = 0;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (team[i][j] == 0)
				{
					++name;
					count[name] /= make_union(i, j, name);
				}
			}
		}

		if (name == N * N)
			break;

		++time;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				person[i][j] = count[team[i][j]];
				team[i][j] = 0;
			}
		}
	}

	printf("%d\n", time);

	return 0;
}

int make_union(int x, int y, int name)
{
	if (team[x][y] == name)
		return 0;

	team[x][y] = name;
	count[name] += person[x][y];

	int temp = person[x][y];

	int a[] = { 0, 1, 0, -1 };
	int b[] = { 1, 0, -1, 0 };

	int sum = 0;

	for (int i = 0; i < 4; ++i)
	{
		int minus = ABS(temp - person[x + a[i]][y + b[i]]);

		if (minus >= L && minus <= R)
			sum += make_union(x + a[i], y + b[i], name);
	}

	return 1 + sum;
}
