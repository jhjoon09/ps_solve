#include <stdio.h>
#include <string.h>
#define MAX 1000

char sent_1[MAX + 1];
char sent_2[MAX + 1];
char lcs[MAX + 1];

int dp[MAX + 1][MAX + 1];
int max;

int cal_lcs(int, int);
int find_lcs(int, int);

int main(void)
{
	scanf("%s", sent_1);
	scanf("%s", sent_2);

	max = cal_lcs(0, 0);

	printf("%d\n", max);

	if (max == 0)
		return 0;

	find_lcs(0, 0);

	printf("%s\n", lcs);

	return 0;
}

int cal_lcs(int a, int b)
{
	if (sent_1[a] == '\0' || sent_2[b] == '\0')
		return 0;

	if (dp[a][b] != 0)
		return dp[a][b];

	int max = 0;

	if (sent_1[a] == sent_2[b])
		max = 1 + cal_lcs(a + 1, b + 1);
	else
	{
		max = cal_lcs(a + 1, b);
		int temp = cal_lcs(a, b + 1);


		if (temp > max)
			max = temp;
	}

	dp[a][b] = max;

	return max;
}

int find_lcs(int a, int b)
{
	lcs[max] = '\0';

	while (dp[a][b] != 0)
	{
		if (dp[a][b] == dp[a][b + 1])
			++b;
		else if (dp[a][b] == dp[a + 1][b])
			++a;
		else if (dp[a][b] == dp[a + 1][b + 1] + 1)
		{
			lcs[max - dp[a][b]] = sent_1[a];
			++a;
			++b;
		}

	}

	return 0;
}
