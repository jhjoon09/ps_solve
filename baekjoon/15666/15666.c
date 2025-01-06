#include <stdio.h>
#include <stdlib.h>

int list[8];
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
			if (list[j] == temp)
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
		{
			list[count] = temp;
			++count;
		}

	}

	qsort(list, count, sizeof(int), compare);

	n_m(0, 0);

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if(x > y)
		return 1;
	else if(x < y)
		return -1;

	return 0;
}

int n_m(int pos, int c)
{
	if(pos >= count)
		return -1;

	if(c == m)
	{
		for(int i = 0; i < m; ++i)
			printf("%d ", temp[i]);

		printf("\n");

		return 1;
	}


	temp[c] = list[pos];
	n_m(pos, c+1);
	n_m(pos+1, c);

	return 0;
}        
