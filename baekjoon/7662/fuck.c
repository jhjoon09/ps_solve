#include <stdio.h>

int end;

int return_max(int*);
int return_min(int*);

int insert(int*, int);
int delete(int*, int);

int check_level(int);

int push_down(int*, int);
int push_down_min(int*, int);
int push_down_max(int*, int);

int push_up(int*, int);
int push_up_min(int*, int);
int push_up_max(int*, int);

int find_min(int*, int);
int find_max(int*, int);

int main(void)
{
	int t, n;
	char oper;
	int input;

	int heap[1000001] = {0, };

	scanf("%d", &t);

	for(int i = 0; i < t; ++i)
	{
		scanf("%d", &n);

		end = 1;
		for(int j = 0; j < n; ++j)
		{
			while(getchar() != '\n');

			scanf("%c %d", &oper, &input);

			if(oper == 'I')
				insert(heap, input);
			else
				delete(heap, input);
		}

		if(end <= 1)
			printf("EMPTY\n");
		else
			printf("%d %d\n", return_max(heap), return_min(heap));
	
	}

	return 0;
}

int return_min(int* heap)
{
	return heap[1];
}

int return_max(int* heap)
{
	if(end == 2)
		return heap[1];
	else if(end == 3)
		return heap[2];
	else
		return heap[2]>heap[3] ? heap[2] : heap[3];
}

int insert(int* heap, int input)
{
	heap[end] = input;
	++end;

	push_up(heap, end-1);

	return 0;
}

int delete(int* heap, int type)
{
	if(end <= 1)
		return 0;

	if(type == 1)
	{
		if(end == 2)
		{
			int max = heap[1];
			heap[1] = 0;
			--end;

			return max;
		}
		else if(end == 3)
		{
			int max = heap[2];
			heap[2] = 0;
			--end;
			
			return max;
		}
		else
		{
			int index = heap[2]>heap[3]? 2 : 3;
			int max = heap[index];
			heap[index] = heap[end-1];
			heap[end-1] = 0;
			--end;

			push_down(heap, index);

			return max;
		}
	}
	else
	{
		int min = heap[1];
		heap[1] = heap[end-1];
		heap[end-1] = 0;
		--end;

		push_down(heap, 1);
	}
}

int check_level(int pos)
{
	while(pos > 1)
		pos /= 4;

	return pos;
}

int push_up(int* heap, int pos)
{
	if(pos != 1)
	{
		if(check_level(pos) == 1)
		{
			if(heap[pos] > heap[pos/2])
			{
				int temp = heap[pos];
				heap[pos] = heap[pos/2];
				heap[pos/2] = temp;

				push_up_max(heap, pos/2);
			}
			else
				push_up_min(heap, pos);
		}
		else
		{
			if(heap[pos/2] > heap[pos])
			{
				int temp = heap[pos];
				heap[pos] = heap[pos/2];
				heap[pos/2] = temp;
				
				push_up_min(heap, pos/2);
			}
			else
				push_up_max(heap, pos);
		}
	}
	else
		return 0;

	return 1;
}

int push_up_min(int* heap, int pos)
{
	if(pos/4 >= 1)
	{
		if(heap[pos/4] > heap[pos])
		{
			int temp = heap[pos];
			heap[pos] = heap[pos/4];
			heap[pos/4] = temp;

			pos /= 4;
		}
		else
			return 0;
	}
	return 1;
}

int push_up_max(int* heap, int pos)
{
	if(pos/4 >= 1)
	{
		if(heap[pos] > heap[pos/4])
		{
			int temp = heap[pos];
			heap[pos] = heap[pos/4];
			heap[pos/4] = temp;

			pos /= 4;
		}
		else
			return 0;
	}
	return 1;   
}


int push_down(int* heap, int pos)
{
	if(check_level(pos) == 1)
	{
		push_down_min(heap, pos);
		return 1;	
	}
	else
	{
		push_down_max(heap, pos);
		return 0;
	}
}

int push_down_min(int* heap, int pos)
{
	int min = 0;

	while(pos * 2 < end)
	{
		int	comp = find_min(heap, pos);

		if(heap[comp] < heap[pos])
		{
			if(comp/4 == pos)
			{
				int temp = heap[pos];
				heap[pos] = heap[comp];
				heap[comp] = temp;

				if(heap[comp] < heap[comp*2])
				{
					temp = heap[comp];
					heap[comp] = heap[comp*2];
					heap[comp*2] = temp;

					push_up_max(heap, comp*2);

					return 0;
				}

				pos = comp;
			}
			else
			{
				int temp = heap[pos];
				heap[pos] = heap[comp];
				heap[comp] = temp;

				return 2;
			}
		}
		else
			return -1;
	}

	return 1;
}

int push_down_max(int* heap, int pos)
{
	int max = 0;

	while(pos * 2 < end)
	{
		int comp = find_max(heap, pos);

		if(heap[comp] > heap[pos])
		{
			if(comp/4 == pos)
			{
				int temp = heap[pos];
				heap[pos] = heap[comp];
				heap[comp] = temp;

				if(heap[comp] > heap[comp*2])
				{
					temp = heap[comp];
					heap[comp] = heap[comp*2];
					heap[comp*2] = temp;

					push_up_min(heap, comp*2);

					return 0;
				}

				pos = comp;
			}
			else
			{
				int temp = heap[pos];
				heap[pos] = heap[comp];
				heap[comp] = temp;

				return 2;
			}
		}
		else
			return -1;
	}

	return 1;

}

int find_min(int* heap, int pos)
{

	int x[] = {2,2,4,4,4,4};
	int p[] = {0,1,0,1,2,3};

	int comp = pos*2;
	
	for(int i = 0; i < 6; ++i)
	{
		int temp = pos*x[i] + p[i];
		if(temp >= end)
			return comp;

		if(heap[comp] > heap[temp])
			comp = temp;
	}

	return comp;
}

int find_max(int* heap, int pos)
{
	int x[] = {2,2,4,4,4,4};
	int p[] = {0,1,0,1,2,3};

	int comp = pos*2;

	for(int i = 0; i < 6; ++i)
	{
		int temp = pos*x[i] + p[i];
		if(temp >= end)
			return comp;

		if(heap[temp] > heap[comp])
			comp = temp;
	}
}
