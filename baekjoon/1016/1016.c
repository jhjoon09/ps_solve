#include <stdio.h>
#define MAX 1000000

int mult_nono[MAX+1];

int main(void)
{
	long long min,max;

	scanf("%lld %lld", &min, &max);

	for(long long i = 2; i * i <= max; ++i)
	{
		for(long long j = ((min-1)/(i*i)) * (i*i) + i*i; j <= max; j += i*i)
		{
			mult_nono[j - min] = 1;
		}
	}

	int count = 0;

	for(int i = 0; i <= max-min; ++i)
	{
		if(mult_nono[i] == 0)
			++count;
	}

	printf("%d\n", count);

	return 0;
}
