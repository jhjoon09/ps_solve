#include <stdio.h>
#define MAX 2000

int dp[MAX][MAX];
int list[MAX];
int n;

int check_paln(int, int);

int main(void)
{
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", list + i);

	int t;
	scanf("%d", &t);
	
	while(t > 0)
	{
		--t;
		int a,b;
		scanf("%d %d", &a, &b);

		if(check_paln(a-1, b-1) == 1)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}

int check_paln(int start, int end)
{
	if(start + 1 == end)
	{
		if(list[start] == list[end])
		{
			dp[start][end] = 1;
			return 1;
		}
		else
		{
			dp[start][end] = -1;
			return -1;
		}

	}
	if(start == end)
		return 1;

	if(dp[start][end] == 1)
		return 1;
	else if(dp[start][end] == -1)
		return -1;

	if(list[start] != list[end])
	{
		dp[start][end] = -1;
	
		return -1;
	}

	if(check_paln(start+1, end-1) == 1)
		dp[start][end] = 1;
	else
		dp[start][end] = -1;

	return dp[start][end];
}
