#include <stdio.h>
#include <limits.h>

int main(void)
{
	int board[101] = { 0 , };
	int trick[101] = { 0, };

	int ladder;
	int snake;

	scanf("%d", &ladder);
	scanf("%d", &snake);

	for (int i = 0; i < ladder + snake; ++i)
	{
		int input = 0;
		scanf("%d", &input);
		scanf("%d", trick + input);
	}

	int pos = 2;

	while (pos <= 100)
	{
		int min = INT_MAX;

		for (int i = pos - 6 > 0 ? pos - 6 : 1; i < pos; ++i)
		{
			if (trick[i] != 0)
				continue;

			if (board[i] < min)
				min = board[i];
		}

		if (board[pos] != 0)
		{
			if (board[pos] > min + 1)
				board[pos] = min + 1;
		}
		if (board[pos] == 0)
		{
			board[pos] = min + 1;
		}

		if (trick[pos] != 0) {
			if (board[trick[pos]] != 0 && (board[trick[pos]] > board[pos]))
			{
				board[trick[pos]] = board[pos];

				if (trick[pos] < pos)
					pos = trick[pos];
			}
			else if (board[trick[pos]] == 0)
				board[trick[pos]] = board[pos];
		}

		++pos;
	}

	printf("%d\n", board[100]);

	return 0;
}
