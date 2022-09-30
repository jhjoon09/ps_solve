#include <stdio.h>
#define MAX 100000
#define DIV 9901

int count[2][MAX+1];

int main(void)
{
	int n;

	scanf("%d", &n);

	count[0][1] = 1;
	count[1][1] = 2;

	for(int i = 2; i <= n; ++i)
	{
		count[0][i] = count[1][i-1] + count[0][i-1];
		count[1][i] = count[0][i-1]*2 + count[1][i-1];
		
		count[0][i] %= DIV;
		count[1][i] %= DIV;
	}

	int result = count[1][n] + count[0][n];

	printf("%d\n", result % DIV);

	return 0;
}
