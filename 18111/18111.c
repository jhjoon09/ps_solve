#include <stdio.h>
#include <limits.h>

int map[500][500];

int main(void)
{
	int n,m;
	long long b;

	scanf("%d %d %lld", &n, &m, &b);

	long long sum = b;
	int high = 0;
	int low = INT_MAX;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", &map[i][j]);

			if(map[i][j] > high)
				high = map[i][j];
	
			if(map[i][j] < low)
				low = map[i][j];

			sum += map[i][j];
		}
	}

	int avg = sum / (m * n);

	if(high > avg)
		high = avg;

	long long time = LLONG_MAX;
	int level = 0;

	for(int x = low; x <= high; ++x)
	{
		long long temp = 0;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(map[i][j] > x)
					temp += (map[i][j] - x) * 2;
				else
					temp += x - map[i][j];
			}
		}

		if(time >= temp)
		{
			time = temp;
			level = x;
		}
	}

	printf("%lld %d\n", time, level);

	return 0;
}
