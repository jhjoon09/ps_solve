#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);
int search(int*,int, int, int);

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	int* x = malloc(sizeof(int) * n);
	int* y = malloc(sizeof(int) * n); 

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", x + i);
		*(y + i) = *(x + i);
	}

	qsort(y, n, sizeof(int), compare);	

	int temp = *(y + 0);
	int end = 0;

	for(int i = 1; i < n; ++i)
	{
		if(temp != *(y+i))
		{
			++end;
			*(y+end) = *(y+i);
			temp = *(y+end);
		}
	}

	for(int i = 0; i < n; ++i)
	{
		printf("%d ", search(y, *(x+i), 0, end));
	}

	printf("\n");

	free(x);
	free(y);

	return 0;

}

int compare(const void* a, const void* b)
{
	int num1 = * (int*)a;
	int num2 = * (int*)b;

	if(num1 < num2)
		return -1;

	if(num1 > num2)
		return 1;

	return 0;
}

int search(int* list, int val, int start, int end)
{
	int mid = (start + end) / 2;

	if(list[mid] == val)
		return mid;
	else if(list[mid] > val)
		return search(list, val, start, mid-1);
	else
		return search(list, val, mid+1, end);

}
