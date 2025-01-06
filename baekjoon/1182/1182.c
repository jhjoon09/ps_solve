#include <stdio.h>

int n,s;
int list[20];

int func(int, int);

int main(void)
{
	scanf("%d %d", &n, &s);

	for(int i = 0; i < n; ++i)
		scanf("%d", list + i);

	int count = func(list[0], 1) + func(0 , 1);
	
	if(s == 0)
		--count;

	printf("%d\n", count);

	return 0;
}

int func(int sum, int k)
{
	if( k >= n)
	{
		if(sum == s)
			return 1;
		else
			return 0;
	}

	return func(sum + list[k], k +1) + func(sum, k+1);
}
