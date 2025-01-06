#include <stdio.h>
#define SIZE 500000

int main(void)
{
	int que[SIZE];
	int n;

	scanf("%d", &n);
	
	int front = 0;
	int rear = n-1;

	for(int i = 0; i < n; ++i)
		que[i] = i + 1;

	for(int i = 1; i < n; ++i)
	{
		front = (front + 1) % SIZE;
		rear = (rear + 1) % SIZE;

		que[rear] = que[front];
		
		front = (front + 1) % SIZE;
	}

	printf("%d\n", que[front]);

	return 0;
}

/*
#include <stdio.h>

int main(void)
{
	int que[500001];
	int n;

	scanf("%d", &n);

	int front = 0;
	int rear = n-1;

	for(int i = 0; i < n; ++i)
		que[i] = i + 1;

	for(int i = 1; i < n; ++i)
	{
		++front;
		if(front >= 500000)
			front = 0;
		++rear;
		if(rear >= 500000)
			rear = 0;

		que[rear] = que[front];

		++front;
		if(front >= 500000)
			front = 0;
	}

	printf("%d\n", que[front]);

	return 0;
}
*/
