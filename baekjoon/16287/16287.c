#include <stdio.h>
#include <stdlib.h>
#define MAX 799994

int check[MAX];
int input[5000];
int n,w;

int compare(const void*, const void*);

int main(void)
{
	scanf("%d %d", &w, &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", input+i);

	qsort(input, n, sizeof(int), compare);

	for(int i = 1; i < n-2; ++i)
	{
		for(int j = 0; j < i; ++j)
			check[input[i] + input[j]] = 1;		

		for(int j = i+2; j < n; ++j)
		{
			int temp = w - input[i+1] - input[j];
			
			if(temp < 0)
				break;

			if(check[temp] == 1)
			{
				printf("YES\n");
				return 0;
			}
		}

	}

	printf("NO\n");

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if(x > y)
		return 1;
	else if(x == y)
		return 0;
	else
		return -1;
}
