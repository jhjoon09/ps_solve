#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 300000

long long prime[MAX];
int last;

int init_prime(int);
int count_prime(int);
int search(int, int, long long);

int main(void)
{
	int N;

	scanf("%d", &N);

	last = init_prime(N);

	int ret = count_prime(N);

	printf("%d\n", ret);

	return 0;
}

int init_prime(int n)
{
	int* list = (int*)calloc(n + 1, sizeof(int));

	int pos = 1;

	for (int i = 2; i <= n; ++i)
	{
		if (list[i] == 0)
		{
			prime[pos] = i;
			++pos;

			for (int j = i; j <= n; j += i)
				list[j] = 1;
		}
	}

	free(list);

	for (int i = 1; i < pos; ++i)
	{
		prime[i] += prime[i - 1];
	}

	prime[pos] = LLONG_MAX;

	return pos;
}

int count_prime(int n)
{
	int pos = search(0, last, n);
	int count = 0;

	while (prime[pos] - prime[pos - 1] <= n)
	{
		int temp = search(0, pos, prime[pos] - n);

		if (prime[pos] - prime[temp] == n)
			++count;

		++pos;
	}


	return count;
}

int search(int start, int end, long long val)
{
	while (start < end)
	{
		int mid = (start + end) / 2;

		if (prime[mid] == val)
			return mid;
		else if (prime[mid] > val)
			end = mid;
		else
			start = mid + 1;
	}

	return end;
}
