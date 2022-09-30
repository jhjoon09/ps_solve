#include <stdio.h>
#define UP 0
#define DOWN 1
#define FRONT 2
#define BACK 3
#define LEFT 4
#define RIGHT 5

char cube[6][3][3];

int cube_init(void);

int Swap(char*, char*);

int turn_plus(int);
int turn_minus(int);

int main(void)
{
	int t;

	scanf("%d", &t);

	while (t > 0)
	{
		--t;

		int n;
		scanf("%d", &n);

		cube_init();

		while (getchar() != '\n');

		for (int i = 0; i < n; ++i)
		{
			char side, op;

			scanf("%c%c", &side, &op);
			getchar();

			int temp = 0;
			switch (side)
			{
				case 'U':
					if (op == '-')
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[FRONT][0][i], &cube[LEFT][0][i]);
							Swap(&cube[LEFT][0][i], &cube[BACK][0][i]);
							Swap(&cube[BACK][0][i], &cube[RIGHT][0][i]);
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[FRONT][0][i], &cube[RIGHT][0][i]);
							Swap(&cube[RIGHT][0][i], &cube[BACK][0][i]);
							Swap(&cube[BACK][0][i], &cube[LEFT][0][i]);
						}
					}

					temp = UP;
					break;
				case 'D':
					if (op == '-')
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[FRONT][2][i], &cube[RIGHT][2][i]);
							Swap(&cube[RIGHT][2][i], &cube[BACK][2][i]);
							Swap(&cube[BACK][2][i], &cube[LEFT][2][i]);
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[FRONT][2][i], &cube[LEFT][2][i]);
							Swap(&cube[LEFT][2][i], &cube[BACK][2][i]);
							Swap(&cube[BACK][2][i], &cube[RIGHT][2][i]);
						}
					}

					temp = DOWN;
					break;
				case 'F':
					if (op == '-')
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][2][i], &cube[RIGHT][i][0]);
							Swap(&cube[RIGHT][i][0], &cube[DOWN][2][i]);
							Swap(&cube[DOWN][2][i], &cube[LEFT][2-i][2]);
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][2][i], &cube[LEFT][2-i][2]);
							Swap(&cube[LEFT][2-i][2], &cube[DOWN][2][i]);
							Swap(&cube[DOWN][2][i], &cube[RIGHT][i][0]);
						}
					}

					temp = FRONT;
					break;
				case 'B':
					if (op == '-')
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][0][i], &cube[LEFT][2 - i][0]);
							Swap(&cube[LEFT][2 - i][0], &cube[DOWN][0][i]);
							Swap(&cube[DOWN][0][i], &cube[RIGHT][i][2]);
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][0][i], &cube[RIGHT][i][2]);
							Swap(&cube[RIGHT][i][2], &cube[DOWN][0][i]);
							Swap(&cube[DOWN][0][i], &cube[LEFT][2-i][0]);
						}
					}

					temp = BACK;
					break;
				case 'L':
					if (op == '-')
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][i][0], &cube[FRONT][i][0]);
							Swap(&cube[FRONT][i][0], &cube[DOWN][2-i][2]);
							Swap(&cube[DOWN][2-i][2], &cube[BACK][2 - i][2]);
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][i][0], &cube[BACK][2 - i][2]);
							Swap(&cube[BACK][2 - i][2], &cube[DOWN][2-i][2]);
							Swap(&cube[DOWN][2-i][2], &cube[FRONT][i][0]);
						}
					}
					temp = LEFT;
					break;
				case 'R':
					if (op == '-')
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][i][2], &cube[BACK][2 - i][0]);
							Swap(&cube[BACK][2 - i][0], &cube[DOWN][2-i][0]);
							Swap(&cube[DOWN][2-i][0], &cube[FRONT][i][2]);
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							Swap(&cube[UP][i][2], &cube[FRONT][i][2]);
							Swap(&cube[FRONT][i][2], &cube[DOWN][2-i][0]);
							Swap(&cube[DOWN][2-i][0], &cube[BACK][2 - i][0]);
						}
					}
					temp = RIGHT;
					break;
			}


			if (op == '+')
				turn_plus(temp);
			else
				turn_minus(temp);
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
				printf("%c", cube[UP][i][j]);

			printf("\n");
		}
	}
}

int cube_init(void)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			///*
			cube[UP][i][j] = 'w';
			cube[DOWN][i][j] = 'y';
			cube[FRONT][i][j] = 'r';
			cube[BACK][i][j] = 'o';
			cube[LEFT][i][j] = 'g';
			cube[RIGHT][i][j] = 'b';
			//*/

		}
	}

	return 0;
}

int Swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;

	return 0;
}

int turn_plus(int side)
{
	Swap(&cube[side][0][0], &cube[side][2][0]);
	Swap(&cube[side][2][0], &cube[side][2][2]);
	Swap(&cube[side][2][2], &cube[side][0][2]);

	Swap(&cube[side][0][1], &cube[side][1][0]);
	Swap(&cube[side][1][0], &cube[side][2][1]);
	Swap(&cube[side][2][1], &cube[side][1][2]);

	return 1;
}

int turn_minus(int side)
{
	Swap(&cube[side][0][0], &cube[side][0][2]);
	Swap(&cube[side][0][2], &cube[side][2][2]);
	Swap(&cube[side][2][2], &cube[side][2][0]);

	Swap(&cube[side][0][1], &cube[side][1][2]);
	Swap(&cube[side][1][2], &cube[side][2][1]);
	Swap(&cube[side][2][1], &cube[side][1][0]);
	return 1;
}
