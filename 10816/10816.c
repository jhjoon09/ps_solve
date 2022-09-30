#include <stdio.h>
#include <stdlib.h>

int list[500000];

int compare(const void*, const void*);
int u_search(int, int, int);
int l_search(int, int, int);

int main(void)
{
	int n, m;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", list + i);

	qsort(list, n, sizeof(int), compare);

	scanf("%d", &m);

	int temp = 0;

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &temp);

		printf("%d ", u_search(temp, 0, n) - l_search(temp, 0, n));

	}

	printf("\n");

	return 0;
}

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second) return 1;
	else if (*(int*)first < *(int*)second) return -1;
	else return 0;
}

int u_search(int temp, int start, int end)
{
	int mid;

	while (start < end)
	{ 
		mid = (start + end) / 2;

		if (list[mid] <= temp)
			start = mid + 1;
		else
			end = mid;
	}

	return end;
}

int l_search(int temp, int start, int end)
{
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (list[mid] < temp)
			start = mid + 1;
		else
			end = mid;
	}

	return end;
}
