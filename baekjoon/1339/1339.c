#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count[26];

int compare(const void*, const void*);

int main(void)
{
	int n;

	scanf("%d", &n);

	while (n-- > 0)
	{
		char input[10];
		scanf("%s", input);

		int len = strlen(input);

		int t = 1;

		for (int i = len - 1; i >= 0; --i)
		{
			count[input[i] - 'A'] += t;
			t *= 10;
		}
	}

	qsort(count, sizeof(count) / sizeof(int), sizeof(int), compare);

	long long sum = 0;

	for (int i = 0; i < 9; ++i)
		sum += count[i] * (9 - i);

	printf("%lld\n", sum);

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = *((int*)a);
	int y = *((int*)b);

	if (x > y)
		return -1;
	else if (x == y)
		return 0;
	else
		return 1;
}
