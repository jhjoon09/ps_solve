#include <stdio.h>         

int main(void)
{
	int t;
	int n, m;
	int que[101] = {0 ,};

	int front, rear;
	int pri;
	int count;
	int max;

	scanf("%d", &t);

	for (int k = 0; k < t; ++k)
	{
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; ++i)
			scanf("%d", que + i);

		front = 0;
		rear = n % 100;
		count = 0;

		max = 0;

		while (1)
		{
			max = que[front];

			for (int i = front + 1; i != rear; i = (i+1) % 100)
			{
				if (max < que[i])
				{
					max = que[i];
				}
			}

			while (que[front] != max)
			{
				que[rear] = que[front];
				que[front] = 0;

				if (m == front)
					m = rear;

				++rear;
				rear %= 100;
				++front;
				front %= 100;
			}

			++count;

			if (m == front)
				break;

			max = 0;
			que[front] = 0;
			++front;
			front %= 100;
		}

		printf("%d\n", count);

	}
	return 0;
}
