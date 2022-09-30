#include <stdio.h>                                                                                                      

int z_count(int, int, int);
int qdrant(int, int, int);

int x, y;
int max;
int main(void)
{
	int n;

	scanf("%d %d %d", &n, &x, &y);

	max = 1;
	for (int i = 1; i <= n; ++i)
		max *= 2;

	int result = z_count(0, 0, max);

	printf("%d\n", result - 1);

	return 0;
}

int z_count(int x_s, int y_s, int n)
{
	if(n == 0)
		return 0;

	int q_res = qdrant(x, y, n);
	int q_this = qdrant(x_s, y_s, n);

	if(q_res < q_this)
		return 0;
	else if(x_s == x && y_s == y)
		return 1;
	else if(q_res == q_this)
	{
		int sum = 0;
		sum += z_count(x_s, y_s, n/2) 
			+ z_count(x_s, y_s + n/2, n/2) 
			+ z_count(x_s + n/2, y_s, n/2) 
			+ z_count(x_s + n/2, y_s + n/2, n/2);

		return sum;
	}
	else
		return n*n;
}

int qdrant(int x_s, int y_s, int n)
{
	int a = (x_s/n)%2;
	int b = (y_s/n)%2;

	return 2*a + b;
}
