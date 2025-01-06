#include <stdio.h>
#define DIV 1000000000

long long dp[201][201];

int main(void)
{
	int N,K;

	scanf("%d %d", &N, &K);

	for(int i = 0; i <= N; ++i)
		dp[1][i] = 1;

	for(int i = 2; i <= K; ++i)
	{
		for(int j = 0; j <= N; ++j)
		{
			for(int k = 0; k <= j; ++k)
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % DIV;
		}
	}

	printf("%lld\n", dp[K][N]);

	return 0;
}
