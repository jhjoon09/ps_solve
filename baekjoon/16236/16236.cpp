#include <stdio.h>
#include <stdlib.h>
#include <queue>

int N;
int board[20][20];
int shark_x, shark_y;
int shark_size;

using namespace std;

struct Pos
{
	int x;
	int y;
	int dis;

	Pos(int in_x, int in_y, int in_dis) : x(in_x), y(in_y), dis(in_dis) {}
};

struct cmp
{
	bool operator()(Pos a, Pos b)
	{
		if (a.dis == b.dis)
		{
			if (a.x == b.x)
			{
				return a.y > b.y;
			}

			return a.x > b.x;
		}
		return a.dis > b.dis;
	}
};

int eat(void);
int check_bound(int, int);

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", board[i] + j);

			if (board[i][j] == 9)
			{
				shark_x = i;
				shark_y = j;

				board[i][j] = 0;
			}
			else if (board[i][j] != 0)
			{

			}
		}
	}

	shark_size = 2;
	int level_up = shark_size;
	int time = 0;

	int temp = eat();
	board[shark_x][shark_y] = 0;

	--level_up;

	if (level_up == 0)
	{
		++shark_size;
		level_up = shark_size;
	}

	while (temp != -1)
	{
		time += temp;

		temp = eat();
		board[shark_x][shark_y] = 0;

		--level_up;

		if (level_up == 0)
		{
			++shark_size;
			level_up = shark_size;
		}
	}

	printf("%d\n", time);

	return 0;
}

int eat(void)
{
	int visit[20][20] = { 0, };

	priority_queue<Pos, vector<Pos>, cmp> que;

	que.push(Pos(shark_x, shark_y, 0));

	visit[shark_x][shark_y] = 1;

	while (que.empty() != 1)
	{
		Pos temp = que.top();
		que.pop();

		int x = temp.x;
		int y = temp.y;
		int dis = temp.dis;

		if (board[x][y] > 0 && board[x][y] < shark_size)
		{
			shark_x = x;
			shark_y = y;
			return dis;
		}

		//x-1, y;
		if (check_bound(x - 1, y))
		{
			if (visit[x - 1][y] == 0 && board[x - 1][y] <= shark_size)
			{
				visit[x - 1][y] = 1;

				que.push(Pos(x-1, y, dis + 1));
			}
		}
		//x, y-1
		if (check_bound(x, y - 1))
		{
			if (visit[x][y - 1] == 0 && board[x][y - 1] <= shark_size)
			{
				visit[x][y-1] = 1;

				que.push(Pos(x, y-1, dis + 1));
			}
		}
		//x, y+1
		if (check_bound(x, y + 1))
		{
			if (visit[x][y + 1] == 0 && board[x][y + 1] <= shark_size)
			{
				visit[x][y+1] = 1;

				que.push(Pos(x, y+1, dis + 1));
			}
		}
		//x-1, y
		if (check_bound(x + 1, y))
		{
			if (visit[x + 1][y] == 0 && board[x + 1][y] <= shark_size)
			{
				visit[x + 1][y] = 1;

				que.push(Pos(x+1, y, dis + 1));
			}
		}
	}

	return -1;
}

int check_bound(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 0;

	return 1;
}
