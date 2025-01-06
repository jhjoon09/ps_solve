#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define MAX 300000

using namespace std;

int dia[MAX][2];
int back[MAX];
int visit[MAX];

int compare_dia(const void*, const void*);
int compare_back(const void*, const void*);

int main(void)
{
	int n,k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%d %d", dia[i] + 0, dia[i] + 1);

	for (int i = 0; i < k; ++i)
		scanf("%d", back + i);

	qsort(dia, n, sizeof(dia[0]), compare_dia);

	qsort(back, k, sizeof(int), compare_back);

	long long sum = 0;

	int pos = 0;

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < k; ++i)
	{
		while (dia[pos][0] <= back[i] && pos < n)
		{
			pq.push(pair<int, int>(dia[pos][1], dia[pos][0]));
			++pos;
		}

		if (pq.size() > 0)
		{
			sum += pq.top().first;
			pq.pop();
		}
	}


	printf("%lld\n", sum);

	return 0;
}

int compare_dia(const void* a, const void* b)
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
		else if (x[1] == y[1])
			return 0;
		else
			return -1;
	}
}

int compare_back(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a == *(int*)b)
		return 0;
	else
		return -1;
}
