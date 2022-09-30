#include <stdio.h>
#define MAX 2147483647

long long mult(int, int, int);

int main(void)
{
	int a,b,c;

	scanf("%d %d %d", &a, &b, &c);

	long long data = mult(a, b, c);

	printf("%lld\n", data);

	return 0;
}

long long mult(int a, int b, int c)
{
	if(b == 0)
		return 1LL;
	
	if(b == 1)
		return (long long)(a % c);
	
	long long data = mult(a, b/2, c);
	
	if(b % 2 == 0)
	{
		return (data * data) % c;
	}
	else
	{
		return (((data*data)%c)*a) % c;
	}
}
