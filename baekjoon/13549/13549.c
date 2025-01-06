#include <stdio.h>
#include <string.h>
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


	for(int i = 0; i < MAX*2; ++i)
		time[i] = max + 1;


	time[n] = 0;

	while(start != end)
	{
		if(que[start] == k)
		{
			printf("%d\n", time[que[start]]);
			return 0;
		}


		int input = que[start]-1;
		if(check_able(input, time[que[start]] +1) && time[input] > time[que[start]] + 1)
		{
			time[input] = time[que[start]] + 1;
			que[end] = input;
			++end;
		}

		input = que[start]+1;

		if(check_able(input, time[que[start]]+1) && time[input] > time[que[start]] + 1)
		{
			time[input] = time[que[start]] + 1;
			que[end] = input;
			++end;
		}

		input = que[start] * 2;

		if(check_able(input, time[que[start]]) && time[input] > time[que[start]])
		{
			time[input] = time[que[start]];
			que[start] = input;
			--start;
		}

		++start;
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

	return 1;
}                    
