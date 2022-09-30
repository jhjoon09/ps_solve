#include <stdio.h>

int a[1000];
int b[1000];

int euc(int a, int b);

int main(void)
{
	int t = 0;
	scanf("%d", &t);

	for(int i = 0; i < t; ++i)
		scanf("%d %d", a + i, b + i);
	
	int gcd = 0;
	int lcm = 0;

	for(int i = 0; i < t; ++i)
	{
		gcd = euc(a[i], b[i]);
		lcm = (a[i] * b[i]) / gcd;

		printf("%d\n", lcm);
	}

	return 0;
}

int euc(int a, int b)
{
	int temp = 0;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	while(a % b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}

	return b;
}
