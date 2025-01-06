#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	char data;
	struct _node* left_Ptr;
	struct _node* right_Ptr;
}Node;

Node* left_child(Node*, char);
Node* right_child(Node*, char);

int pre(Node*);
int mid(Node*);
int pos(Node*);

int main(void)
{
	int N;

	scanf("%d", &N);

	char a, b, c;

	while (getchar() != '\n');

	scanf("%c %c %c", &a, &b, &c);
	--N;

	Node* head = (Node*)malloc(sizeof(Node));
	head->data = a;
	head->right_Ptr = NULL;
	head->left_Ptr = NULL;

	Node* t_Node[26] = { 0, };
	t_Node[a - 'A'] = head;

	if (b != '.')
	{
		t_Node[b - 'A'] = left_child(t_Node[a - 'A'], b);
	}

	if (c != '.')
	{
		t_Node[c - 'A'] = right_child(t_Node[a - 'A'], c);
	}

	while (N > 0)
	{
		--N;
		while (getchar() != '\n');

		scanf("%c %c %c", &a, &b, &c);

		if (b != '.')
		{
			t_Node[b - 'A'] = left_child(t_Node[a - 'A'], b);
		}

		if (c != '.')
		{
			t_Node[c - 'A'] = right_child(t_Node[a - 'A'], c);
		}
	}

	pre(head);
	printf("\n");
	mid(head);
	printf("\n");
	pos(head);
	printf("\n");

	for (int i = 0; i < 26; ++i)
	{
		if (t_Node[i] != NULL)
			free(t_Node[i]);
	}

	return 0;
}

Node* left_child(Node* paren, char input)
{
	Node* in_Node = (Node*)malloc(sizeof(Node));

	in_Node->data = input;
	in_Node->left_Ptr = NULL;
	in_Node->right_Ptr = NULL;

	paren->left_Ptr = in_Node;

	return in_Node;
}

Node* right_child(Node* paren, char input)
{
	Node* in_Node = (Node*)malloc(sizeof(Node));

	in_Node->data = input;
	in_Node->left_Ptr = NULL;
	in_Node->right_Ptr = NULL;

	paren->right_Ptr = in_Node;

	return in_Node;
}

int pre(Node* t_Node)
{
	if (t_Node == NULL)
		return 0;

	printf("%c", t_Node->data);
	pre(t_Node->left_Ptr);
	pre(t_Node->right_Ptr);

	return 1;
}

int mid(Node* t_Node)
{
	if (t_Node == NULL)
		return 0;

	mid(t_Node->left_Ptr);
	printf("%c", t_Node->data);
	mid(t_Node->right_Ptr);

	return 1;
}

int pos(Node* t_Node)
{
	if (t_Node == NULL)
		return 0;

	pos(t_Node->left_Ptr);
	pos(t_Node->right_Ptr);
	printf("%c", t_Node->data);

	return 1;
}
