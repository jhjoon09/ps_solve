#include <stdio.h>

int check(int*, int);
int digit(int);

int main(void)
{
	int n;
	int m;
	int but[10] = { 0, };


	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; ++i)
	{
		int input;
		scanf("%d", &input);
		but[input] = 1;
	}

	int result = n > 100 ? n - 100 : 100 - n;

	int temp = n;

	while (check(but, temp) != 0 && temp >= 0)
	{
		--temp;
	}

	if (check(but, temp) == 0)
	{
		temp = digit(temp) + n - temp;

		if (result > temp)
			result = temp;
	}

	temp = n;

	while (temp - n <= result)
	{
		if (check(but, temp) == 0)
			break;

		++temp;
	}

	if (check(but, temp) == 0)
	{
		temp = digit(temp) + temp - n;

		if (result > temp)
			result = temp;
	}

	printf("%d\n", result);

	return 0;
}

int check(int* button, int n)
{
	if (n < 0)
		return 1;

	if (n == 0)
	{
		if (button[0] != 0)
			return 1;
		else
			return 0;
	}

	while (n != 0)
	{
		int temp = n % 10;
		n /= 10;

		if (*(button + temp) != 0)
			return 1;
	}

	return 0;
}

int digit(int n)
{
	if (n == 0)
		return 1;

	int re = 0;

	while (n != 0)
	{
		n /= 10;
		++re;
	}

	return re;
}
