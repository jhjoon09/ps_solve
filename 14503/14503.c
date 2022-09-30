#include <stdio.h>                                                                                                    
/*
   2 is clean state
   1 is wall
   0 is unclean state
 */

int room[50][50];

int robot(int*, int*, int*);
int check(int, int);
int clean(int*, int*, int*);
int back(int*, int*, int*);

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int X, Y, D;

	scanf("%d %d %d", &X, &Y, &D);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			scanf("%d", &room[i][j]);
	}

	int count = 0;

	while (robot(&X, &Y, &D) != -1)
		++count;

	printf("%d\n", count + 1);

	return 0;
}

int robot(int* x, int* y, int* rot)
{
	room[*x][*y] = 2;

	int flag = 0;

	while (flag == 0)
	{
		if (check(*x, *y) == 1)
		{
			while(clean(x, y, rot) != 1);
			flag = 1;
		}
		else
		{
			flag = back(x, y, rot);
		}
	}

	return flag;
}

int check(int x, int y)
{
	if (room[x - 1][y] == 0)
		return 1;

	if (room[x][y - 1] == 0)
		return 1;

	if (room[x + 1][y] == 0)
		return 1;

	if (room[x][y + 1] == 0)
		return 1;

	return 0;
}

int clean(int* x, int* y, int* rot)
{
	switch (*rot)
	{
		case 0:
			*rot = 3;

			if (room[*x][*y-1] == 0)
			{
				--(*y);
				return 1;
			}
			break;
		case 1:
			*rot = 0;

			if (room[*x-1][*y] == 0)
			{
				--(*x);
				return 1;
			}
			break;
		case 2:
			*rot = 1;

			if (room[*x][*y+1] == 0)
			{
				++(*y);
				return 1;
			}
			break;
		case 3:
			*rot = 2;

			if (room[*x+1][*y] == 0)
			{
				++(*x);
				return 1;
			}
			break;
	}

	return 0;
}

int back(int* x, int* y, int* rot)
{
	switch (*rot)
	{
		case 0:
			++(*x);
			break;
		case 1:
			--(*y);
			break;
		case 2:
			--(*x);
			break;
		case 3:
			++(*y);
			break;
	}

	if (room[*x][*y] == 1)
		return -1;

	return 0;
}
