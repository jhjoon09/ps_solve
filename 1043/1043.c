#include <stdio.h>                                                                                                      

int truth[51];
int graph[51][51];
int party[50][51];

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int person;
	scanf("%d", &person);

	int que[50];
	int start = 0;
	int end = 0;

	for (int i = 0; i < person; ++i)
	{
		int temp;
		scanf("%d", &temp);

		truth[temp] = 1;

		que[end] = temp;
		++end;
	}


	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &party[i][0]);

		for (int j = 1; j <= party[i][0]; ++j)
			scanf("%d", &party[i][j]);

		for (int j = 1; j <= party[i][0]; ++j)
		{
			int a = party[i][j];

			for (int k = j + 1; k <= party[i][0]; ++k)
			{
				int b = party[i][k];

				graph[a][b] = 1;
				graph[b][a] = 1;
			}
		}
	}

	while (start < end)
	{
		int temp = que[start];

		for (int i = 1; i <= N; ++i)
		{
			if (graph[temp][i] == 1)
			{
				if (truth[i] == 0)
				{
					que[end] = i;
					++end;
					truth[i] = 1;
				}
			}
		}

		++start;
	}

	int lie = 0;

	for (int i = 0; i < M; ++i)
	{
		int count = party[i][0];
		int flag = 1;

		for (int j = 1; j <= count; ++j)
		{
			if (truth[party[i][j]] != 0)
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			++lie;
	}

	printf("%d\n", lie);
}
