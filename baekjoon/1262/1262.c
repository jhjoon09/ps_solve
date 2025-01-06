#include <stdio.h>

char dia(int x, int y, int n);

int main(void)
{
	int n,r1,c1,r2,c2;

	scanf("%d %d %d %d %d", &n, &r1, &c1, &r2, &c2);

	for(int i = r1; i <= r2; ++i)
	{
		for(int j = c1; j <= c2; ++j)
		{
			printf("%c", dia(i+1, j+1, n));
		}
		printf("\n");
	}

	return 0;

}

char dia(int x, int y, int n)
{
	int a = x % (2*n -1);
	int b = y % (2*n -1);

	if(a == 0)
		++a;

	if(b == 0)
		++b;

	int count = ((a>=n) ? a-n : n-a) + ((b>=n) ? b-n : n-b);

	if(count >= n)
		return '.';
	else
		return 'a' + count % ('z' - 'a' + 1);
}
