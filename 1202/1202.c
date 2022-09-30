#include <stdio.h>
#include <stdlib.h>
#define MAX 300000

int dia[MAX][2];
int back[MAX];
int visit[MAX];
int k;

int compare_dia(const void*, const void*);
int compare_back(const void*, const void*);
int search(int, int, int);

int main(void)
{
	int n;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%d %d", dia[i] + 0, dia[i] + 1);

	for (int i = 0; i < k; ++i)
		scanf("%d", back + i);

	qsort(dia, n, sizeof(dia[0]), compare_dia);

	qsort(back, k, sizeof(int), compare_back);

	long long sum = 0;

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int w = dia[i][0];

		if (search(w, 0, k - 1) != 0)
		{
			++count;
			sum += dia[i][1];
		}

		if (count == k)
			break;
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

int search(int val, int start, int end)
{
	int mid = (start + end) / 2;

	while (start < end)
	{
		if (back[mid] == val)
		{
			end = mid;
			break;
		}
		else if (back[mid] > val)
		{
			start = mid + 1;
		}
		else
			end = mid;

	}

	while (visit[end] == 1 && end < k)
		++end;

	if (end == k)
		return 0;

	visit[end] = 1;

	return 1;
}
