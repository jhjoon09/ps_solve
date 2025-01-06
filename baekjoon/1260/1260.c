#include <stdio.h>                  
#include <string.h>

int line[1001][1001];
int n, m, v;
int check[1001];

int depth(int);
int breath(int);

int main(void)
{
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; ++i)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		line[x][y] = 1;
		line[y][x] = 1;

	}

	depth(v);
	printf("\n");
	memset(check, 0, sizeof(check));
	breath(v);
	printf("\n");

	return 0;
}

int depth(int name)
{
	if (check[name] != 0)
		return 0;

	printf("%d ", name);

	check[name] = 1;

	for (int i = 1; i <= n; ++i)
	{
		if (line[name][i] != 0)
		{
			depth(i);
		}
	}

	return 0;
}

int breath(int name)
{
	int end = 0;
	int list[1000] = {0, };

	check[name] = 1;

	list[end++] = name;

	printf("%d ", list[0]);

	for(int i = 0; i < n; ++i)
	{
		if(list[i] == 0)
			break;

		for(int j = 1; j <= n; ++j)
		{
			if(line[list[i]][j] != 0)
			{
				if(check[j] == 0)
				{
					printf("%d ", j);
					list[end++] = j;
					check[j] = 1;
				}
			}
		}
	}
}
