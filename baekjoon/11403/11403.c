#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct _node{
	int x;
	int y;
	int dis;
	struct _node * p_Next;
}Node;

typedef struct _que{
	int count;
	struct _node * front;
	struct _node * back;
}Que;

int matrix[MAX][MAX];

int empty(Que*);
int enque(Que*, int, int, int);
Node* deque(Que*);

int main(void)
{
	int n = 0;

	Que* que = (Que*)malloc(sizeof(Que));
	
	que->count = 0;
	que->front = NULL;
	que->back = NULL;

	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			scanf("%d", &matrix[i][j]);

			if(matrix[i][j] == 1)
			{
				enque(que, i, j, 1);
			}
		}
	}

	Node * temp;
	while(empty(que) != 1)
	{
		temp = deque(que);
		
		for(int i = 0; i < n; ++i)
		{
			if(matrix[i][temp->x] != 0 && matrix[i][temp->y] == 0)
			{
				matrix[i][temp->y] = temp->dis + 1;

				enque(que, i, temp->y, temp->dis + 1);
			}
		}

		free(temp);
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(matrix[i][j] != 0)
				printf("1 ");
			else
				printf("0 ");
		}

		printf("\n");
	}

	return 0;
}

int empty(Que* que)
{
	if(que->count == 0)
		return 1;
	else
		return 0;
}

int enque(Que* que, int x, int y, int dis)
{
	Node* input = malloc(sizeof(Node));
	
	input->x = x;
	input->y = y;
	input->dis = dis;
	input->p_Next = NULL;

	if(empty(que) == 1)
	{
		que->front = input;
		que->back = input;
		++(que->count);
	}
	else
	{
		(que->back)->p_Next = input;
		que->back = input;
		++(que->count);
	}

	return 0;
}

Node* deque(Que* que)
{
	Node* temp = que->front;

	que->front = temp->p_Next;
	--(que->count);

	return temp;
}
