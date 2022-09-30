#include <stdio.h>
#define MAX 100000

int list[MAX];

int N,S;

int compare(const void*, const void*);

int main(void)
{
	scanf("%d %d", &N, &S);

	for(int i = 0; i < N; ++i)
		scanf("%d", list+i);

	int end = 0;
	int min = MAX;
	int sum = 0;

	for(int i = 0; i < N; ++i)
	{
		sum += list[i];

		while(sum >= S)
		{
			if(min > i - end + 1)
				min = i - end + 1;

			sum -= list[end];
			++end;
		}
	}
	
	printf("%d\n", min);

	return 0;
}
