#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;
	int front = 0;
	int back = 0;
	int input = 0;

	char order[10] = {0 ,};

	scanf("%d", &n);

	int* que = (int*) malloc(sizeof(int) * n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%s", order);
	
		if(strcmp(order, "push") == 0)
		{
			scanf("%d", &input);

			*(que + back) = input;
			++back;
		}
		else if(strcmp(order, "pop") == 0)
		{
			if(front == back)
				printf("-1\n");
			else
			{
				printf("%d\n", *(que + front));
				++front;
			}
		}
		else if(strcmp(order, "size") == 0)
		{
			printf("%d\n", back - front);
		}
		else if(strcmp(order, "empty") == 0)
		{
			if(front == back)
				printf("1\n");
			else
				printf("0\n");
		}
		else if(strcmp(order, "front") == 0)
		{
			if(front == back)
				printf("-1\n");
			else
				printf("%d\n", *(que + front));
		}
		else
		{
			if(front == back)
				printf("-1\n");
			else
				printf("%d\n", *(que + back -1));
		}


	}


	free(que);

	return 0;
}
