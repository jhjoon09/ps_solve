#include <stdio.h>

int c[30][30];

int comb(int a, int b);

int main(void)
{
	int t = 0;
	int n = 0; int m = 0;

	scanf("%d", &t);

	for(int i = 0; i < t; ++i)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", comb(n, m));
	}

	return 0;
}

int comb(int a, int b)
{
	if(c[a][b] != 0)
		return c[a][b];
	
	if(a == 0 || a == b)
	{
		c[a][b] = 1;
		return 1;
	}
	c[a][b] = comb(a-1, b-1) + comb(a, b-1);

	return c[a][b];

}
