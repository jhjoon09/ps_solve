#include <stdio.h>

int visit[26];
int board[20][20];
int R,C;
int count;

int move(int, int, int);

int main(void)
{
	scanf("%d %d", &R, &C);

	for(int i = 0; i < R; ++i)
	{
		char c_temp;

		while(getchar() != '\n');

		for(int j = 0; j < C; ++j)
		{
			scanf("%c", &c_temp);
			board[i][j] = c_temp - 'A';
		}
	}

	move(0, 0, 1);

	printf("%d\n", count);

	return 0;
}

int move(int x, int y, int t_count)
{
	if(x < 0 || x >= R || y < 0 || y >= C)
		return 0;

	if(visit[board[x][y]] == 1)
		return 0;

	if(t_count > count)
		count = t_count;

	visit[board[x][y]] = 1;

	
	move(x+1, y, t_count + 1);
	move(x-1, y, t_count + 1);
	move(x, y+1, t_count + 1);
	move(x, y-1, t_count + 1);

	visit[board[x][y]] = 0;

	return 1;
}
