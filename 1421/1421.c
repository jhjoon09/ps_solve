#include <stdio.h>

int main(void)
{
	int n,c,w;

	scanf("%d %d %d", &n, &c, &w);

	int wood[50] = {0 ,};

	int lon = 0;

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", wood + i);

		if( wood[i] > lon)
			lon = wood[i];
	}

	long long max = 0;
	long long money = 0;

	long long sell = 0;

	for(int i = 1; i <= lon; ++i)
	{
		money = 0;
		sell = 0;

		for(int j = 0; j < n; ++j)
		{
			if(wood[j] >= i)
			{
				sell += (wood[j] / i) * i * w;

				if(wood[j] % i == 0)
					sell -= (wood[j] / i -1) * c;
				else
					sell -= (wood[j] / i) * c;


				if(sell > 0)
					money += sell;
			}
		}

		if(money > max)
			max = money;

	}

	printf("%lld\n", max);

	return 0;

}
