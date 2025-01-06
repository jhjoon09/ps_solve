#include <stdio.h> 

int que[8][2];
int office[8][8];
int area[8][8];

int N, M;

int cctv(int, int);
int watch(int, int, int);
int line(int, int, int, int);
int count(void);

int main(void)
{
	int count = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &office[i][j]);

			if (office[i][j] >= 1 && office[i][j] <= 5)
			{
				que[count][0] = i;
				que[count][1] = j;
				++count;
			}

			if (office[i][j] == 6)
				area[i][j] += 1;
		}
	}

	int max = 0;

	max = cctv(0, count);

	printf("%d\n", M * N - max);

	return 0;
}

int cctv(int pos, int max)
{
	if (pos == max)
	{
		return count();
	}
	int max_area = 0;

	int x = que[pos][0];
	int y = que[pos][1];

	if (office[x][y] == 5)
	{
		watch(pos, 0, 1);
		max_area = cctv(pos + 1, max);
		watch(pos, 0, -1);

		return max_area;
	}
	else if (office[x][y] == 2)
	{
		for (int i = 0; i < 2; ++i)
		{
			watch(pos, i, 1);
			int temp = cctv(pos + 1, max);

			if (temp > max_area)
				max_area = temp;

			watch(pos, i, -1);
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			watch(pos, i, 1);
			int temp = cctv(pos + 1, max);

			if (temp > max_area)
				max_area = temp;

			watch(pos, i, -1);
		}
	}


	return max_area;
}

int watch(int pos, int type, int a)
{
	int x = que[pos][0];
	int y = que[pos][1];

	int kind = office[x][y];

	area[x][y] += a;

	if (kind == 1)
	{
		line(x, y, type, a);
	}
	else if (kind == 2)
	{
		line(x, y, type, a);
		line(x, y, (type + 2) % 4, a);
	}
	else if (kind == 3)
	{
		line(x, y, type, a);
		line(x, y, (type + 1) % 4, a);
	}
	else if (kind == 4)
	{
		for (int i = 0; i < 3; ++i)
			line(x, y, (type + i) % 4, a);
	}
	else
	{
		for (int i = 0; i < 4; ++i)
			line(x, y, (type + i) % 4, a);
	}

	return 0;
}

int line(int x, int y, int type, int input)
{
	if (type == 0)
	{
		for (int i = x - 1; i >= 0; --i)
		{
			if (office[i][y] == 6)
				return 0;

			area[i][y] += input;
		}
	}
	else if (type == 1)
	{
		for (int i = y + 1; i < M; ++i)
		{
			if (office[x][i] == 6)
				return 0;

			area[x][i] += input;
		}
	}
	else if (type == 2)
	{
		for (int i = x + 1; i < N; ++i)
		{
			if (office[i][y] == 6)
				return 0;

			area[i][y] += input;
		}
	}
	else
	{
		for (int i = y - 1; i >= 0; --i)
		{
			if (office[x][i] == 6)
				return 0;

			area[x][i] += input;
		}
	}

	return 0;

}

int count(void)
{
	int temp = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (area[i][j] > 0)
				++temp;
		}
	}

	return temp;
}
