#include <stdio.h>
#include <string.h>

int fri[50][50];
int n;

int cou(int a);

int main(void)
{
	char yn;


	scanf("%d\n", &n);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			scanf("%c", &yn);
	
			if(yn == 'N')
				fri[i][j] = 0;
			else
				fri[i][j] = 1;
		}
		
		while(getchar() != '\n');
	}

	int max = 0;

	for(int i = 0; i < n; ++i)
	{

		int temp = cou(i);
		if(temp > max)
			max = temp;
	}

	printf("%d\n", max);

	return 0;
}

int cou(int a)
{
	for(int i = 0; i < n; ++i)
	{
		if(fri[a][i] == 1)
		{
			for(int j = 0; j < n; ++j)
			{
				if((fri[a][j] == 0 && fri[i][j] == 1) && a != j)
					fri[a][j] = 2;
			}
		}
	}

	int count = 0;
	for(int i = 0; i < n; ++i)
	{
		if(fri[a][i] != 0)
			++count;
	}

	return count;
}
