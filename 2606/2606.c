#include <stdio.h>

int line[100][100];
int n, m;
int check[100];

int virus(int);

int main(void)
{
	scanf("%d\n%d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		line[x - 1][y - 1] = 1;
		line[y - 1][x - 1] = 1;

	}

	printf("%d\n", virus(0) - 1);

	return 0;
}

int virus(int name)
{
	if (check[name] != 0)
		return 0;

	check[name] = 1;

	int sum = 1;

	for (int i = 0; i < n; ++i)
	{
		if (line[name][i] != 0)
		{
			sum += virus(i);
		}
	}

	return sum;
}
