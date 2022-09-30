#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#define MAX 1000001

int list[MAX];
int trace[MAX];
int LST[MAX];

int b_search(int, int, int);
int trace_LST(int);

int main(void)
{
	int N;
	int max_pos = 0, lst_count = 0;

	LST[0] = INT_MIN;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", list + i);

		if (LST[lst_count] < list[i])
		{
			trace[i] = LST[lst_count];

			++lst_count;
			LST[lst_count] = list[i];
			max_pos = i;
		}
		else
		{
			int pos = b_search(1, lst_count, list[i]);

			LST[pos] = list[i];
			trace[i] = LST[pos - 1];
		}
	}

	printf("%d\n", lst_count);

	trace_LST(max_pos);

	return 0;
}


int b_search(int start, int end, int val)
{
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (LST[mid] == val)
			return mid;

		if (LST[mid] > val)
			end = mid;
		else
			start = mid + 1;
	}

	return end;
}


int trace_LST(int pos)
{
	if (pos < 0)
		return 1;

	if (trace[pos] == INT_MIN)
	{
		printf("%d ", list[pos]);
		return 1;
	}

	int temp = pos;

	while (list[temp] != trace[pos])
		--temp;

	trace_LST(temp);

	printf("%d ", list[pos]);

	return 0;
}
