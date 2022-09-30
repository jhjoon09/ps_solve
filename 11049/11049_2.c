#include <stdio.h>
#include <limits.h>

int dp[500][500];
int input[500][2];

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d %d", input[i] + 0, input[i] + 1);

	for(int i = 1; i < n; ++i)
	{
		for(int j = i-1; j >= 0; --j)
		{
			int min = INT_MAX;

			for(int k = j; k < i; ++k)
			{
				int temp =  dp[j][k] + dp[k+1][i] + input[j][0] * input[k][1] * input[i][1];

				if(min > temp)
					min = temp;
			}

			dp[j][i] = min;
		}
	}

	printf("%d\n", dp[0][n-1]);

	return 0;
}
