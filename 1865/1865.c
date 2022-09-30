#include <stdio.h>
#include <limits.h>

int edge[501][501];

int main(void)
{
	int T;
	int N,M,W;

	scanf("%d", &T);

	for(int k = 0; k < T; ++k)
	{
		scanf("%d %d %d", &N, &M, &W);

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
			{
				edge[a][b] = c;
				edge[b][a] = c;
			}
		}

		for(int i = 0; i < W; ++i)
		{
			int a, b, c;

			scanf("%d %d %d", &a, &b, &c);

			c *= -1;

			if(edge[a][b] > c)
				edge[a][b] = c;
		}

		//algorithm
		for(int m = 1; m <= N; ++m)
		{
			for(int s = 1; s <= N; ++s)
			{
				for(int e = 1; e <= N; ++e)
				{
					if(edge[s][m] == INT_MAX || edge[m][e] == INT_MAX)
						continue;

					if(edge[s][e] > edge[s][m] + edge[m][e])
						edge[s][e] = edge[s][m] + edge[m][e];
				}
			}
		}
		
		int flag = 1;
		
		for(int i = 1; i <= N; ++i)
		{
			if(edge[i][i] < 0)
			{
				flag = 0;
				break;
			}
		}

		if(flag == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
