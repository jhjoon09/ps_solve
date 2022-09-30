#include <stdio.h>

long long n, k;

long long k_search(long long, long long);
long long k_count(long long);

int main(void)
{
	scanf("%lld %lld", &n, &k);

	long long ret = k_search(1, n * n+1);

	printf("%lld\n", ret);

	return 0;
}

long long k_search(long long start, long long end)
{
	long long mid;

	while (start+1 < end)
	{
		mid = (start + end) / 2;
		long long temp = k_count(mid);

		if (temp <= k)
			start = mid;
		else
			end = mid;
	}

	return start;
}

long long k_count(long long end)
{
	long long temp = 0;

	for (long long i = 1; i <= n; ++i)
	{
		if (n * i < end)
			temp += n;
		else 
		{
			if (end % i == 0)
				temp += (end / i) - 1;
			else
				temp += (end / i);
		}
	}

	return temp+1;
}
