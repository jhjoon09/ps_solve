#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct _edge
{
	int from;
	int to;
	int w;

	struct _edge* next_Edge;
}Edge;

typedef struct _node
{
	Edge* e_Ptr;
}Node;

typedef struct _tdis
{
	int dis;
	int end;
}T_dis;

Node* n_Ptr;
int visit[MAX];

T_dis cal_length(int);

int main(void)
{
	int n;

	scanf("%d", &n);

	n_Ptr = (Node*)malloc(sizeof(Node) * n);

	for (int i = 0; i < n; ++i)
	{
		n_Ptr[i].e_Ptr = NULL;
	}

	for (int i = 0; i < n; ++i)
	{
		int a, b, c;

		scanf("%d %d", &a, &b);

		while (b != -1)
		{
			scanf("%d", &c);


			Edge* t_edge = (Edge*)malloc(sizeof(Edge));

			t_edge->from = a - 1;
			t_edge->to = b - 1;
			t_edge->w = c;

			t_edge->next_Edge = n_Ptr[a-1].e_Ptr;

			n_Ptr[a-1].e_Ptr = t_edge;

			scanf("%d", &b);
		}
	}

	T_dis max = cal_length(0);
	max = cal_length(max.end);
	
	printf("%d\n", max.dis);

	for (int i = 0; i < n; ++i)
	{
		Edge* free_edge = n_Ptr[i].e_Ptr;

		while (free_edge != NULL)
		{
			Edge* temp_free = free_edge->next_Edge;
			free(free_edge);
			free_edge = temp_free;
		}
	}

	free(n_Ptr);

	return 0;
}

T_dis cal_length(int pos)
{
	if (visit[pos] != 0)
	{
		T_dis fail;
		fail.end = pos;
		fail.dis = -1000000;

		return fail;
	}
	visit[pos] = 1;

	Edge* temp_Edge = n_Ptr[pos].e_Ptr;

	T_dis max;
	max.dis = 0;
	max.end = pos;

	while (temp_Edge != NULL)
	{
		T_dis temp = cal_length(temp_Edge->to);

		temp.dis += temp_Edge->w;

		if (temp.dis > max.dis)
			max = temp;

		temp_Edge = temp_Edge->next_Edge;
	}

	visit[pos] = 0;

	return max;
}
