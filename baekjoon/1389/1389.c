#include <stdio.h>
#include <limits.h>
#include <string.h>


int edge[101][101];

int main(void)
{
	int n, m;
	int que[100] = {0, };
	int check[101] = {0 ,};

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; ++i)
	{
		int x,y;
		scanf("%d %d", &x, &y);

		edge[x][y] = 1;
		edge[y][x] = 1;
	}

	int end = 0;

	for(int x = 1; x <= n; ++x)
	{
		memset(check, 0, sizeof(check));
		que[0] = x;
		end = 1;
		for(int i = 0; i < n; ++i)
		{
			check[que[i]] = 1;

			for(int j = 1; j <= n; ++j)	
			{
				if(edge[que[i]][j] != 0)
				{
					if(check[j] == 0)
					{
						que[end] = j;
						++end;
					}

					if((edge[x][j] == 0 || edge[x][j] > edge[x][que[i]] + edge[que[i]][j]) && x != j)
					{
						edge[x][j] = edge[x][que[i]] + edge[que[i]][j];
						edge[j][x] = edge[x][j];
					}
				}
			}

		}
	}
	int min = INT_MAX;
	int person = 0;

	for(int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for(int j = 1; j <= n; ++j)
		{
			sum += edge[i][j];
		}

		if(sum < min)
		{
			min = sum;
			person = i;
		}
	}

	printf("%d\n", person);

	return 0;
}
