#include <stdio.h>                                                                                                      

char board[9][10];

int hori[9][9];
int vert[9][9];
// (x/3)*3 + y/3;
int box[9][9];

int sudoku(int, int);

int main(void)
{
	for (int i = 0; i < 9; ++i)
	{
		scanf("%s", board[i]);

		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] != '0')
			{
				hori[i][board[i][j] - '1'] = 1;
				vert[j][board[i][j] - '1'] = 1;
				box[(i / 3) * 3 + (j / 3)][board[i][j] - '1'] = 1;
			}
		}
	}
	sudoku(0, 0);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			printf("%c", board[i][j]);

		printf("\n");
	}

	return 0;
}

int sudoku(int x, int y)
{
	if (x == 9 && y == 0)
		return 1;

	if (board[x][y] == '0')
	{
		for (int i = 0; i < 9; ++i)
		{
			if (hori[x][i] == 0 && vert[y][i] == 0 && box[(x / 3) * 3 + (y / 3)][i] == 0)
			{
				board[x][y] += i + 1;
				hori[x][i] = 1;
				vert[y][i] = 1;
				box[(x / 3) * 3 + (y / 3)][i] = 1;

				if (y == 8)
				{
					if (sudoku(x + 1, 0) == 1)
						return 1;
				}
				else
				{
					if (sudoku(x, y + 1) == 1)
						return 1;
				}

				board[x][y] = '0';
				hori[x][i] = 0;
				vert[y][i] = 0;
				box[(x / 3) * 3 + (y / 3)][i] = 0;
			}
		}
	}
	else
	{
		if (y == 8)
			return sudoku(x + 1, 0);
		else
			return sudoku(x, y + 1);
	}

	return -1;
}
