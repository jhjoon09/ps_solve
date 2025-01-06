#include <stdio.h>
#include <stdlib.h>

int board[100][100];
int m, n;

int compare(const void*, const void*);

int cal_wid(int, int);

int main(void)
{
	int k;
	int area[10000] = {0 ,};

	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < k; ++i)
	{
		int x1, x2, y1, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for(int x = x1; x < x2; ++x)
			for(int y = y1; y < y2; ++y)
				board[x][y] = 1;

	}

	int count = 0;

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(board[i][j] == 0)
			{
				area[count++] = cal_wid(i, j);
			}
		}
	}
	
	qsort(area, count, sizeof(int), compare);

	printf("%d\n", count);

	for(int i = 0; i < count; ++i)
		printf("%d ", area[i]);

	printf("\n");

	return 0;
}

int compare(const void* a, const void* b)
{
	int x = *((int*)a);
	int y = *((int*)b);

	if(x > y)
		return 1;
	else if(x == y)
		return 0;
	else
		return -1;
}

int cal_wid(int x, int y)
{
	if(x < 0 || y < 0 || x >= m || y >= n)
		return 0;

	if(board[x][y] != 0)
		return 0;

	board[x][y] = 1;

	return 1 + cal_wid(x-1,y) + cal_wid(x+1, y) + cal_wid(x, y-1) + cal_wid(x, y+1);
}
