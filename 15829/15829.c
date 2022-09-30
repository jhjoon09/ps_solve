#include <stdio.h>
#define DIV 1234567891

int main(void)
{
	int n;
	char line[51];

	scanf("%d", &n);
	scanf("%s", line);

	long long hash = 0;

	for(int i = n-1; i >= 0; --i)
	{
		hash *= 31;
		hash += (line[i] - 'a' + 1);
		hash %= DIV;
	}

	printf("%lld\n", hash);
	
	return 0;
}
