#include <stdio.h>
#define MAX 1000

int input[MAX];
int goal[MAX];

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", input + i);


	for(int i = 0; i < n; ++i)
		scanf("%d", goal + i);

}
