#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct _node
{
	int name;
	int pos;
	int height;

	struct _node* l_Ptr;
	struct _node* r_Ptr;
}Node;

Node n_list[MAX];
int min[MAX];
int max[MAX];
int count[MAX];

int ret;
int num_node;

Node* make_node(int);
int find_root(int);
void make_child(int, int, int);
void make_pos(Node*);

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);
		make_child(a, b, c);
	}

	int root = find_root(n);

	make_pos(&n_list[root - 1]);

	int max_h = 0;

	for (int i = 0; i < n; ++i)
	{
		int h = n_list[i].height;
		int p = n_list[i].pos;

		if(h > max_h)
			max_h = h;

		if (min[h] == 0)
		{
			min[h] = p;
			max[h] = p;
		}

		if (min[h] > p)
			min[h] = p;

		if (max[h] < p)
			max[h] = p;
	}

	int ret = 0;

	for(int i = 1; i <= max_h; ++i)
	{
		if(max[i] - min[i] > max[ret] - min[ret])
			ret = i;
	}

	printf("%d %d\n", ret + 1, max[ret] - min[ret] + 1);

	return 0;
}

Node* make_node(int name)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->name = name;
	temp->pos = 0;
	temp->height = 0;
	temp->l_Ptr = NULL;
	temp->r_Ptr = NULL;
}

void make_child(int a, int b, int c)
{
	++count[a - 1];

	if (b != -1)
	{
		++count[b - 1];
		n_list[a - 1].l_Ptr = &n_list[b - 1];
	}

	if (c != -1)
	{
		++count[c - 1];
		n_list[a - 1].r_Ptr = &n_list[c - 1];
	}
}

int find_root(int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (count[i] == 1)
			return i + 1;
	}
}

void make_pos(Node* p_Node)
{
	if (p_Node == NULL)
		return;

	int h = p_Node->height;

	if (p_Node->l_Ptr != NULL)
		(p_Node->l_Ptr)->height = h + 1;

	if (p_Node->r_Ptr != NULL)
		(p_Node->r_Ptr)->height = h + 1;

	make_pos(p_Node->l_Ptr);

	p_Node->pos = num_node + 1;
	++num_node;

	make_pos(p_Node->r_Ptr);
}
