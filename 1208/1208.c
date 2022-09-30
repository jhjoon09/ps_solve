#include <stdio.h>
#define MAX 4000000

long long dp[MAX * 2 + 1];

int main(void)
{
	int n,s;

	scanf("%d %d", &n, &s);

	while(n>0)
	{
		--n;

		int a;
		scanf("%d", &a);

		if(a<0)
		{
			for(int i = -a; i <= MAX * 2; ++i)
				dp[i+a] += dp[i];
		}
		else
		{
			for(int i = MAX*2 - a; i >= 0; --i)
				dp[i+a] += dp[i];
		}
	
		++dp[MAX+a];

	}
	
	printf("%lld\n", dp[s+MAX]);

	return 0;
}
