#include <stdio.h>
#include <stdlib.h>
#define MAX 5000
#define ABS(x) (((x) > 0) ? (x) : (-(x)))

long long input[MAX];

int compare(const void*, const void*);

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%lld", input + i);

	qsort(input, n, sizeof(long long), compare);

	int a, b, c;
	a = 0;
	b = 1;
	c = n - 1;


	long long temp = input[a] + input[b] + input[c];

	for (int i = 0; i < n; ++i)
	{
		int j = i + 1;
		int k = n - 1;

		while (j < k)
		{
			if (ABS(input[i] + input[j] + input[k]) < ABS(temp))
			{
				a = i;
				b = j;
				c = k;

				temp = input[i] + input[j] + input[k];
				if (temp > 0)
					--k;
				else
					++j;
			}
			else if (input[i] + input[j] + input[k] > 0)
				--k;
			else
				++j;
		}
	}

	printf("%lld %lld %lld\n", input[a], input[b], input[c]);

	return 0;
}

int compare(const void* a, const void* b)
{
	if ((*(long long*)a) > (*(long long*)b))
		return 1;
	else if ((*(long long*)a) == (*(long long*)b))
		return 0;
	else
		return -1;
}
