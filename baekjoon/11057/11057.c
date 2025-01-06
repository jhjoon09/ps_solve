#include <stdio.h>
#define DIV 10007

int main(void)
{
	int count[1000][10] = {0, };
	int n;
	scanf("%d", &n);

	for(int i = 0; i <= 9; ++i)
		count[0][i] = 1;


	for(int i = 1; i < n; ++i)
	{
		count[i][0] = count[i-1][0];

		for(int j = 1; j <= 9; ++j)
		{
			count[i][j] = (count[i-1][j] + count[i][j-1]) % DIV;
		}
	}

	int sum = 0;

	for(int i = 0; i <= 9; ++i)
		sum += count[n-1][i];

	printf("%d\n", sum % DIV);

	return 0;
}
