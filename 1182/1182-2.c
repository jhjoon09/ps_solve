#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	struct _node* preNode;
	struct _node* afterNode;
	int count;
	int num;
}Node;

typedef struct _list {
	struct _node* head;
	struct _node* tail;
}List;

int main(void)
{
	int n, s;

	scanf("%d %d", &n, &s);

	int data[20] = { 0 , };

	for (int i = 0; i < n; ++i)
		scanf("%d", data + i);

	List* series = (List*)malloc(sizeof(List));

	series->head = NULL;
	series->tail = NULL;

	Node* zero = (Node*)malloc(sizeof(Node));
	zero->preNode = NULL;
	zero->afterNode = NULL;
	zero->count = 1;
	zero->num = 0;

	series->head = zero;
	series->tail = zero;

	for (int i = 0; i < n; ++i)
	{
		if (*(data + i) >= 0)
		{
			Node* temp = series->tail;

			while (temp != NULL)
			{
				Node* pos = series->tail;

				while (1)
				{
					if (pos == NULL)
						break;

					if (pos->num < temp->num + data[i])
					{
						Node* input = (Node*)malloc(sizeof(Node));
						input->num = temp->num + data[i];
						input->count = temp->count;
						input->preNode = pos;
						input->afterNode = pos->afterNode;
						pos->afterNode = input;

						if (input->afterNode == NULL)
							series->tail = input;
						else
							(input->afterNode)->preNode = input;

						break;
					}
					else if (pos->num == temp->num + data[i])
					{
						pos->count += temp->count;

						break;
					}
					pos = pos->preNode;

				}

				temp = temp->preNode;
			}
		}
		else
		{
			Node* temp = series->head;

			while (temp != NULL)
			{
				Node* pos = series->head;

				while (1)
				{
					if (pos == NULL)
						break;

					if (pos->num > temp->num + data[i])
					{
						Node* input = (Node*)malloc(sizeof(Node));
						input->num = temp->num + data[i];
						input->count = temp->count;
						input->afterNode = pos;
						input->preNode = pos->preNode;
						pos->preNode = input;

						if (input->preNode == NULL)
							series->head = input;
						else
							(input->preNode)->afterNode = input;

						break;

					}
					else if (pos->num == temp->num + data[i])
					{
						pos->count += temp->count;

						break;
					}

					pos = pos->afterNode;

				}

				temp = temp->afterNode;
			}
		}
	}
	--(zero->count);

	Node* result = series->head;

	while (result != NULL)
	{
		if (result->num == s)
		{
			printf("%d\n", result->count);

			result = series->head;

			while (result != NULL)
			{
				Node* trash = result;
				result = result->afterNode;
				free(trash);
			}

			free(series);

			return 0;
		}

		result = result->afterNode;
	}

	printf("0\n");

	Node* temp = series->head;
	Node* trash = NULL;

	while (temp != NULL)
	{
		trash = temp;
		temp = temp->afterNode;
		free(trash);
	}

	free(series);

	return 0;
}
