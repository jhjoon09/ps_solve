#include <stdio.h>
#include <limits.h>
/*
	min_dis[1]
	min_dis[point_1]
	min_dis[point_2]
	min_dis[N]

	1 -> p2 -> p1 -> N
	1 -> p1 -> p2 -> N
   
 */
int edge[801][801];

int main(void)
{
	int N,E;

	scanf("%d %d", &N, &E);


	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
			edge[i][j] = INT_MAX;

		edge[i][i] = 0;
	}

	for(int i = 0; i < E; ++i)
	{
		int a, b, temp;

		scanf("%d %d %d", &a, &b, &temp);

		if(edge[a][b] > temp)
			edge[a][b] = temp;
	}

	int point_1, point_2;

	scanf("%d %d", &point_1, &point_2);

	//dijkstra 3 times

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

	int min_1 = INT_MAX;
	int min_2 = INT_MAX;
	if(edge[1][point_1] != INT_MAX && edge[point_1][point_2] != INT_MAX && edge[point_2][N] != INT_MAX)
		min_1 = edge[1][point_1] + edge[point_1][point_2] + edge[point_2][N];

	if(edge[1][point_2] != INT_MAX && edge[point_2][point_1] != INT_MAX && edge[point_1][N] != INT_MAX)
		min_2 = edge[1][point_2] + edge[point_2][point_1] + edge[point_1][N];

	int min = min_1 > min_2 ? min_2 : min_1;
	if(min != INT_MAX)
		printf("%d\n", min);
	else
		printf("-1\n");


	return 0;
}
