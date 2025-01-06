#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int compare(const void*, const void*);

int point[MAX][2];

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d %d", &point[i][0], &point[i][1]);

	qsort(point, n, sizeof(point[0]), compare);

	for(int i = 0; i < n; ++i)
		printf("%d %d\n", point[i][0], point[i][1]);

	return 0;
}

int compare(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;

	if(x[0] > y[0])
		return 1;
	else if(x[0] == y[0])
	{
		if(x[1] > y[1])
			return 1;
		else if(x[1] == y[1])
			return 0;
		else
			return -1;
	}
	else
		return -1;
}

