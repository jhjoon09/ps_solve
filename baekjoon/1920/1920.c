#include <stdio.h>
#include <stdlib.h>

int list[100000];

int compare(const void*,const void*);
int search(int, int, int);

int main(void)
{
	int n, m;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", list + i);

	qsort(list, n, sizeof(int), compare);

	scanf("%d", &m);

	int temp = 0;

	for(int i = 0; i < m; ++i)
	{
		scanf("%d", &temp);

		if(search(temp, 0 , n-1))
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}

int compare(const void* first, const void* second)
{
	if(*(int*)first > *(int*)second) return 1;
	else if(*(int*)first < *(int*)second) return -1;
	else return 0;
}

int search(int temp, int start, int end)
{
	if(start > end)
		return list[start] == temp;

	int mid = (start + end) / 2;

	if(list[mid] == temp)
		return 1;
	else if(list[mid] > temp)
		return search(temp, start, mid - 1);
	else
		return search(temp, mid + 1, end);
}
