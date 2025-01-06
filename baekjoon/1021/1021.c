#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;

	scanf("%d %d", &n, &m);

	int* deq = (int*) malloc(sizeof(int) * n);
	int* out = (int*) malloc(sizeof(int) * m);
	
	for(int i = 1; i <= n; ++i)
		*(deq + i - 1) = i;

	for(int i = 0; i < m; ++i)
		scanf("%d", out + i);


	free(deq);
	free(out);

	return 0;
}
