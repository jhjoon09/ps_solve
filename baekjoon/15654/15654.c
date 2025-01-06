#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);
int make_list(int, int);

int list[8];
int point[8];
int check[8];
int n, m;

int main(void)
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
		scanf("%d", list + i);

	qsort(list, n, sizeof(int), compare);

	for(int i = 0; i < n; ++i)
		make_list(0, i);

	return 0;
}

int compare(const void* a, const void*b)
{
	int x = *((int*)a);
	int y = *((int*)b);

	if(x > y)
		return 1;
	else if(x == y)
		return 0;
	else
		return -1;
}

int make_list(int count, int pos)
{
	if(pos >= n || check[pos] != 0)
		return -1;

	point[count++] = list[pos];
	check[pos] = 1;

	if(count == m)
	{
		check[pos] = 0;

		for(int i = 0; i < m; ++i)
			printf("%d ", point[i]);

		printf("\n");
		return 1;
	}

	for(int i = 0; i < n; ++i)
		make_list(count, i);

	check[pos] = 0;
	return 0;
}

