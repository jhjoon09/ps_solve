#include <stdio.h>
#include <string.h>

int map[50][50];

int bug(int, int);
int m,n;

int main(void)
{
	int t;
	int k;

	scanf("%d", &t);

	for(int i = 0; i < t; ++i)
	{
		memset(map, 0, sizeof(map));

		scanf("%d %d %d", &m, &n, &k);
		
		int x = 0, y = 0;

		for(int j = 0; j < k; ++j)
		{
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}

		int count = 0;

		for(int a = 0; a < m; ++a)
		{
			for(int b = 0; b < n; ++b)
			{
				if(map[a][b] == 1)
				{
					++count;
					bug(a, b);
				}
			}
		}

		printf("%d\n", count);

	}

	return 0;
}

int bug(int x, int y)
{
	if(x >= m || x < 0 || y >= n || y < 0)
		return 0;

	if(map[x][y] == 0 || map[x][y] == 2)
		return 0;

	if(map[x][y] == 1)
	{
		map[x][y] = 2;
		bug(x, y+1);
		bug(x+1,y);
		bug(x-1, y);
		bug(x, y-1);
	}

	return 0;
}


