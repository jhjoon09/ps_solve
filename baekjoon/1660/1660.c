#include <stdio.h>

int count[300001];
int sum[130];

int main(void)
{
	int n;

	scanf("%d", &n);

	sum[0] = 0;
	sum[1] = 1;

	int i;

	for(i = 2; i <= 122; ++i)
	{
		sum[i] = sum[i-1] + (i *(i+1))/2;
		if(sum[i] >= n)
			break;
	}
	
	count[0] = 0;
	count[1] = 1;

	for(int i = 2; i <= n; ++i)
	{
		int min = 3000001;
		for(int j = 1; sum[j] <= i; ++j)
		{
			int k = i - sum[j];
			if(count[k] + 1 < min)
				min = count[k] + 1;
		}

		count[i] = min;
	}
	printf("%d\n", count[n]);

	return 0;
}
