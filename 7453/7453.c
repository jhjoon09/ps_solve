#include <stdio.h>
#include <stdlib.h>
#define MAX 4000

int input[MAX][4];
int sum1[MAX * MAX];
int sum2[MAX * MAX];

int compare(const void*, const void*);

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d %d %d %d", input[i] + 0, input[i] + 1, input[i] + 2, input[i] + 3);


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			sum1[i * n + j] = input[i][0] + input[j][1];

			sum2[i * n + j] = input[i][2] + input[j][3];
		}
	}

	qsort(sum1, n * n, sizeof(int), compare);
	qsort(sum2, n * n, sizeof(int), compare);

	int pos1 = 0;
	int pos2 = n * n - 1;
	long long count = 0;

	while (pos1 < n * n && pos2 >= 0)
	{
		if (sum1[pos1] + sum2[pos2] > 0)
			--pos2;
		else if (sum1[pos1] + sum2[pos2] < 0)
			++pos1;
		else
		{
			long long count1 = 0, count2 = 0;

			int temp = sum1[pos1];

			while(sum1[pos1] == temp && pos1 < n*n)
				++count1, ++pos1;

			while(sum2[pos2] + temp == 0 && pos2 >= 0)
				++count2, --pos2;

			count += count1 * count2;
		}
	}

	printf("%lld\n", count);

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = *((int*)a);
	int y = *((int*)b);

	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	else
		return -1;
}
