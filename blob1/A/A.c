#include <stdio.h>
#include <stdlib.h>

int N;

int main(void)
{
	scanf("%d", &N);

	int* tower = (int*)malloc(sizeof(int) * N);

	for(int i = 0; i < N; ++i);
		scanf("%d", tower + i);
}
