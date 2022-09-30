#include <stdio.h>                                                                                                      
#define DIV 1000000007

long long S, N;

long long gcd(long long, long long);
long long rev_mod(long long, int);

int main(void)
{
	int M;

	scanf("%d", &M);

	scanf("%lld %lld", &N, &S);

	for (int i = 1; i < M; ++i)
	{
		long long a, b;

		scanf("%lld %lld", &b, &a);

		S = (S * b + N * a) % DIV;
		N = (b * N) % DIV;
	}

	long long d = gcd(S, N);

	S /= d;
	N /= d;

	printf("%lld\n", (S * rev_mod(N, DIV-2)) % DIV);

	return 0;
}

long long gcd(long long a, long long b)
{
	if (a < b)
	{
		long long c = a;
		a = b;
		b = c;
	}

	while (b != 0)
	{
		long long temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

long long rev_mod(long long a, int b)
{
	if(b == 1)
		return a;

	if(b % 2 == 1)
		return (a * rev_mod(a, b-1)) % DIV;

	long long temp = rev_mod(a, b/2);

	return (temp * temp) % DIV;
}
