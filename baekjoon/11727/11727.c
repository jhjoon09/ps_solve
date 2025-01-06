#include <stdio.h>                                                                                                      
int main(void)
{
	int n;
	int i_count[1001] = {0 ,};

	scanf("%d", &n);

	i_count[1] = 1;
	i_count[2] = 3;

	for(int i = 3; i <= n; ++i)
	{
		i_count[i] = i_count[i-1] + 2 * i_count[i-2];
		i_count[i] %= 10007;
	}

	printf("%d\n", i_count[n]);

	return 0;
}
