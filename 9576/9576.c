#include <stdio.h>
#include <stdlib.h>

int list[1000][2];

int compare(const void*, const void*);
int give_book(void);

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t > 0)
	{
		--t;

		printf("%d\n", give_book());
	}
}

int compare(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;

	if(x[1] > y[1])
		return 1;
	else if(x[1] < y[1])
		return -1;
	else
	{
		if(x[0] > y[0])
			return 1;
		else if(x[0] < y[0])
			return -1;
		else
			return 0;
	}
}

int give_book(void)
{
	int n,m;
	int give[1000] = {0 ,};

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; ++i)
		scanf("%d %d", list[i]+0, list[i]+1);

	qsort(list, m, sizeof(list[0]), compare);

	int count = 0;

	for(int i = 0; i < m; ++i)
	{
		int st = list[i][0]-1;
		int en = list[i][1]-1;

		for(int i = st; i <= en; ++i)
		{
			if(give[i] == 0)
			{
				give[i] = 1;
				++count;
				break;
			}
		}
	}

	return count;
}
