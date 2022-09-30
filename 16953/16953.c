#include <stdio.h>

int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);

	int count = 0;

	while(a < b)
	{
		if(b % 2 == 0)
		{
			b /= 2;
			++count;
		}
		else if(b % 10 == 1)
		{
			b /= 10;
			++count;
		}
		else
			break;
	}

	if(a == b)
		printf("%d\n", count + 1);
	else
		printf("-1\n");

	return 0;
}
