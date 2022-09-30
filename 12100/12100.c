#include <stdio.h>

int n;

int move_board(int[20][20], int);
int moving(int[20][20], int);

int main(void)
{
	int board[20][20];

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", board[i]+j);

	int ret = move_board(board, 5);
}

int move_board(int board[20][20], int count)
{
	if(count == 0)
	{
		int max = 0;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(max < board[i][j])
					max = board[i][j];
			}
		}

		return max;
	}

	int temp[20][20];
	int max = 0;
	for(int i = 0; i < 4; ++i)
	{
		temp = moving(board, i);
		
		int t = move_board(temp, count-1);
	
		max = (t>max) ? t : max;
	}

	return max;
}

int moving(int board[20][20], int type)
{


}
