#include <stdio.h>

typedef struct matrix
{
	int cell[5][5];
}Matrix;

Matrix basic;
int N;

Matrix multiply(long long);
Matrix matrix_mult(Matrix, Matrix);

int main(void)
{
	long long b;

	scanf("%d %lld", &N, &b);

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			scanf("%d", &basic.cell[i][j]);
			basic.cell[i][j] %= 1000;
		}
	}

	Matrix result = multiply(b);

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
			printf("%d ", result.cell[i][j]);

		printf("\n");
	}

	return 0;
}

Matrix multiply(long long b)
{
	if(b == 1)
		return basic;

	Matrix temp = multiply(b/2);

	if(b%2 == 0)
		return matrix_mult(temp, temp);
	else
		return matrix_mult(matrix_mult(temp, temp), basic);
}

Matrix matrix_mult(Matrix a, Matrix b)
{
	Matrix temp;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			temp.cell[i][j] = 0;
			for(int k = 0; k < N; ++k)
			{
				temp.cell[i][j] += a.cell[i][k] * b.cell[k][j];

				temp.cell[i][j] %= 1000;
			}
		}
	}

	return temp;
}
