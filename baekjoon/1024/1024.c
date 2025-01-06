#include <stdio.h>

int main(void)
{
	int n, l;
	scanf("%d %d", &n, &l);

	int a = 0;
	
	for(int i = l; i <= 100; ++i)
	{
		int temp = n - i*(i+1) / 2;

		if(temp % i == 0)
		{
			int j = temp / i + 1;

			if(j >= 0)
			{
				for(int k = 0; k < i; ++k)
					printf("%d ", j + k);

				return 0;
			}
		}
	}

	printf("-1");

	return 0;
}
