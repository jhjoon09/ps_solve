#include <stdio.h>
#define MAX 100000

int height[MAX];

long long cal_area(int, int);
long long mid_start(int, int);

int main(void)
{
	int n;

	scanf("%d", &n);

	while (n != 0)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", height + i);

		printf("%lld\n", cal_area(0, n - 1));

		scanf("%d", &n);
	}


	return 0;
}

long long cal_area(int start, int end)
{
	if (start == end)
		return height[start];

	if (start > end)
		return 0;

	int mid = (start + end) / 2;

	long long max = mid_start(start, end);
	long long temp = cal_area(start, mid-1);

	max = (max > temp) ? max : temp;

	temp = cal_area(mid + 1, end);

	max = (max > temp) ? max : temp;

	return max;
}

long long mid_start(int start, int end)
{
	int t_s = (start + end) / 2;
	int t_e = (start + end) / 2;

	long long max = height[t_s];
	long long h_max = max;

	while (t_s != start && t_e != end)
	{
		if (height[t_s - 1] > height[t_e + 1])
		{
			--t_s;

			if (h_max > height[t_s])
				h_max = height[t_s];
		}
		else
		{
			++t_e;

			if (h_max > height[t_e])
				h_max = height[t_e];
		}

		if (max < h_max * (t_e - t_s + 1))
			max = h_max * (t_e - t_s + 1);
	}

	if (t_s == start)
	{
		while (t_e != end)
		{
			++t_e;

			if (h_max > height[t_e])
				h_max = height[t_e];

			if (max < h_max * (t_e - t_s + 1))
				max = h_max * (t_e - t_s + 1);
		}
	}

	if (t_e == end)
	{
		while (t_s != start)
		{
			--t_s;

			if (h_max > height[t_s])
				h_max = height[t_s];

			if (max < h_max * (t_e - t_s + 1))
				max = h_max * (t_e - t_s + 1);

		}
	}

	return max;
}
