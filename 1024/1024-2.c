#include <stdio.h>

int main(void)
{
	int n, l;
	scanf("%d %d", &n, &l);

	int a = 0;

	while(1)
	{
		if(l > 101)
		{
			break;
		}

		if(l % 2 == 1)
		{
			if(n % l == 0)
			{
				a = (n/l) - (l/2);
				if(a >= 0)
				{
					for(int i = 0; i < l - 1; ++i)
						printf("%d ", a + i);

					printf("%d", a + l - 1);

					return 0;
				}
			}
		}
		else
		{
			if(n != 2 * l)
			{
				if(((n - l / 2) % l) == 0)
				{
					a = (n - l/2) / l - (l/2 - 1);
					if(a >= 0)
					{
						for(int i = 0; i < l - 1; ++i)
							printf("%d ", a + i);

						printf("%d", a + l - 1);

						return 0;
					}
				}
			}
		}

		++l;
	}

	printf("-1");

	return 0;
}          

