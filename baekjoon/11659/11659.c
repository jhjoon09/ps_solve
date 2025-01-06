#include <stdio.h>

int main(void)
{
	long long ll_sum[100001] = {0 ,};

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", ll_sum + i);
		ll_sum[i] += ll_sum[i-1];
	}

	int x, y;

	for(int i = 0; i < m; ++i)
	{
		scanf("%d %d", &x, &y);

		printf("%lld\n", ll_sum[y] - ll_sum[x-1]);
	}

	return 0;
}
