#include <stdio.h>

int main(void)
{
	int n;
	unsigned long long result = 1;

	scanf("%d", &n);


	for(int i = 1;i <= n; ++i)
	{
		result *= i;

		while(result % 10 == 0)
			result /= 10;

		result %= 10000000000000;
	}

	result %= 100000;

	if(result / 10 == 0)
		printf("0000%llu\n", result);
	else if(result / 100 == 0)
		printf("000%llu\n", result);
	else if(result / 1000 == 0)
		printf("00%llu\n", result);
	else if(result / 10000 == 0)
		printf("0%llu\n", result);
	else
		printf("%llu\n", result);

	return 0;
	
}
