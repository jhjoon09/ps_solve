#include <stdio.h>
#define MAX 3072

int print_tri(int, int, int);
int print_star(int, int);

char board[MAX][MAX * 3];

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N * 2; ++j)
			board[i][j] = ' ';
	}
	print_tri(N, 0, N - 1);

	for (int i = 0; i < N; ++i)
	{
		printf("%s\n", board[i]);
	}
	return 0;
}

int print_tri(int N, int x, int y)
{
	if (N == 3)
	{
		print_star(x, y);

		return 1;
	}

	print_tri(N / 2, x, y);
	print_tri(N / 2, x + N / 2, y - N / 2);
	print_tri(N / 2, x + N / 2, y + N / 2);

	return 0;
}

int print_star(int x, int y)
{
	board[x][y] = '*';

	board[x + 1][y - 1] = '*';
	board[x + 1][y + 1] = '*';

	for (int i = -2; i <= 2; ++i)
		board[x + 2][y + i] = '*';

	return 0;
}
