#include <stdio.h>
#include <stdlib.h>

long long gcd(long long, long long);
long long lcm(long long, long long);

int main(void)
{
	long long K, Q;

	scanf("%lld %lld", &K, &Q);

	long long* dp = (long long*)malloc(sizeof(long long) * (K + 1));

	long long temp = 1;
	long long count = 1;

	while(count <= K && temp != 0)
	{
		dp[count] = temp;
		++count;

		temp = (temp * count) % K;
	}

	for(int i = 0; i < Q; ++i)
	{
		long long input;

		scanf("%lld", &input);

		input = input % K;

		long long result = lcm(K, input) / input;

		for(long long i = 1; i <= count; ++i)
		{
			if(dp[i] % result == 0)
			{
				printf("%lld ", i);
				break;
			}

			if(i == count)
				printf("%lld ", count);
		}
	}

	printf("\n");

	return 0;
}

long long gcd(long long a, long long b)
{
	long long c;

	while(b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}

	return a;
}

long long lcm(long long a, long long b)
{
	long long c = (a*b)/gcd(a,b);
	return c;
}        
