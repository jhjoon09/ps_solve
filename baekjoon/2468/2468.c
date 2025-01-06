#include <stdio.h>
#include <string.h>

int board[100][100];
int check[100][100];

int area(int);
int count(int, int, int);

int main(void)
{
	int n;
	int high = 0, max = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			scanf("%d", &board[i][j]);

			if(board[i][j] > high)
				high = board[i][j];
		}
	}

	for(int i = 1; i < high; ++i)
	{
		int temp = area(i);

		if(temp > max)
			max = temp;
	}

	printf("%d", max);

	return 0;

}

int area(int level)
{
	int sum = 0;

	memset(check, 0, 100 * 100 * sizeof(int));
}
