#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* left_ptr;
	struct _node* right_ptr;
}Node;

typedef struct _tree
{
	int count;
	Node* head;
}Tree;

int input_node(Tree*, int);
int post(Node*);

int main(void)
{
	Tree* bst = (Tree*)malloc(sizeof(Tree));
	bst->count = 0;
	bst->head = NULL;

	int input;

	while (1)
	{
		if (scanf("%d", &input) == EOF)
			break;

		input_node(bst, input);
	}

	post(bst->head);

	return 0;
}

int input_node(Tree* bst, int data)
{
	Node* input_Node = (Node*)malloc(sizeof(Node));

	input_Node->data = data;
	input_Node->left_ptr = NULL;
	input_Node->right_ptr = NULL;

	if (bst->count == 0)
	{
		bst->head = input_Node;
		++(bst->count);

		return 1;
	}

	Node* temp = bst->head;

	while (1)
	{
		if (temp->data < data)
		{
			if (temp->right_ptr == NULL)
			{
				temp->right_ptr = input_Node;
				++(bst->count);

				return 1;
			}
			else
				temp = temp->right_ptr;
		}
		else
		{
			if (temp->left_ptr == NULL)
			{
				temp->left_ptr = input_Node;
				++(bst->count);

				return 1;
			}
			else
				temp = temp->left_ptr;
		}
	}

	return 0;
}

int post(Node* t_node)
{
	if (t_node == NULL)
		return -1;

	post(t_node->left_ptr);
	post(t_node->right_ptr);

	printf("%d\n", t_node->data);

	free(t_node);

	return 0;
}
