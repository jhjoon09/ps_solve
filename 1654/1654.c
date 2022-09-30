#include <stdio.h>

long long line[10000];
int k, n;

int check(long long);
long long cal(long long, long long);

int main(void)
{
	scanf("%d %d", &k, &n);

	long long max = 0;

	for (int i = 0; i < k; ++i)
	{
		scanf("%lld", line + i);

		if (line[i] > max)
			max = line[i];
	}

	printf("%lld", cal(1, max));

	return 0;
}

int check(long long length)
{
	long long sum = 0;

	for (int i = 0; i < k; ++i)
	{
		sum += line[i] / length;

		if (sum >= n)
			return 1;
	}

	return 0;
}

long long cal(long long start, long long end)
{
	if (start > end)
		return end;

	long long mid = (start + end) / 2;

	if (check(mid))
		return cal(mid+1, end);
	else
		return cal(start, mid - 1);
}
