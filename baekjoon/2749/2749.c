#include <stdio.h>
#define DIV 1000000

typedef struct _matrix
{
	long long mat[2][2];
}MATRIX;

MATRIX basic;

long long fibo(long long);
MATRIX cal_matrix(long long);
MATRIX mult_matrix(MATRIX, MATRIX);

int main(void)
{
	long long n;
	scanf("%lld", &n);

	if(n == 0)
	{
		printf("0\n");
		return 0;
	}
	else if(n == 1)
	{
		printf("1\n");
		return 0;
	}
	else if(n == 2)
	{
		printf("1\n");
		return 0;
	}

	basic.mat[0][0] = 1;
	basic.mat[0][1] = 1;
	basic.mat[1][0] = 1;
	basic.mat[1][1] = 0;

	printf("%lld\n", fibo(n-2));

	return 0;
}

long long fibo(long long n)
{
	MATRIX ret = cal_matrix(n);

	return (ret.mat[0][0] + ret.mat[0][1]) % DIV;
}

MATRIX cal_matrix(long long n)
{
	if(n == 1)
		return basic;

	MATRIX temp = cal_matrix(n/2);

	if(n%2 == 0)
		return mult_matrix(temp, temp);
	else
		return mult_matrix(basic, mult_matrix(temp, temp));
}

MATRIX mult_matrix(MATRIX a, MATRIX b)
{
	MATRIX ret;
	ret.mat[0][0] = 0;
	ret.mat[0][1] = 0;
	ret.mat[1][0] = 0;
	ret.mat[1][1] = 0;

	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				ret.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				ret.mat[i][j] %= DIV;
			}
		}
	}

	return ret;
}
