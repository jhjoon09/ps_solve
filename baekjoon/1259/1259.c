#include <stdio.h>

int main(void)
{
	int input;

	scanf("%d", &input);

	while(input != 0)
	{
		int t;
		int flag = 1;
		int n = 1;

		while(input /(n * 10) != 0)
			n *= 10;

		t = input;

		while(t != 0)
		{
			if( t%10 != t/n)
			{
				flag = 0;
				break;
			}

			t = (t%n) / 10;

			n =	n / 100;
		}

		if(flag)
			printf("yes\n");
		else
			printf("no\n");

		scanf("%d", &input);


	}

	return 0;
}
