#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int n;

int compare(const void*, const void*);
int cluster(int(*) [MAX], int, int);

int main(void)
{
	int board[MAX][MAX] = {0, };
	int number[MAX * MAX] = {0 ,};
	int end = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			scanf("%1d", (*(board + i) + j));
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(board[i][j] == 1)
			{
				number[end++] = cluster(board, i, j);
			}
		}
	}

	qsort(number, end, sizeof(int), compare);

	printf("%d\n", end);

	for(int i = 0; i < end; ++i)
		printf("%d\n", *(number + i));

	return 0;
}

int compare(const void* a, const void* b)
{
	if( *(int*)a < *(int*)b)
		return -1;
	else
		return 1;
}

int cluster(int(* board)[MAX], int x, int y)
{
	if(x< 0 || y < 0 || x >= n || y >= n)
		return 0;

	if(board[x][y] == 0)
		return 0;

	board[x][y] = 0;

	return 1 + cluster(board, x-1, y) + cluster(board, x+1, y) + cluster(board, x, y-1) + cluster(board, x, y+1);
}
