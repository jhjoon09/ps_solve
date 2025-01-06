#include <stdio.h>

int main(void)
{
	int input;
	int sum = 0;

	for(int i = 1; i <= 5; ++i)
	{
		scanf("%d", &input);
		sum += input * input;
	}

	printf("%d", sum % 10);

	return 0;
}
