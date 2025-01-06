#include <stdio.h>
#define MAX(x, y) ((x)>(y) ? (x) : (y))
#define MIN(x, y) ((x)>(y) ? (y) : (x))

int main(void)
{
	int N;

	scanf("%d", &N);

	int min[2][3] = {0, };
	int max[2][3] = {0, };

	for(int i = 0; i < N; ++i)
	{
		int input[3];

		scanf("%d %d %d", input + 0, input + 1, input + 2);

		min[1][0] = MIN(min[0][0], min[0][1]) + input[0];
		min[1][1] = MIN(MIN(min[0][0], min[0][1]), min[0][2]) + input[1];
		min[1][2] = MIN(min[0][1], min[0][2]) + input[2];

		max[1][0] = MAX(max[0][0], max[0][1]) + input[0];
		max[1][1] = MAX(MAX(max[0][0], max[0][1]), max[0][2]) + input[1];
		max[1][2] = MAX(max[0][1], max[0][2]) + input[2];

		for(int j = 0; j < 3; ++j)
		{
			min[0][j] = min[1][j];
			min[1][j] = 0;

			max[0][j] = max[1][j];
			max[1][j] = 0;
		}
	}

	int a = MAX(max[0][0], max[0][1]);
	a = MAX(a, max[0][2]);

	int b = MIN(min[0][0], min[0][1]);
	b = MIN(b, min[0][2]);

	printf("%d %d\n", a, b);

	return 0;
}
