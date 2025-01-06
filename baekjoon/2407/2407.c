#include <stdio.h>
#define MAX 100000000000000

long long result[101][101];
long long result2[101][101];

int comb(int, int);
int n_digit(long long);

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	comb(n, k);

	if(result2[n][k] == 0)
		printf("%lld\n", result[n][k]);
	else
	{
		printf("%lld", result2[n][k]);
		//make zero
		int r_dig = n_digit(result[n][k]);
		int m_dig = n_digit(MAX);

		for(int i = r_dig; i < m_dig-1; ++i)
			printf("0");

		printf("%lld\n", result[n][k]);
	}

	return 0;
}

int comb(int n, int k)
{
	if(n == k)
	{
		result[n][k] = 1LL;
		return 1;
	}

	if(k == 1)
	{ 
		result[n][k] = (long long)n;
		return 1;
	}

	if(result[n][k] != 0 || result2[n][k] != 0)
		return 1;

	comb(n-1, k-1);
	comb(n-1, k);

	result[n][k] = result[n-1][k-1] + result[n-1][k];
	result2[n][k] = result2[n-1][k-1] + result2[n-1][k] + result[n][k] / MAX;
	result[n][k] %= MAX;

	return 1;
}

int n_digit(long long i)
{
	int count = 0;

	while(i > 0)
	{
		++count;
		i /= 10;
	}

	return count;
}
