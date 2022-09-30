#include <stdio.h>
#define MAX 100000
#define ABS(x) (((x) > 0) ? (x) : -(x))

int water[MAX];

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", water + i);

	int min = 0;
	int max = n - 1;
	int temp = water[max] + water[min];

	int a = 0, b = n - 1;

	while (a < b)
	{
		if (ABS(water[a] + water[b]) < ABS(temp))
		{
			min = a;
			max = b;

			temp = water[a] + water[b];

			if (ABS(water[a] + water[b]) == ABS(temp))
			{
				if (ABS(water[a + 1] + water[b]) > ABS(water[a] + water[b - 1]))
					--b;
				else
					++a;
			}
		}
		else if (water[a] + water[b] > 0)
		{
			--b;
		}
		else
		{
			++a;
		}
	}

	printf("%d %d\n", water[min], water[max]);

	return 0;
}
