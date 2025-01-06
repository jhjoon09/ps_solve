#include <stdio.h>
#define SIZE 1024

int width[SIZE][SIZE];

int cal_width(int, int, int, int);

int main(void)
{
	int n,m;

	scanf("%d %d", &n, &m);


	for(int i = 0; i < n; ++i)
	{
		int temp = 0;
		for(int j = 0; j < n; ++j)
		{
			scanf("%d", *(width+i) + j);
			width[i][j] += temp;
			temp = width[i][j];
		}
	}

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			width[i][j] += width[i-1][j];
		}
	}

	for(int i = 0; i < m; ++i)
	{
		int x1, x2;
		int y1, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		printf("%d\n", cal_width(x1-1, y1-1, x2-1, y2-1));
	}
	
	return 0;
}

int cal_width(int x1, int y1, int x2, int y2)
{
	int result = width[x2][y2];

	if(y1 == 0)
	{
		if(x1 == 0)
			return result;
		
		result -= width[x1-1][y2];

		return result;
	}

	if(x1 == 0)
	{
		result -= width[x2][y1-1];
		
		return result;
	}

	result = result - width[x2][y1-1] - width[x1-1][y2] + width[x1-1][y1-1];

	return result;
}
