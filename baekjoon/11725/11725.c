#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct _edge
{
	int to;
	struct _edge* next_Ptr;
}Edge;

typedef struct _list
{
	int pos;
	struct _edge* start;
	struct _edge* end;
}List;

int line[MAX + 1];
int que[MAX + 1];

int make_line(List*, int);

int main(void)
{
	int N;

	scanf("%d", &N);


	List* e_list = (List*)calloc(N + 1, sizeof(List));

	for (int i = 0; i <= N; ++i)
	{
		line[i] = 0;

		e_list[i].pos = i;
		e_list[i].start = NULL;
		e_list[i].end = NULL;
	}

	for (int i = 0; i < N-1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		make_line(&e_list[a], b);
		make_line(&e_list[b], a);
	}

	int start = 0;
	int end = 1;
	que[start] = 1;
	line[1] = 1;

	while (start < end)
	{
		Edge* temp = e_list[que[start]].start;
		int from = e_list[que[start]].pos;

		while (temp != NULL)
		{
			if (line[temp->to] == 0)
			{
				line[temp->to] = from;
				que[end] = temp->to;
				++end;
			}

			temp = temp->next_Ptr;
		}

		++start;
	}

	for (int i = 2; i <= N; ++i)
		printf("%d\n", line[i]);

	return 0;
}

int make_line(List* e_list, int a)
{
	Edge* input = (Edge*)malloc(sizeof(Edge));
	input->to = a;
	input->next_Ptr = NULL;

	if (e_list->start == NULL)
	{
		e_list->start = input;
		e_list->end = input;
	}
	else
	{
		(e_list->end)->next_Ptr = input;
		e_list->end = input;
	}

	return 1;
}
