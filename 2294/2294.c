#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main(void)
{
	int n,k;
	int dp[10001] = {0, };
	int coin[100] = {0, };
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; ++i)
		scanf("%d", coin + i);

	qsort(coin, n, sizeof(int), compare);

	int temp = 0;

	for(int i = 0; i < n; ++i)
	{
		if(temp == coin[i])
			continue;
		
		if(coin[i] > k)
			break;

		temp = coin[i];

		dp[temp] = 1;

		for(int j = 1; j < k; ++j)
		{
			if(j + temp > k)
				break;

			if(dp[j] != 0)
			{
				if(dp[j+temp] == 0 || dp[j+temp] > dp[j] + 1)
					dp[j + temp] = dp[j] + 1;
			}
		}
	}

	if(dp[k] == 0)
		printf("-1\n");
	else
		printf("%d\n", dp[k]);

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
	else return -1;
}
