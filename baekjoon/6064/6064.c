#include <stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i = 0; i < T; ++i)
	{
		int M,N,x,y;
		scanf("%d %d %d %d", &M, &N, &x, &y);

		if(N > M)
		{
			int temp = N;
			N = M;
			M = temp;

			temp = x;
			x = y;
			y = temp;
		}

		int count = x;

		while(count <= M*N)
		{
			if(count % N == 0 && y == N)
				break;

			if(count % N == y)
				break;

			count += M;
		}

		if(count > M * N)
			count = -1;

		printf("%d\n", count);
	}

	return 0;
}
