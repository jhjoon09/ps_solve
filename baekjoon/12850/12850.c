#include <stdio.h>
#define DIV 1000000007

typedef struct _matrix
{
	long long cell[8][8];
}MATRIX;

MATRIX basic;

int init_basic(void);
MATRIX cal_walk(int);
MATRIX matrix_mult(MATRIX, MATRIX);

int main(void)
{
	int D;

	scanf("%d", &D);

	init_basic();

	MATRIX res = cal_walk(D);


	printf("%lld\n", res.cell[0][0]);
	return 0;
}

int init_basic(void)
{
	basic.cell[0][1] = 1;
	basic.cell[0][2] = 1;

	basic.cell[1][0] = 1;
	basic.cell[1][2] = 1;
	basic.cell[1][3] = 1;

	basic.cell[2][0] = 1;
	basic.cell[2][1] = 1;
	basic.cell[2][3] = 1;
	basic.cell[2][4] = 1;

	basic.cell[3][1] = 1;
	basic.cell[3][2] = 1;
	basic.cell[3][4] = 1;
	basic.cell[3][5] = 1;

	basic.cell[4][2] = 1;
	basic.cell[4][3] = 1;
	basic.cell[4][5] = 1;
	basic.cell[4][7] = 1;

	basic.cell[5][3] = 1;
	basic.cell[5][4] = 1;
	basic.cell[5][6] = 1;

	basic.cell[6][5] = 1;
	basic.cell[6][7] = 1;

	basic.cell[7][4] = 1;
	basic.cell[7][6] = 1;

	return 0;
}

MATRIX cal_walk(int N)
{
	if (N == 1)
		return basic;

	MATRIX temp = cal_walk(N / 2);

	if (N % 2 == 0)
	{
		return matrix_mult(temp, temp);
	}
	else
		return matrix_mult(temp, matrix_mult(temp, basic));

}

MATRIX matrix_mult(MATRIX a, MATRIX b)
{
	MATRIX ret;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			long long sum = 0;

			for (int k = 0; k < 8; ++k)
			{
				sum += a.cell[i][k] * b.cell[k][j];
				sum %= DIV;
			}

			ret.cell[i][j] = sum;
		}
	}

	return ret;
}
