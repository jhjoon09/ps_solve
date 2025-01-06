#include <stdio.h>
#include <stdlib.h>
#define MAX 200000

int home[MAX];

int compare(const void*, const void*);
int bns(int, int, int, int);
int router(int, int, int, int);
int bns_dis(int, int, int, int);

int main(void)
{
	int N, C;
	int MIN;

	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; ++i)
		scanf("%d", home + i);

	qsort(home, N, sizeof(int), compare);

	MIN = bns(1, (home[N - 1] - home[0]) / (C - 1), N, C);

	printf("%d\n", MIN);

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if (x > y)
		return 1;
	else if (y == x)
		return 0;
	else
		return -1;
}

int bns(int from, int to, int N, int C)
{
	if (to < from)
		return to;
	int mid = (from + to) / 2;

	if (router(0, N - 1, C - 1, mid) == 1)
		from = mid + 1;
	else
		to = mid - 1;

	return bns(from, to, N, C);
}

int router(int start, int end, int count, int length)
{
	if (home[end] - home[start] < length)
		return -1;

	if (count == 1)
	{
		if (home[end] - home[start] >= length)
			return 1;
		else
			return -1;
	}

	end = bns_dis(start, end, end, length);

	return router(start, end, count - 1, length);
}

int bns_dis(int start, int end, int pos, int length)
{
	if (start > end)
		return end;

	int mid = (start + end) / 2;

	if (home[pos] - home[mid] == length)
		return mid;
	else if (home[pos] - home[mid] > length)
		return bns_dis(mid+1, end, pos, length);
	else
		return bns_dis(start, mid-1, pos, length);
}
