#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4000000

int input[MAX+1];
int visit[MAX+1];
int N, M, K;

int b_search(int, int, int);

int main(void)
{
	scanf("%d %d %d", &N, &M, &K);

	int temp;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &temp);

		++visit[temp - 1];
	}

	for (int i = 1; i <= N; ++i)
		visit[i] += visit[i-1];

	for (int i = N; i >= 0; --i)
	{
		input[visit[i]-1] = i + 1;
	}

	memset(visit, 0, sizeof(int) * N + 1);

	for (int i = 0; i < K; ++i)
	{
		int out;
		scanf("%d", &out);

		int pos = b_search(0, M - 1, out);

		while (input[pos] <= out || visit[pos] == 1)
			++pos;

		printf("%d\n", input[pos]);

		visit[pos] = 1;
	}

	return 0;
}

int b_search(int start, int end, int data)
{
	while (start < end)
	{
		int mid = (start + end) / 2;

		if (input[mid] == data)
			return mid;
		
		if(input[end] < data)
			return end+1;

		if (input[mid] > data)
			end = mid - 1;
		else if (input[mid] < data)
			start = mid + 1;
	}

	return end;
}
