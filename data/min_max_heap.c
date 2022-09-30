#include <stdio.h>

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
		comp = find_min(heap, pos);

		if(heap[comp] < heap[pos])
		{
			if(com/4 == pos)
			{
				int temp = heap[pos];
				heap[pos] = heap[comp];
				heap[comp] = temp;

				if(heap[comp] < heap[comp*2])
				{
					temp = heap[comp];
					heap[comp] = heap[comp*2];
					heap[comp*2] = temp;

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
		comp = find_max(heap, pos);

		if(heap[comp] > heap[pos])
		{
			if(com/4 == pos)
			{
				int temp = heap[pos];
				heap[pos] = heap[comp];
				heap[comp] = temp;

				if(heap[comp] > heap[comp*2])
				{
					temp = heap[comp];
					heap[comp] = heap[comp*2];
					heap[comp*2] = temp;

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

	return temp;
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
