#include <stdio.h>

int edge[1001][1001];
int vertex[1001];
int n;

int count(int);

int main(void)
{
	int m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		
		edge[x][y] = 1;
		edge[y][x] = 1;
	}


	int sum = 0;

	for(int i = 1; i <= n; ++i)
		sum += count(i);

	printf("%d\n", sum);

	return 0;
}

int count(int point)
{
	if(vertex[point] != 0)
		return 0;

	vertex[point] = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(edge[point][i] != 0)
			count(i);
	}

	return 1;
}
