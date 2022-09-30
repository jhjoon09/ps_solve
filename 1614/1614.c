#include <stdio.h>

int main(void)
{
	int hurt;
	long long count;

	scanf("%d %lld", &hurt, &count);

	long long sum = 0;

	switch (hurt)
	{
		case 1:
			sum = count * 8;
			break;
		case 2:
			sum = count/2 * 8 + 1 + count%2 * 6;
			break;
		case 3:
			sum = count/2 * 8 + 2 + count%2 *4;
			break;
		case 4:
			sum = (count/2) * 8 + 3 + count%2 * 2;
			break;
		case 5:
			sum = count * 8 + 4;
			break;
	}

	printf("%lld\n", sum);

	return 0;
}
