#include <stdio.h>
#define SIZE 100

int main(void)
{
	int que[SIZE] = {0,};
	int t,n,m;

	scanf("%d", &t);

	for(int k = 0; k < t; ++k)
	{
		scanf("%d %d", &n, &m);

		int front = 0;
		int rear = n;

		for(int i = 0; i < n; ++i)
			scanf("%d", que + i);

		int count = 0;

		while(1)
		{
			int high = 0;

			for(int i = front; i != rear; ++i)
			{
				i %= n;
				if(high < que[i])
					high = que[i];
			}

			while(que[front] != high)
			{
				rear %= n;
				que[rear] = que[front];

				if(m == front)
					m = rear;

				++rear;
				++front;
				front %= n;
			}

			++count;
			if(m == front)
			{
				printf("%d\n", count);
				break;
			}

			++front;
			front %= n;

		}

	}
	
	return 0;
}
