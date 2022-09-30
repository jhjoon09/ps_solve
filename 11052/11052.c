#include <stdio.h>

int cost[1001];

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int money[1001] = {0,};

	for(int i = 1; i <= n; ++i)
		scanf("%d", cost + i);

	for(int i = 1; i <= n; ++i)
	{
		money[i] = cost[i];

		for(int j = 1; j < i; ++j)
		{
			if(money[i] < money[i-j] + cost[j])
				money[i] = money[i-j] + cost[j];
		}
	}

	printf("%d\n", money[n]);

	return 0;
}
