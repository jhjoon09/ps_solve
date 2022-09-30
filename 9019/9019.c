#include <stdio.h>
#include <string.h>
#define DIV 10000;

int visit[10001];
int queue[10001];
char oper[10000][10001];

int main(void)
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		int A, B;

		scanf("%d %d", &A, &B);

		memset(visit, 0, sizeof(int) * 10001);

		int count = 0;
		int end = 1;
		queue[count] = A;
		visit[A] = 1;

		while (count != end)
		{
			int temp = queue[count];

			if (temp == B)
			{
				printf("%s\n", oper[count]);
				break;
			}

			int input = (temp * 2) % DIV;

			if (visit[input] == 0)
			{
				visit[input] = 1;

				queue[end] = input;
				strcpy(oper[end], oper[count]);
				oper[end][strlen(oper[count])] = 'D';
				oper[end][strlen(oper[count]) + 1] = '\0';

				if (input == B)
				{
					printf("%s\n", oper[end]);
					break;
				}

				++end;
			}

			input = (temp + 9999) % DIV;

			if (visit[input] == 0)
			{
				visit[input] = 1;

				queue[end] = input;
				strcpy(oper[end], oper[count]);
				oper[end][strlen(oper[count])] = 'S';
				oper[end][strlen(oper[count]) + 1] = '\0';

				if (input == B)
				{
					printf("%s\n", oper[end]);
					break;
				}

				++end;
			}

			input = ((temp * 10) % 10000) + (temp / 1000);

			if (visit[input] == 0)
			{
				visit[input] = 1;

				queue[end] = input;
				strcpy(oper[end], oper[count]);
				oper[end][strlen(oper[count])] = 'L';
				oper[end][strlen(oper[count]) + 1] = '\0';

				if (input == B)
				{
					printf("%s\n", oper[end]);
					break;
				}

				++end;
			}

			input = temp / 10 + (temp % 10) * 1000;

			if (visit[input] == 0)
			{
				visit[input] = 1;

				queue[end] = input;
				strcpy(oper[end], oper[count]);
				oper[end][strlen(oper[count])] = 'R';
				oper[end][strlen(oper[count]) + 1] = '\0';

				if (input == B)
				{
					printf("%s\n", oper[end]);
					break;
				}

				++end;
			}

			++count;
		}
	}

	return 0;
}
