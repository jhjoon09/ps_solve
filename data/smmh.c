#include <stdio.h>

int insert(int*, int, int*);
int extract(int*, int, int*);
int extract_min(int*, int);
int extract_max(int*, int);

int insert(int* heap, int input, int* end)
{
	int pos = *end;
	heap[pos] = input;
	++(*end);

	while(pos > 3)
	{
		if(pos % 2 == 1 && heap[pos-1] > heap[pos])
		{
			int temp = heap[pos-1];
			heap[pos-1] = heap[pos];
			heap[pos] = temp;
			--pos;
		}

		if(heap[pos] < heap[pos/4 * 2])
		{
			int temp = heap[pos/4 * 2];
			heap[pos/4 * 2] = heap[pos];
			heap[pos] = temp;
			pos = pos/4 * 2;
		}
		else if(heap[pos] > heap[pos/4 * 2 + 1])
		{
			int temp = heap[pos/4 * 2 + 1];
			heap[pos/4 * 2 + 1] = heap[pos];
			heap[pos] = temp;
			pos = pos/4 * 2 + 1;
		}
		else
			break;

	}

	if(pos == 3 && heap[2] > heap[3])
	{
		int temp = heap[2];
		heap[2] = heap[3];
		heap[3] = temp;
	}

}

int extract(int* heap, int type, int* end)
{
	if(*end <= 2)
		return -1;
	else if(*end == 3)
	{
		int temp = heap[2];
		heap[2] = 0;
		--(*end);
		return 1;
	}

	if(type == 1)
	{
		extract_max(heap, end);
	}
	else
		extract_min(heap, end);

	return 0;
}

int extract_min(int* heap, int* end)
{
	int result = heap[2];
	heap[2] = heap[*end -1];
	heap[*end-1] = 0;
	--(*end);

	int size = (*end) -1;
	int pos = 2;

	while(pos <= size)
	{
		if(pos+1 < size && heap[pos] > heap[pos+1])
		{
			int temp = heap[pos];
			heap[pos] = heap[pos+1];
			heap[pos+1] = temp;
		}
		
		int nxt = pos * 2;
	
		if(nxt > size)
			break;

		if((pos+1)*2 <= size && heap[nxt] > heap[(pos+1) * 2])
			nxt = (pos+1) * 2;

		if(heap[pos] > heap[nxt])
		{
			int temp = heap[pos];
			heap[pos] = heap[nxt];
			heap[nxt] = temp;
			pos = nxt;
		}
		else
			break;
	}

	return result;
}

int extract_max(int* heap, int* end)
{
	int result = heap[3];
	heap[3] = heap[*end -1];
	heap[*end -1] = 0;
	--(*end);

	int size = (*end) - 1;
	int pos = 3;

	while(pos <= size)
	{
		if(heap[pos-1] > heap[pos])
		{
			int temp = heap[pos];
			heap[pos] = heap[pos-1];
			heap[pos-1] = temp;
		}

		int nxt = (pos-1) * 2 + 1;
		if(nxt > size)
			break;
		if(pos*2 + 1 <= size && heap[nxt] < heap[pos*2 + 1])
			nxt = pos*2 + 1;

		if(heap[pos] < heap[nxt])
		{
			int temp = heap[pos];
			heap[pos] = heap[nxt];
			heap[nxt] = temp;

			pos = nxt;
		}
		else
			break;
	}
}
