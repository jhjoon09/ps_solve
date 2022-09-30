#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000

int time[MAX * 2], que[MAX * 2];
int n, k;

int check_able(int, int);

int main(void)
{
	scanf("%d %d", &n, &k);
	
	if(n >= k)
	{
		printf("%d\n", n-k);
		return 0;
	}

	int max = k-n;

	que[0] = n;
	int start = 0;
	int end = 1;
	int s_temp = 0;
	int e_temp = 0;

	for(int i = 0; i <= max; ++i)
	{
		s_temp = start;
		e_temp = end;
		start = end;
		for(int j = s_temp; j < e_temp; ++j)
		{
			if(que[j] == k)
			{
				printf("%d\n", i);
				return 0;
			}

			int input = que[j]-1;
			if(check_able(input, i +1) && time[input] == 0)
			{
				time[input] = i + 1;
				que[end] = input;
				++end;
			}

			input = que[j]+1;

			if(check_able(input, i+1) && time[input] == 0)
			{
				time[input] = i + 1;
				que[end] = input;
				++end;
			}

			input = que[j] * 2;

			if(check_able(input, i+1) && time[input] == 0)
			{
				time[input] = i + 1;
				que[end] = input;
				++end;
			}

		}

	}

	return 0;
}

int check_able(int pos, int time)
{
	if(pos < 0)
		return 0;

	if(pos == n)
		return 0;

	if(pos >= 2 * MAX)
		return 0;

	if(pos > k)
	{
		if(pos-k+time > k-n)
			return 0;
	}
}
