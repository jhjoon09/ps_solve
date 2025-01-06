#include <stdio.h>

int main(void)
{
	int n = 0;
	unsigned long long len[1000000] = {0, };
	unsigned long long cost[1000000] = {0, };
	unsigned long long money = 0;
	int cheap = 0;

	scanf("%d", &n);
	
	for(int i = 0; i < n -1; ++i)
		scanf("%llu", len + i);

	for(int i = 0; i < n; ++i)
		scanf("%llu", cost + i);

	cheap = cost[0];

	for(int i = 0; i < n -1; ++i)
	{
		if(cheap > cost[i])
			cheap = cost[i];

		money += cheap * len[i];
	}

	printf("%llu\n", money);

	return 0;
}
