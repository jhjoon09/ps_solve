#include <stdio.h>
#include <stdlib.h>

int list[8][2];
int temp[8];
int count = 0;
int m;

int compare(const void*, const void*);
int n_m(int, int);

int main(void)
{
	int n;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);

		int flag = 1;

		for (int j = 0; j < count; ++j)
		{
			if (list[j][0] == temp)
			{
				++list[j][1];
				flag = 0;
				break;
			}
		}

		if (flag == 1)
		{
			list[count][0] = temp;
			list[count][1] = 1;
			++count;
		}

	}

	qsort(list, count, sizeof(int) * 2, compare);

	n_m(0, 0);

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = ((int*)a)[0];
	int y = ((int*)b)[0];

	if (x > y)
		return 1;
	else if (x < y)
		return -1;

	return 0;
}

int n_m(int pos, int c)
{
	if (pos >= count)
		return -1;

	if (c == m)
	{
		for (int i = 0; i < m; ++i)
		{
			printf("%d ", list[temp[i]][0]);

		}
		printf("\n");

		return 1;
	}

	if (list[pos][1] != 0)
	{
		temp[c] = pos;
		--list[pos][1];
		n_m(0, c+1);
		++list[pos][1];
	}

	n_m(pos + 1, c);

	return 0;
}
