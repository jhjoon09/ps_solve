#include <stdio.h>
#include <limits.h>

int edge[101][101];

int main(void)
{
	int N, M, X;

	scanf("%d %d %d", &N, &M, &X);

	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
			edge[i][j] = INT_MAX;

		edge[i][i] = 0;
	}

	for(int i = 0; i < M; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if(edge[a][b] > c)
			edge[a][b] = c;
	}

	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			for(int k = 1; k <= N; ++k)
			{
				if(edge[j][i] != INT_MAX && edge[i][k] != INT_MAX)
				{
					if(edge[j][i] + edge[i][k] < edge[j][k])
						edge[j][k] = edge[j][i] + edge[i][k];
				}
			}
		}
	}

	int max = 0;

	for(int i = 1; i <= N; ++i)
	{
		if(max < edge[i][X] + edge[X][i])
			max = edge[i][X] + edge[X][i];
	}

	printf("%d\n", max);

	return 0;
}              
