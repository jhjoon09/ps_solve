#include <stdio.h>

int main(void)
{
	int que[1001];
	int n;
	int k; 

	scanf("%d %d", &n, &k);

	int front = 0;
	int rear = n-1;

	for(int i = 0; i < n; ++i)
		que[i] = i + 1;

	printf("<");

	for(int i = 1; i < n; ++i)
	{
		for(int j = 1; j < k; ++j)
		{
			++rear;
			if(rear >= 1000)
				rear = 0;

			que[rear] = que[front];

			++front;
			if(front >= 1000)
				front = 0;

		}

		printf("%d, ", que[front]);
		++front;
		if(front >= 1000)
			front = 0;
	}

	printf("%d>", que[front]);

	return 0;
}
