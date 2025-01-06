#include <stdio.h>
#include <queue>
#define MAX 32001

int count[MAX];
int list[MAX];
int N,M;

int main(void)
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; ++i)
	{
		int from, to;
		
		scanf("%d %d", &from, &to);

		edge_que[from].push(to);
		++count[to];
	}

	for(int i = 1; i <= N; ++i)
	{
		if(count[i] == 0)
			out_que.push(i);
	}

	int end = N-1;

	while(out_que.size() != 0)
	{
		while(out_que.empty() != 1)
		{
			int out = out_que.top();
			out_que.pop();
			list[end] = out;
			--end;

			while(edge_que[out].empty() != 1)
			{
				int link = edge_que[out].top();
				edge_que[out].pop();

				--count[link];

				if(count[link] == 0)
					t_que.push(link);
			}

		}

		out_que = t_que;
	}

	for(int i = 0; i < N; ++i)
		printf("%d ", list[i]);

	return 0;
}
