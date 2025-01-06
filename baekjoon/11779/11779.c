#include <stdio.h>
#include <limits.h>
#include <string.h>

int edge[1001][1001];
int list[1001][1001];
int count[1001];
int visit[1001];

int N, M;

int find_min(int);

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			edge[i][j] = INT_MAX;

		edge[i][i] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		if(edge[a][b] > c)
			edge[a][b] = c;
	}

	int from, to;

	scanf("%d %d", &from, &to);

	visit[from] = 1;
	count[from] = 1;
	list[from][0] = from;

	int temp = find_min(from);

	while (temp != INT_MAX)
	{
		visit[temp] = 1;

		if (count[temp] == 0)
		{
			list[temp][0] = from;
			count[temp] = 2;
			list[temp][1] = temp;
		}

		for (int i = 1; i <= N; ++i)
		{
			if (edge[from][temp] == INT_MAX || edge[temp][i] == INT_MAX)
				continue;

			if (edge[from][i] > edge[from][temp] + edge[temp][i])
			{
				edge[from][i] = edge[from][temp] + edge[temp][i];

				memset(list[i], 0, sizeof(int) * count[i]);

				count[i] = count[temp] + 1;

				for (int j = 0; j <= count[temp]; ++j)
					list[i][j] = list[temp][j];

				list[i][count[i]-1] = i;
			}
		}
		temp = find_min(from);
	}

	printf("%d\n%d\n", edge[from][to], count[to]);

	for (int i = 0; i < count[to]; ++i)
		printf("%d ", list[to][i]);

	printf("\n");

	return 0;
}

int find_min(int from)
{
	int temp = INT_MAX;

	for (int i = 1; i <= N; ++i)
	{
		if (visit[i] == 1)
			continue;

		if (temp == INT_MAX)
		{
			temp = i;
			continue;
		}

		if (edge[from][i] < edge[from][temp])
			temp = i;

	}

	return temp;
}
