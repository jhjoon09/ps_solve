#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size(int front, int back, int n);

int main(void)
{
	int n = 0;
	int front = 0;
	int back = 0;
	int input = 0;

	char order[10] = {0 ,};

	scanf("%d", &n);

	int* deq = (int*) malloc(sizeof(int) * n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%s", order);


		if(strcmp(order, "push_front") == 0)
		{
			scanf("%d", &input);
			
			front = (front - 1 + n) % n;
			deq[front] = input;
		}
		else if(strcmp(order, "push_back") == 0)
		{
			scanf("%d", &input);
			deq[back] = input;
			back = (back + 1) % n;
		}
		else if(strcmp(order, "pop_front") == 0)
		{
			if(size(front, back, n) == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", deq[front]);
				front++;
				front %= n;
			}
		}
		else if(strcmp(order, "pop_back") == 0)
		{
			if(size(front, back, n) == 0)
				printf("-1\n");
			else
			{
				back = (back - 1 + n) % n;
				printf("%d\n", deq[back]);
			}
		}
		else if(strcmp(order, "size") == 0)
		{
			printf("%d\n", size(front,back,n));
		}
		else if(strcmp(order, "empty") == 0)
		{
			if(size(front, back, n) == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if(strcmp(order, "front") == 0)
		{
			if(size(front, back, n) == 0)
				printf("-1\n");
			else
				printf("%d\n", *(deq + front));
		}
		else
		{
			if(size(front, back, n) == 0)
				printf("-1\n");
			else
				printf("%d\n", *(deq + ((back -1 + n) % n)));
		}


	}


	free(deq);

	return 0;
}

int size(int front, int back, int n)
{
	return (back >= front ? back -front : n - front + back);
}
