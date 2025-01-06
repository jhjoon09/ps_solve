#include <stdio.h>
#include <limits.h>

#define MAX 500

int board[MAX][MAX];
int n,m;

int tetro(int, int, int);
int middle_finger(int,int);

int main(void)
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);


	int max = INT_MIN;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int temp = tetro(i, j, 4);
			
			if(temp > max)
				max = temp;
		
			temp = middle_finger(i, j);

			if(temp > max)
				max = temp;
		}
	}

	printf("%d\n", max);

	return 0;
}

int tetro(int x, int y, int time)
{
	if(x < 0 || y < 0 || x >= n || y >= m)
		return INT_MIN;

	if(time == 1)
		return board[x][y];

	int temp = board[x][y];
	
	board[x][y] = INT_MIN;

	int max = INT_MIN;

	int a[4] = {0, 0, 1, -1};

	for(int i = 0; i < 4; ++i)
	{
		int comp = tetro(x+a[i], y+a[3-i], time-1);

		max = comp>max ? comp : max;
	}

	board[x][y] = temp;
	return board[x][y] + max;
}

int middle_finger(int x, int y)
{
	int min = 0;

	int a[4] = {0, 0, 1, -1};

	int data[4] = {0, };

	for(int i = 0; i < 4; ++i)
	{
		data[i] = tetro(x+a[i], y+a[3-i], 1);
		
		if(data[i] < data[min])
			min = i;
	}

	int temp = board[x][y];

	for(int i = 0; i < 4; ++i)
	{
		if(i == min)
			continue;
		temp += data[i];
	}

	return temp;
}
