#include <stdio.h>
#define DIV 1000000

typedef struct _matrix
{
	long long mat[2][2];
}MATRIX;

MATRIX mult;

MATRIX mult_matrix(MATRIX, MATRIX);

int main(void)
{
	long long n;
	scanf("%lld", &n);

	n = (n - 1) / 2;

	if (n <= 1)
	{
		printf("%lld\n", 2*n + 1);
		return 0;
	}

	MATRIX basic;

	basic.mat[0][0] = 1;
	basic.mat[0][1] = 1;
	basic.mat[1][0] = 1;
	basic.mat[1][1] = 0;

	mult = mult_matrix(basic, basic);

	long long temp = 3;

	for (int i = 1; i < n; ++i)
	{
		basic = mult_matrix(mult, basic);

		temp += (basic.mat[0][0] + basic.mat[0][1]);

		temp %= DIV;
	}

	printf("%lld\n", temp); 

	return 0;
}

MATRIX mult_matrix(MATRIX a, MATRIX b)
{
	MATRIX ret;
	ret.mat[0][0] = 0;
	ret.mat[0][1] = 0;
	ret.mat[1][0] = 0;
	ret.mat[1][1] = 0;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				ret.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				ret.mat[i][j] %= DIV;
			}
		}
	}

	return ret;
}
