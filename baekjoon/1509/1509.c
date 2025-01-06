#include <stdio.h>

int dp[2500];
char input[2501];

int is_paln(int, int);

int main(void)
{
	scanf("%s", input);

	int pos = 0;

	dp[0] = 1;

	while(input[pos] != '\0')
	{
		if(is_paln(0, pos) == 1)
			dp[pos] = 1;
		else
		{
			dp[pos] = dp[pos-1] + 1;

			for(int i = 1; i < pos; ++i)
			{
				if(dp[pos] > dp[i-1] + 1)
				{
					if(is_paln(i, pos) == 1)
						dp[pos] = dp[i-1] + 1;
				}
			}
		}
		++pos;
	}

	printf("%d\n", dp[pos-1]);

	return 0;
}

int is_paln(int start, int end)
{
	while(start < end)
	{
		if(input[start] != input[end])
			return 0;

		++start;                
		--end;
	}

	return 1;
} 
