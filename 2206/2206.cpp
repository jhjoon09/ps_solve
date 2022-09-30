#include <stdio.h>
#include <limits.h>
#include <queue>

using namespace std;

char board[1000][1001];
int dp[2][1000][1000];
int N, M;

struct Node
{
	int x;
	int y;
	int count;

	Node(int input_x, int input_y, int input_count) : x(input_x), y(input_y), count(input_count) {}

};

struct cmp
{
	bool operator()(Node a, Node b)
	{
		return a.count > b.count;
	}
};

int search_start(void);
int search_end(void);
int break_wall(int, int);

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		scanf("%s", board[i]);
		for (int j = 0; j < M; ++j)
		{
			dp[0][i][j] = INT_MAX;
			dp[1][i][j] = INT_MAX;
		}
	}

	search_start();
	search_end();

	int min = dp[0][N - 1][M - 1];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == '1')
			{
				int temp = break_wall(i, j);

				if (temp < min)
					min = temp;
			}
		}
	}

	if (min == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", min);

	return 0;
}

int search_start(void)
{
	priority_queue<Node, vector<Node>, cmp> pq;

	pq.push(Node(0, 0, 1));

	while (pq.empty() != 1)
	{
		Node temp = pq.top();
		pq.pop();

		int x = temp.x;
		int y = temp.y;
		int count = temp.count;

		if (x < 0 || y < 0 || x >= N || y >= M)
			continue;

		if (board[x][y] == '1')
			continue;

		if (dp[0][x][y] <= count)
			continue;

		if (dp[0][x][y] <= count)
			continue;

		dp[0][x][y] = count;

		if (x == N - 1 && y == M - 1)
			return 1;

		int dxy[] = { 0, 1, 0, -1 };

		for (int i = 0; i < 4; ++i)
		{
			pq.push(Node(x + dxy[i], y + dxy[3 - i], count + 1));
		}

	}

	return 0;
}

int search_end(void)
{
	priority_queue<Node, vector<Node>, cmp> pq;

	pq.push(Node(N - 1, M - 1, 1));

	while (pq.empty() != 1)
	{
		Node temp = pq.top();
		pq.pop();

		int x = temp.x;
		int y = temp.y;
		int count = temp.count;

		if (x < 0 || y < 0 || x >= N || y >= M)
			continue;

		if (board[x][y] == '1')
			continue;

		if (dp[1][x][y] <= count)
			continue;

		dp[1][x][y] = count;

		if (x == 0 && y == 0)
			return 1;

		int dxy[] = { 0, 1, 0, -1 };

		for (int i = 0; i < 4; ++i)
		{
			pq.push(Node(x + dxy[i], y + dxy[3 - i], count + 1));
		}
	}
	return 0;
}

int break_wall(int x, int y)
{
	int min[] = { INT_MAX, INT_MAX };

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };


	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M)
			{
				if (min[j] > dp[j][x + dx[i]][y + dy[i]])
					min[j] = dp[j][x + dx[i]][y + dy[i]];
			}
		}
	}
	if (min[0] == INT_MAX || min[1] == INT_MAX)
		return INT_MAX;
	else
		return min[0] + min[1] + 1;
}
