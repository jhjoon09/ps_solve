#include <stdio.h>
#include <limits.h>

int N,M,R;
int item_count[101];
int road[101][101];
int visit[101];

int find_item(int, int, int);

int main(void)
{
	scanf("%d %d %d", &N, &M, &R);

	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			road[i][j] = INT_MAX;
		}

		road[i][i] = 0;
	}

	for(int i = 1; i <= N; ++i)
		scanf("%d", item_count + i);

	for(int i = 0; i < R; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		road[a][b] = c;
		road[b][a] = c;
	}

	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			for(int k = 1; k <= N; ++k)
			{
				if(road[j][i] != INT_MAX && road[i][k] != INT_MAX)
				{
					if(road[j][k] > road[j][i] + road[i][k])
					{
						road[j][k] = road[j][i] + road[i][k];
						road[k][j] = road[j][k];
					}
				}
			}
		}
	}

	int max = 0;

	for(int i = 1; i <= N; ++i)
	{
		int temp = 0;

		for(int j = 1; j <= N; ++j)
		{
			if(road[i][j] <= M)
				temp += item_count[j];
		}

		if(temp > max)
			max = temp;
	}

	printf("%d\n", max);

	return 0;
}
