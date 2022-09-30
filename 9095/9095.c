#include <stdio.h>

int i_count[11];

int cal(int);

int main(void)
{
	int t, n;

	i_count[1] = 1;
	i_count[2] = 2;
	i_count[3] = 4;

	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		scanf("%d", &n);
	
		printf("%d\n", cal(n));
	}

	return 0;
}

int cal(int n)
{
	if(n < 0)
		return 0;

	if(i_count[n] != 0)
		return i_count[n];

	i_count[n] = cal(n-1) + cal(n-2) + cal(n-3);

	return i_count[n];
}
