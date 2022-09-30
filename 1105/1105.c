#include <stdio.h>

int main(void)
{
	int L,R;

	scanf("%d %d", &L, &R);

	int x = 0, y = 0;

	while(L < R)
	{
		x = L % 10;
		y = R % 10;

		L /= 10;
		R /= 10;
	}

	int count =  0;
	
	while(R > 0)
	{
		if(R % 10 == 8)
			++count;

		R /= 10;
	}

	printf("%d\n", count);

	return 0;
}
