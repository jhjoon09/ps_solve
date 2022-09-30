#include <stdio.h>

int sticker[100000][2];
int dp[100000][2];
int N;

int get_stick(int, int);

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t > 0)
	{
		--t;

		scanf("%d", &N);

		for(int i = 0; i < N; ++i)
		{
			dp[i][0] = -1;
			dp[i][1] = -1;
			scanf("%d", &sticker[i][0]);
		}
		for(int i = 0; i < N; ++i)
			scanf("%d", &sticker[i][1]);

		int max = 0;

		int temp = get_stick(0, 0);

		if(temp > max)
			max = temp;

		temp = get_stick(0, 1);

		if(temp > max)
			max = temp;

		printf("%d\n", max);
	}

	return 0;
}

int get_stick(int x, int y)
{
	if(x >= N)
		return 0;

	if(dp[x][y] != -1)
		return dp[x][y];

	int max = sticker[x][y];

	int t_y = (y+1) % 2;

	int a = get_stick(x+1, t_y);
	int b = get_stick(x+2, t_y);

	max += (a>b ? a : b);

	dp[x][y] = max;

	return max;
}
