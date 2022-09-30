#include <stdio.h>

long long tree[1000000];
int n;
long long m;

long long check(long long);
long long search(long long, long long);

int main(void)
{
	scanf("%d %lld", &n, &m);

	long long low = 0;
	long long mid = 0;
	long long max = 0;

	long long result = 0;

	for(int i = 0; i < n; ++i)
	{
		scanf("%lld", tree + i);
		if(tree[i] > max)
			max = tree[i];
	}

	while (low <= max)
	{
		mid = (low + max) / 2;

		if(check(mid) < m)
			max = mid - 1;
		else
		{
			low = mid + 1;
			if(mid > result)
				result = mid;
		}

	}

	printf("%lld\n", result);


	return 0;
}

long long check(long long length)
{
	long long sum = 0;

	for(int i = 0; i < n; ++i)
	{
		sum += tree[i] > length ? tree[i] - length : 0;
	}

	return sum;
}
