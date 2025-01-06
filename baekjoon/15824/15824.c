#include <stdio.h>
#include <stdlib.h>
#define MAX 300000
#define DIV 1000000007

int input[MAX];

int compare(const void*, const void*);
long long cal_cap(int);

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", input + i);

	qsort(input, n, sizeof(int), compare);

	long long ret = cal_cap(n);

	printf("%lld\n", ret);

	return 0;
}

int compare(const void* a, const void* b)
{
	if (*((int*)a) > *((int*)b))
		return 1;
	else if (*((int*)a) == *((int*)b))
		return 0;
	else
		return -1;
}

long long cal_cap(int n)
{
	long long count = 1;
	long long sum = 0;
	long long temp = input[0];

	for (int i = 1; i < n; ++i)
	{
		sum += ((long long)input[i] * count - temp);
		sum %= DIV;

		temp *= 2;
		count *= 2;

		temp += input[i];
		++count;

		temp %= DIV;
		count %= DIV;
	}

	return sum;
}
