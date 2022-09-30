#include <stdio.h>                                                                                                      
int n, m, i;
char temp;

int cal(void);

int main(void)
{
	int count = 0;

	scanf("%d %d", &n, &m);

	while (getchar() != '\n');

	temp = '\0';
	scanf("%c", &temp);
	i = 1;


	while (i < m)
		count += cal();

	printf("%d\n", count);

	return 0;
}

int cal(void)
{
	int sum = 0;

	while (temp != 'I')
	{
		scanf("%c", &temp);
		++i;

		if (i == m)
			return 0;
	}

	++sum;

	char comp = temp;
	scanf("%c", &temp);
	++i;

	while (comp != temp && i < m)
	{
		++sum;
		comp = temp;
		scanf("%c", &temp);
		++i;
	}

	sum = (sum + 1) / 2;

	return sum > n ? sum - n : 0;
}
