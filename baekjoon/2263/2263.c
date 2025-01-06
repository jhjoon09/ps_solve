#include <stdio.h>
#define MAX 100000

int make_Node(int, int, int, int);

int in_list[MAX];
int post_list[MAX];
int root_pos[MAX+1];

int main(void)
{
	int n;
	scanf("%d", &n);
	//in
	//left root right
	for (int i = 0; i < n; ++i)
		scanf("%d", in_list + i);
	//post
	//left right root
	for (int i = 0; i < n; ++i)
		scanf("%d", post_list + i);

	for (int i = 0; i < n; ++i)
	{
		root_pos[in_list[i]] = i;
	}

	make_Node(0, n-1, 0, n-1);
	//pre
	//root left right
	printf("\n");

	return 0;
}

int make_Node(int in_start, int in_end, int post_start, int post_end)
{
	if (in_start > in_end || post_start > post_end)
		return 0;

	int root = post_list[post_end];

	printf("%d ", root);

	int in_root = root_pos[root];

	int post_right = (in_root - in_start) + post_start;

	make_Node(in_start, in_root - 1, post_start, post_right-1);
	make_Node(in_root + 1, in_end, post_right, post_end-1);

	return 1;
}
