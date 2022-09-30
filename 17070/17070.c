#include <stdio.h>

int home[18][18];
int N;

int move_pip(int, int, int);

int main(void)
{
	scanf("%d", &N);

	for(int i = 0; i <= N+1; ++i)
	{
		home[i][0] = 1;
		home[i][N+1] = 1;
		home[0][i] = 1;
		home[N+1][i] = 1;
	}

	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= N; ++j)
			scanf("%d", &home[i][j]);

	printf("%d\n", move_pip(1,2,0));

	return 0;
}

int move_pip(int x, int y, int type)
{
	/*
	   type 0 is vertical
	   type 1 is horizontal
	   type 2 diagonal

	 */
	if(home[x][y] != 0)
		return 0;

	if(x == N && y == N)
		return 1;

	int sum = 0;

	if(type == 0 || type == 2)
	{
		sum += move_pip(x, y+1, 0);
	}

	if(type == 1 || type == 2)
	{
		sum += move_pip(x+1, y, 1);
	}

	if(home[x][y+1] == 0 && home[x+1][y] == 0)
	{
		sum += move_pip(x+1, y+1, 2);
	}

	return sum;
}
