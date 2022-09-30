#include <stdio.h>

int count_bi(int);

int main(void)
{
	int N;
	int m;

	scanf("%d", &N);

	m = count_bi(N);


	return 0;
}

int count_bi(int a)
{
	int i = 0;

	while(a != 0)
	{
		a /= 2;
		++i;
	}

	return i;
}
