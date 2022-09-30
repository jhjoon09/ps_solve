#include <stdio.h>

int board[15][2];
/*
   board[i][0] = over
   board[i][1] = full;  

	board[i+1][1] = board[i][1] * 3 + board[i][0]
	board[i+1][0] = board[i][1] * 2 + board[i][0];
 */


int main(void)
{
	int n;

	scanf("%d", &n);

	if(n%2 == 1)
	{
		printf("0\n");
		return 0;
	}

	board[0][0] = 2;
	board[0][1] = 3;


	for(int i = 1; i < n/2; ++i)
	{
		board[i][0] = board[i-1][1] * 2 + board[i-1][0];
		board[i][1] = board[i-1][1] * 3 + board[i-1][0];
	}

	printf("%d\n", board[n/2 - 1][1]);

	return 0;
}
