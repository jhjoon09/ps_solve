#include <stdio.h>                                                                                                      

int tower[500001];
int dp[500001];

int main(void)
{
	int N;
	int max_pos = 1;

	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
		scanf("%d", tower + i);

	for (int i = 2; i <= N; ++i)
	{
		if(tower[i] > tower[max_pos])
		{
			dp[i] = 0;
			max_pos = i;
		}
		else if(tower[i] == tower[max_pos])
		{
			dp[i] = max_pos;
			max_pos = i;
		}
		else
		{
			for (int j = i - 1; j > 0; --j)
			{
				if (tower[i] <= tower[j])
				{
					dp[i] = j;
					break;
				}
				else
				{
					if (dp[j] == 0)
						dp[i] = 0;
					else
						j = dp[j] + 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i)
		printf("%d ", dp[i]);

	printf("\n");

	return 0;
}
