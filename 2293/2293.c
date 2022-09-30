#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void*, const void*);

int main(void)
{
	int coin[100] = {0,};
	int count[10001] = {0 ,};
	int temp[10001] = {0, };
	int n, k;

	count[0] = 1;

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", coin + i);
	}

	qsort(coin, n, sizeof(int), compare);

	for(int i = 0; i < n; ++i)
	{
		memset(temp, 0, sizeof(temp));
		for(int j = coin[i]; j <= k; ++j)
		{
			temp[j] = count[j - coin[i]] + temp[j-coin[i]];
		}

		for(int j = coin[i]; j <= k; ++j)
			count[j] += temp[j];
	}


	printf("%d\n", count[k]);

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = *((int*)a);
	int y = *((int*)b);

	if(x < y)
		return -1;
	else if(x == y)
		return 0;
	else
		return 1;
}
