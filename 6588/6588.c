#include <stdio.h>
#define MAX 1000000

int prime[MAX];

int eratos(int);

int main(void)
{
	int n;

	eratos(MAX);

	scanf("%d", &n);

	while (n != 0)
	{
		int temp = 0;
		for (int i = 2; i * 2 <= n; ++i)
		{
			if (prime[i] == 0)
				continue;

			if (prime[i] != 0 && prime[n - i] != 0)
			{
				temp = i;
				break;
			}
		}

		if (temp == 0)
			printf("Goldbach's conjecture is wrong\n");
		else
			printf("%d = %d + %d\n", n, temp, n - temp);


		scanf("%d", &n);
	}

	return 0;
}

int eratos(int n)
{
	for (int i = 2; i < n; ++i)
		prime[i] = 1;

	for (int i = 2; i < n; ++i)
	{
		if (i * i >= n)
			break;

		if (prime[i] == 1)
		{
			for (int j = i * i; j < n; j += i)
			{
				prime[j] = 0;
			}
		}
	}

	return 0;
}
