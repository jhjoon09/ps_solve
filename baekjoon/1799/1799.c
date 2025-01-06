#include <stdio.h>

int chess[10][10];
int n;

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", chess[i] + j);


	return 0;
}
