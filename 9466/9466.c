#include <stdio.h>
#include <string.h>
#define MAX 100000

int edge[MAX];
int visit[MAX];

int circuit(int);

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t > 0)
	{
		--t;
		
		memset(visit, 0, sizeof(visit));

		int count = 0;

		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; ++i)
		{
			scanf("%d", edge + i);
		}

		for(int i = 0; i < n; ++i)
		{
			if(visit[i] == 0)
				circuit(i);

			if(visit[i] != 2)
				++count;
		}

		printf("%d\n", count);
	}

	return 0;
}

int circuit(int pos)
{
	if(visit[pos] == -1)
		return -1;

	if(visit[pos] >= 2)
		return 1;

	++visit[pos];

	circuit(edge[pos]-1);

	if(visit[pos] != 2)
		visit[pos] = -1;

	return 0;
}
