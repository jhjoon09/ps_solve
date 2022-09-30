#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N,K;
	
	int max = 0;
	int sum = 0;

	scanf("%d %d", &N, &K);

	int* pie = (int*)malloc(sizeof(int) * N);

	for(int i = 0; i < N; ++i)
		scanf("%d", pie + i);

	for(int i = 0; i < K; ++i)
		sum += pie[i];

	max = sum;

	int start = K;
	int end = 0;

	while(start != K-1)
	{
		sum -= pie[end];
		sum += pie[start];

		if(sum > max)
			max = sum;

		start = (start + 1) % N;
		end = (end + 1) % N;
	}

	printf("%d\n", max);

	return 0;
}
