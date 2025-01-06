#include <stdio.h>
#include <limits.h>

int n, m;
char board[50][51];
int dp[50][50];
int visit[50][50];

int is_vail(int, int);
int move(int, int, int);

int main(void)
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
		scanf("%s", board[i]);

	int ret = move(0, 0, 0);

	if (ret == INT_MAX)
		ret = -1;

	printf("%d\n", ret);

	return 0;
}

int is_vail(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;

	if (board[x][y] == 'H')
		return 0;

	return 1;
}

int move(int x, int y, int count)
{
	if (is_vail(x, y) == 0)
		return count;

	if (visit[x][y] == 1)
		return INT_MAX;

	if (dp[x][y] > count)
		return dp[x][y];

	visit[x][y] = 1;

	dp[x][y] = count;

	int c_next = board[x][y] - '0';

	int dxy[] = { 0, 0, 1, -1 };

	int max = -1;

	for (int i = 0; i < 4; ++i)
	{
		int n_x = x + c_next * dxy[i];
		int n_y = y + c_next * dxy[3 - i];

		int temp = move(n_x, n_y, count + 1);

		max = max > temp ? max : temp;
	}

	visit[x][y] = 0;
	dp[x][y] = max;

	return max;
}
