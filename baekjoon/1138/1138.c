#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	struct _node* aftNode;
	int count;
	int n;
}NODE;

typedef struct _list {
	struct _node* head;
	int num;
}LIST;

int main(void)
{
	int n;

	scanf("%d", &n);

	int* count;
	count = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
		scanf("%d", count + i);

	LIST* line = malloc(sizeof(LIST));
	line->head = NULL;
	line->num = 0;

	for (int i = n - 1; i >= 0; --i)
	{
		NODE* input = malloc(sizeof(NODE));
		input->aftNode = NULL;
		input->count = i + 1;
		input->n = count[i];

		if (line->num == 0)
		{
			line->head = input;
			++(line->num);
		}
		else
		{

			if (count[i] == 0)
			{
				input->aftNode = line->head;
				line->head = input;
			}
			else
			{
				NODE* temp = line->head;

				for (int j = 1; j < count[i]; ++j)
					temp = temp->aftNode;

				input->aftNode = temp->aftNode;
				temp->aftNode = input;
			}

			++(line->num);
		}
	}

	NODE* temp = line->head;
	NODE* trash = NULL;

	while (temp != NULL)
	{
		printf("%d ", temp->count);
		trash = temp;
		temp = temp->aftNode;
		free(trash);
	}

	printf("\n");

	free(line);

	free(count);

	return 0;
}

