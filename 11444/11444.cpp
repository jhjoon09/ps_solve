#include <stdio.h>
#include <map>
#define DIV 1000000007

using namespace std;
//dp how?

map<int, long long> dp;

long long fibona(long long n);

int main(void)
{
	long long N;

	scanf("%lld", &N);

	printf("%lld\n", fibona(N));

	return 0;
}

long long fibona(long long n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;

	if(dp.find(n) != dp.end())
	{
		return dp.find(n)->second;
	}
	//a+b = (a-1)b + a(b+1)

	if(n % 2 == 0)
	{
		int a = n/2 + 1;
		int b = n/2 - 1;

		// x*x-1 + x+1 * x
		// x *(x-1) + x * x + x * (x-1)

		dp.insert({n, (fibona(n/2) * ((fibona(n/2) + fibona(n/2-1)*2) % DIV)) % DIV});

		return dp.find(n)->second;
	}
	else
	{
		int a = n/2 + 1;
		int b = n/2;

		//x*x + (x+1)(x+1)

		dp.insert({n, ((fibona(n/2) * fibona(n/2)) % DIV + (fibona(n/2+1) * fibona(n/2 + 1)) % DIV) % DIV});

		return dp.find(n)->second;
	}
}
