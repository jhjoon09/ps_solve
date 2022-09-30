#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define MAX 1000

struct Edge
{
	int from;
	int to;
	int weight;
};

struct Node
{
	int to;
	int weight;

	Node(int t, int w) : to(t), weight(w) {}
};

struct cmp {
	bool operator()(Node a, Node b)
	{
		return a.weight > b.weight;
	}
};

int w_dis[MAX + 1];
int pivot[MAX + 1];
int visit[MAX + 1];

int compare(const void*, const void*);

int main(void)
{
	int V, E;

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; ++i)
		w_dis[i] = INT_MAX;

	Edge* edge_list = (Edge*)malloc(sizeof(Edge) * E);

	for (int i = 0; i < E; ++i)
		scanf("%d %d %d", &edge_list[i].from, &edge_list[i].to, &edge_list[i].weight);

	qsort(edge_list, E, sizeof(Edge), compare);

	int s_city;
	int e_city;

	scanf("%d %d", &s_city, &e_city);

	int temp = 0;
	w_dis[s_city] = 0;

	for (int i = 0; i < E; ++i)
	{
		if (edge_list[i].from > temp)
		{

			temp = edge_list[i].from;
			pivot[temp] = i;
		}
	}

	priority_queue<Node, vector<Node>, cmp> pq;

	pq.push(Node(s_city, 0));

	int check_ver;

	while (pq.empty() == false)
	{
		Node n_temp = pq.top();
		pq.pop();

		check_ver = n_temp.to;

		if (visit[check_ver] == 1)
			continue;

		if (w_dis[check_ver] == INT_MAX)
			break;
		visit[check_ver] = 1;

		for (int i = pivot[check_ver]; edge_list[i].from == check_ver; ++i)
		{
			Edge* t_edge = edge_list + i;

			if (w_dis[t_edge->to] > w_dis[check_ver] + t_edge->weight)
			{
				w_dis[t_edge->to] = w_dis[check_ver] + t_edge->weight;
				pq.push(Node(t_edge->to, w_dis[t_edge->to]));
			}
		}
	}

	printf("%d\n", w_dis[e_city]);

	free(edge_list);

	return 0;
}

int compare(const void* a, const void* b)
{
	Edge* x = (Edge*)a;
	Edge* y = (Edge*)b;

	if (x->from > y->from)
	{
		return 1;
	}
	else if (x->from == y->from)
	{
		if (x->to > y->to)
			return 1;
		else if (x->to == y->to)
		{
			if (x->weight > y->weight)
				return 1;
			else if (x->weight == y->weight)
				return 0;
			else
				return -1;
		}
		else
			return -1;
	}
	else
		return -1;
}
