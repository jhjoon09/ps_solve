#include <stdio.h>
#include <limits.h>

#define MAX 1000000

int long_end[MAX + 1];

int search(int, int, int);

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		long_end[i] = INT_MAX;

	int end = 1;
	for (int i = 1; i <= n; ++i)
	{
		int input;

		scanf("%d", &input);

		if(long_end[end] > input && long_end[end-1] < input)
		{
			long_end[end] = input;
			++end;
		}
		else
		{
			int pos = search(0, end, input);

			long_end[pos] = input;
		}
	}

	printf("%d\n", end-1);

	return 0;
}

int search(int start, int end, int data)
{
	while(start < end)
	{
		int mid = (start + end)/2;

		if(long_end[mid] == data)
			return mid;
		else if(long_end[mid] > data)
			end = mid;
		else
			start = mid+1;
	}

	return end;
}
