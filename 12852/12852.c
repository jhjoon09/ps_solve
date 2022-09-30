#include <stdio.h>

#define MAX 1000000

int que[MAX];
int count[MAX+1];
int past[MAX+1];

int trace(int, int);

int main(void)
{
	int n;
	scanf("%d", &n);

	if(n == 1)
	{
		printf("0\n1\n");
		return 0;
	}

	que[0] = n;

	int start = 0;
	int end = 1;

	while(start != end)
	{
		int temp = que[start];

		if(temp % 3 == 0 && count[temp/3] == 0)
		{
			que[end] = temp/3;
			++end;
			count[temp/3] = count[temp] + 1;	
			
			past[temp/3] = temp;

			if(temp == 3)
				break;
		}

		if(temp % 2 == 0 && count[temp/2] == 0)
		{
			que[end] = temp/2;
			++end;
			count[temp/2] = count[temp] + 1;
	
			past[temp/2] = temp;

			if(temp == 2)
				break;
		}

		if(count[temp-1] == 0)
		{
			que[end] = temp-1;
			++end;
			count[temp-1] = count[temp]+1;
		
			past[temp-1] = temp;

			if(temp == 2)
				break;
		}

		++start;
	}

	printf("%d\n", count[1]);

	trace(1, count[1]);
	printf("1\n");

	return 0;
}

int trace(int start, int c)
{
	if(c == 1)
	{
		printf("%d ", past[start]);
		return 0;
	}

	trace(past[start], c-1);

	printf("%d ", past[start]);

	return 0;
}
