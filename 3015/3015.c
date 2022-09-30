#include <stdio.h>
#define MAX 500000

int input[MAX];

int main(void)
{
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", input + i);

}
