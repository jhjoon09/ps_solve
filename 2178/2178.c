#include <stdio.h>

int way(int, int, int);

int n, m;
int board[101][101];
int check[101][101];

int main(void)
{
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			scanf("%1d", &board[i][j]);
			check[i][j] = n*m + 1;
		}
	}

	printf("%d\n", way(1, 1, 1));

	return 0;
}


int way(int x, int y, int count)
{
	if(x==n && y==m)
		return count;

	if(board[x][y] == 0)
		return n*m + 1;

	if(x > n || y > m)
		return n*m + 1;

	if(x<=0 || y <= 0)
		return n*m + 1;

	if(check[x][y] <= count)
		return n*m + 1;

	check[x][y] = count;

	int a = way(x+1,y,count+1);
	int b = way(x-1,y,count+1);
	a = a<b ? a : b;

	int c = way(x,y-1,count+1);
	int d = way(x,y+1,count+1);
	c = c<d ? c : d;

	a = a<c ? a : c;

	return a;
}
