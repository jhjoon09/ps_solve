#include <stdio.h>
#include <stdlib.h>
#define N_MAX 32001
#define E_MAX 100000

int edge[E_MAX][2];
int count[N_MAX];
int pivot[N_MAX];
int que[N_MAX];
int N, M;

int compare(const void*, const void*);

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", edge[i] + 0, edge[i] + 1);
		++pivot[edge[i][0]];
		++count[edge[i][1]];
	}

	qsort(edge, M, sizeof(edge[0]), compare);

	int start = 0;
	int end = 0;
	int n_end = 0;

	for (int i = 1; i <= N; ++i)
	{
		pivot[i] += pivot[i - 1];

		if (count[i] == 0)
		{
			que[n_end] = i;
			++n_end;
		}
	}

	while (n_end < N)
	{
		start = end;
		end = n_end;

		for (int i = start; i < end; ++i)
		{
			//TODO check here
			int j = pivot[que[i]-1];

			while(edge[j][0] == que[i])
			{
				--count[edge[j][1]];
				if (count[edge[j][1]] == 0)
				{
					que[n_end] = edge[j][1];
					++n_end;
				}

				++j;
			}

		}
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", que[i]);

	printf("\n");

	return 0;
}

int compare(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;

	if (x[0] > y[0])
		return 1;
	else if (x[0] < y[0])
		return -1;
	else
	{
		if (x[1] > y[1])
			return 1;
		else
			return -1;
	}
}
