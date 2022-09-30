#include <stdio.h>
#define MAX 1001

int go_track(int, int);
int back_track(int, int);
int trace_track(int, int, char);

char board[MAX][MAX];
int visit[MAX][MAX];
int N, M;

int main(void)
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i)
		scanf("%s", board[i]);

	int count = 0;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(visit[i][j] == 0)
			{
				go_track(i, j);
				++count;
			}
		}
	}

	printf("%d\n", count);
}

int go_track(int x, int y)
{
	if(visit[x][y] != 0)
		return 0;

	visit[x][y] = 1;

	switch(board[x][y])
	{
		case 'U':
			go_track(x-1, y);
			break;
		case 'D':
			go_track(x+1, y);
			break;
		case 'L':
			go_track(x, y-1);
			break;
		case 'R':
			go_track(x, y+1);
			break;
	}

	back_track(x, y);

	return 0;
}

int back_track(int x, int y)
{
	trace_track(x+1, y, 'U');
	trace_track(x-1, y, 'D');
	trace_track(x, y+1, 'L');
	trace_track(x, y-1, 'R');

	return 0;
}

int trace_track(int x, int y, char c)
{
	if(x < 0 || x >= N || y < 0 || y >= M)
		return -1;

	if(board[x][y] != c)
		return -1;

	if(visit[x][y] != 0)
		return 0;

	visit[x][y] = 1;

	back_track(x, y);

	return 0;
}
