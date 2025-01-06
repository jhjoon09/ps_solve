#include <stdio.h>     

int main(void)
{
	int t = 0;

	scanf("%d", &t);

	char p[100001];
	int n[100001];

	for (int i = 0; i < t; ++i)
	{
		while (getchar() != '\n');

		scanf("%s", p);
		int count;
		scanf("%d", &count);

		while (getchar() != '[');

		for (int j = 0; j < count; ++j)
		{
			scanf("%d", n + j);
			getchar();
		}

		int start = 0;
		int end = count - 1;
		int flag = 1;
		int k = 0;

		while (p[k] != '\0')
		{
			if (p[k] == 'R')
			{
				int temp = start;
				start = end;
				end = temp;
			}
			else
			{
				if (count == 0)
				{
					flag = 0;
					break;
				}

				if (start > end)
				{
					--count;
					--start;
				}
				else if (start < end)
				{
					--count;
					++start;
				}
				else
				{
					count = 0;
				}
			}

			++k;
		}

		if (flag == 0)
		{
			printf("error\n");
			continue;
		}
		else
		{
			if (count == 0)
			{
				printf("[]\n");
			}
			else if (start < end)
			{
				printf("[");
				for (int i = start; i < end; ++i)
				{
					printf("%d,", *(n + i));
				}
				printf("%d]\n", *(n + end));
			}
			else
			{
				printf("[");

				for (int i = start; i > end; --i)
				{
					printf("%d,", *(n + i));
				}
				printf("%d]\n", *(n + end));
			}
		}

	}
	return 0;
}
