#include <stdio.h>
#define INF 2000000000

typedef struct _edge
{
	int start;
	int end;
	int t;
}Edge;

Edge edge_list[5200];

int N,M,W;

int bellman(void);

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int k = 0; k < T; ++k)
	{
		scanf("%d %d %d", &N, &M, &W);
	
		for(int i = 0; i < M; ++i)
		{
			int a, b, c;

			scanf("%d %d %d", &a, &b, &c);

			edge_list[i*2].start = a;
			edge_list[i*2].end = b;
			edge_list[i*2].t = c;
			
			edge_list[i*2 + 1].start = b;
			edge_list[i*2 + 1].end = a;
			edge_list[i*2 + 1].t = c;

		}

		for(int i = 0; i < W; ++i)
		{
			int a, b, c;

			scanf("%d %d %d", &a, &b, &c);

			edge_list[M*2 + i].start = a;
			edge_list[M*2 + i].end = b;
			edge_list[M*2 + i].t = -c;
		}

		//algorithm
	
		if(bellman() == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

int bellman(void)
{
	int dis[501];
	int count = M*2 + W;

	for(int i = 1; i <= N; ++i)
		dis[i] = INF;

	dis[1] = 0;

	for(int i = 0; i < N-1; ++i)
	{
		for(int j = 0; j < count; ++j)
		{
			int s = edge_list[j].start;
			int e = edge_list[j].end;
			int t = edge_list[j].t;

			if(dis[e] > dis[s] + t)
				dis[e] = dis[s] + t;
		}
	}

	for(int j = 0; j < count; ++j)
	{
		int s = edge_list[j].start;
		int e = edge_list[j].end;
		int t = edge_list[j].t;

		if(dis[e] > dis[s] + t)
			return 1;
	}

	return 0;
}
