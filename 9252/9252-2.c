#include <stdio.h>
#include <string.h>
#define MAX 1000

char sent_1[MAX + 1];
char sent_2[MAX + 1];
char lcs[MAX + 1];

int dp[MAX + 1][MAX + 1];
int max;

int cal_lcs(void);
int find_lcs(int, int);

int main(void)
{
	scanf("%s", sent_1);
	scanf("%s", sent_2);

	cal_lcs();

	int len_1 = strlen(sent_1);
	int len_2 = strlen(sent_2);

	printf("%d\n", dp[len_1][len_2]);

	if (dp[len_1][len_2] == 0)
		return 0;

	//find_lcs(0, 0);

	find_lcs(len_1, len_2);

	printf("%s\n", lcs);

	return 0;
}

int cal_lcs(void)
{
	for (int i = 1; sent_1[i-1] != '\0'; ++i)
	{
		for (int j = 1; sent_2[j-1] != '\0'; ++j)
		{
			if (sent_1[i - 1] == sent_2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] < dp[i][j - 1]) {
					dp[i][j] = dp[i][j - 1];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	return max;
}

/*
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
 */

int find_lcs(int a, int b)
{
	lcs[max] = '\0';

	while (a >= 1 && b >= 1)
	{
		if (dp[a][b] == dp[a-1][b])
			--a;
		else if (dp[a][b] == dp[a][b-1])
			--b;
		else
		{
			lcs[dp[a-1][b-1]] = sent_1[a-1];
			--a;
			--b;
		}

	}
}
