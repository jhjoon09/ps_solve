#include <stdio.h>
#define INF 10000000
#define MAX 66000
int W[16][16];
int dp[MAX];

int mult[16];

int main(void)
{
	int N;

	scanf("%d", &N);

	int temp = 1;

	for(int i = 0; i < N; ++i)
	{
		mult[i] = temp;
		temp *= 2;

		for(int j = 0; j < N; ++j)
		{
			scanf("%d", W[i] + j);

			if(W[i][j] == 0)
				W[i][j] = INF;
		}
	}


}
