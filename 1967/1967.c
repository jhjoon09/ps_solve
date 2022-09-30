#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	int max;
	int length;
	int size;

	struct _node** n_temp;
}Node;

int max_side(Node*);
int max_length(Node*);

int main(void)
{
	int n;

	scanf("%d", &n);

	Node* n_list = (Node*)malloc(sizeof(Node) * n);

	for (int i = 0; i < n; ++i)
	{
		n_list[i].data = 0;
		n_list[i].max = 0;
		n_list[i].length = 0;
		n_list[i].size = 0;

		n_list[i].n_temp = NULL;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		++(n_list[a - 1].size);
		n_list[a - 1].n_temp = realloc(n_list[a - 1].n_temp, sizeof(Node*) * n_list[a - 1].size);
		n_list[a - 1].n_temp[n_list[a - 1].size - 1] = &n_list[b - 1];
		n_list[b - 1].data = c;
	}

	max_side(&n_list[0]);
	int result = max_length(&n_list[0]);

	printf("%d\n", result);

	free(n_list);

	return 0;
}

int max_side(Node* n_Ptr)
{
	if (n_Ptr == NULL)
		return 0;

	int a = 0;
	int b = 0;

	for (int i = 0; i < n_Ptr->size; ++i)
	{
		int temp = max_side(n_Ptr->n_temp[i]);

		if (temp > a)
		{
			b = a;
			a = temp;
		}
		else if (temp > b)
		{
			b = temp;
		}
	}

	n_Ptr->max = a + n_Ptr->data;
	n_Ptr->length = a + b;

	return n_Ptr->max;
}

int max_length(Node* n_Ptr)
{
	if (n_Ptr == NULL)
		return 0;

	int a = 0;

	for (int i = 0; i < n_Ptr->size; ++i)
	{
		int temp = max_length(n_Ptr->n_temp[i]);

		if (temp > a)
			a = temp;
	}

	if (a < n_Ptr->length)
		return n_Ptr->length;
	else
		return a;
}

