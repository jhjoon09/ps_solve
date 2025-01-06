#include <stdio.h>

typedef struct _node
{
	int pos;
	Node* head_Ptr;

}Node;

int main(void)
{
	Node* node_list = malloc(sizeof(Node*));

	int N,M;

	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; ++i)
	{
		int oper;
		int in1, in2;

		scanf("%d %d %d", &oper, &in1, &in2);

		if(oper == 0)
		{
			merge_group(in1, in2);
		}
		else
		{
			check_group(in1, in2);
		}
	}

	return 0;

}

int merge_group(int in1, int in2)
{

}

int check_group(int in1, int in2)
{

	
}
