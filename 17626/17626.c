#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i_least[50001] = {0 ,};

	int n = 0;

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i)
	{
		i_least[i] = INT_MAX;

		for(int j = 1; j*j <= i; ++j)
		{
			if(i_least[i] > i_least[i - j*j] + 1)
				i_least[i] = i_least[i - j*j] + 1;
		}
	}

	printf("%d\n", i_least[n]);

	return 0;
}
