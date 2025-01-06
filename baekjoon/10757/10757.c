#include <stdio.h>
#include <string.h>     

int main(void)
{
	char a[10002] = { 0, };
	char b[10002] = { 0, };

	scanf("%s %s", a, b);

	int a_len = strlen(a);
	int b_len = strlen(b);

	char res[10003] = { 0 , };

	int temp = 0;
	int len = 0;
	int up = 0;

	if (a_len >= b_len)
	{
		len = b_len -1;

		res[a_len] = '\0';

		for (int i = a_len - 1; i >= 0; --i)
		{
			if (len < 0)
			{
				len = i;
				break;
			}
			temp = a[i] - '0' + b[len] - '0' + up;
			up = 0;
			--len;
			if (temp >= 10)
			{
				temp -= 10;
				up = 1;
			}
			res[i] = temp + '0';
		}

		for (int i = len; i >= 0; --i)
		{
			temp = a[i] - '0' + up;
			up = 0;
			if (temp >= 10) {
				res[i] = temp - 10 + '0';
				up = 1;
			}
			else
				res[i] = temp + '0';
		}

	}
	else
	{
		len = a_len -1;

		res[b_len] = '\0';

		for (int i = b_len - 1; i >= 0; --i)
		{
			if (len < 0)
			{
				len = i;
				break;
			}
			temp = b[i] - '0' + a[len] - '0' + up;
			up = 0;
			--len;
			if (temp >= 10)
			{
				temp -= 10;
				up = 1;
			}
			res[i] = temp + '0';
		}

		for (int i = len; i >= 0; --i)
		{
			temp = b[i] - '0' + up;
			up = 0;
			if (temp >= 10) {
				res[i] = temp - 10 + '0';
				up = 1;
			}
			else
				res[i] = temp + '0';
		}

	}

	if (up == 1)
		printf("1%s", res);
	else
		printf("%s", res);

	return 0;
}
