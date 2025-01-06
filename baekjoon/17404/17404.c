#include <stdio.h>

#define INF 1000001
#define MIN(x, y) ((x)>(y) ? (y) : (x))

int main(void)
{
	int N;

	scanf("%d", &N);

	int color[3][2][3] = {0 ,};

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			color[i][0][j] = INF;

	scanf("%d %d %d", &color[0][0][0], &color[1][0][1], &color[2][0][2]);

	for (int i = 1; i < N; ++i)
	{
		int input[3];

		scanf("%d %d %d", input + 0, input + 1, input + 2);

		for(int j = 0; j < 3; ++j)
		{
			color[j][1][0] = MIN(color[j][0][1], color[j][0][2]) + input[0];
			color[j][1][1] = MIN(color[j][0][0], color[j][0][2]) + input[1];
			color[j][1][2] = MIN(color[j][0][0], color[j][0][1]) + input[2];
		
			for(int k = 0; k < 3; ++k)
			{
				color[j][0][k] = color[j][1][k];
				color[j][1][k] = 0;
			}
		}
	}

	for(int i = 0; i < 3; ++i)
		color[i][0][i] = INF;

	int min = INF;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(min > color[i][0][j])
				min = color[i][0][j];
		}
	}

	printf("%d\n", min);

	return 0;
}
