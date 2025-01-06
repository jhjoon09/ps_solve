#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define VERTEX 10000
#define EDGE 100000

using namespace std;

int visit[VERTEX];
int e_index[VERTEX + 1];
int e_list[EDGE * 2][3];

int compare(const void*, const void*);

int main(void)
{
	int V, E;

	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; ++i)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		e_list[i * 2][0] = a - 1;
		e_list[i * 2][1] = b - 1;
		e_list[i * 2][2] = c;

		e_list[i * 2 + 1][0] = b - 1;
		e_list[i * 2 + 1][1] = a - 1;
		e_list[i * 2 + 1][2] = c;
	}

	qsort(e_list, E * 2, sizeof(e_list[0]), compare);

	int pos = 0;

	for (int i = 0; i < V; ++i)
	{
		e_index[i] = pos;

		while (e_list[pos][0] == i)
			++pos;
	}

	e_index[V] = 2 * E;

	priority_queue<pair<int, int>> pq;

	visit[0] = 1;

	for (int i = e_index[0]; i < e_index[1]; ++i)
	{
		pq.push({ -e_list[i][2], e_list[i][1] });
	}

	int sum = 0;

	for (int i = 1; i < V; ++i)
	{
		while (visit[pq.top().second] != 0)
			pq.pop();

		int next = pq.top().second;
		sum -= pq.top().first;

		visit[next] = 1;

		for (int i = e_index[next]; i < e_index[next + 1]; ++i)
		{
			pq.push({ -e_list[i][2], e_list[i][1] });
		}
	}

	printf("%d\n", sum);

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
		else if (x[1] < y[1])
			return -1;
		else
			return 0;
	}
}
