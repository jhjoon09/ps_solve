#include <stdio.h>
#include <limits.h>
#define MAX 1000000

long long dp[MAX + 1];
int F,S,G,U,D;

int go_up(int, int);

int main(void)
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	for(int i = 0; i <= F; ++i)
		dp[i] = LLONG_MAX;

	if(S == G)
	{
		printf("0\n");
		return 0;
	}

	if(go_up(S, 0) == 1)
		printf("%lld\n", dp[G]);
	else
		printf("use the stairs\n");

	return 0;	
}

int go_up(int pos, int count)
{
	if(pos <= 0 || pos > F)
		return -1;

	if(dp[pos] <= count)
		return -1;
	
	dp[pos] = count;

	if(pos == G)
		return 1;

	int a = go_up(pos+U, count+1);
	int b = go_up(pos-D, count+1);

	return a>b ? a : b;
}
