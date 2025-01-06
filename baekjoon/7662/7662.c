#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int insert(long*, long, int*);
long extract(long*, int, int*);
long extract_min(long*, int*);
long extract_max(long*, int*);

int main(void)
{
	int end = 2;
	long heap[1000010] = { 0, };

	int t, n;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		end = 2;
		memset(heap, 0, sizeof(heap));

		scanf("%d", &n);

		for (int j = 0; j < n; ++j)
		{
			while (getchar() != '\n');

			char oper;
			long input;

			scanf("%c %ld", &oper, &input);

			if (oper == 'I')
			{
				insert(heap, input, &end);
			}
			else
				extract(heap, input, &end);
		}

		if (end == 2)
			printf("EMPTY\n");
		else if (end == 3)
			printf("%ld %ld\n", heap[2], heap[2]);
		else
			printf("%ld %ld\n", heap[3], heap[2]);
	}

	return 0;
}


int insert(long* heap, long input, int* end)
{
	int pos = *end;
	heap[pos] = input;
	++(*end);

	while (pos > 3)
	{
		if (pos % 2 == 1 && heap[pos - 1] > heap[pos])
		{
			long temp = heap[pos - 1];
			heap[pos - 1] = heap[pos];
			heap[pos] = temp;
			--pos;
		}
		else if(pos%2 == 0 && pos + 1 < *end -1)
		{
			if(heap[pos] > heap[pos+1])
			{
				long temp = heap[pos+1];
				heap[pos+1] = heap[pos];
				heap[pos] = temp;
				++pos;
			}
		}

		if (heap[pos] < heap[pos / 4 * 2])
		{
			long temp = heap[pos / 4 * 2];
			heap[pos / 4 * 2] = heap[pos];
			heap[pos] = temp;
			pos = pos / 4 * 2;
		}
		else if (heap[pos] > heap[pos / 4 * 2 + 1])
		{
			long temp = heap[pos / 4 * 2 + 1];
			heap[pos / 4 * 2 + 1] = heap[pos];
			heap[pos] = temp;
			pos = pos / 4 * 2 + 1;
		}
		else
			break;

	}

	if (pos == 3 && heap[2] > heap[3])
	{
		long temp = heap[2];
		heap[2] = heap[3];
		heap[3] = temp;
	}

}

long extract(long* heap, int type, int* end)
{
	long temp = -1;

	if (*end <= 2)
		return temp;
	else if (*end == 3)
	{
		temp = heap[2];
		heap[2] = 0;
		--(*end);
		return temp;
	}

	if (type == 1)
	{
		temp = extract_max(heap, end);
	}
	else
		temp =extract_min(heap, end);

	return temp;
}

long extract_min(long* heap, int* end)
{
	long result = heap[2];
	heap[2] = heap[*end - 1];
	heap[*end - 1] = 0;
	--(*end);

	int size = (*end) - 1;
	int pos = 2;

	while (pos <= size)
	{
		if (pos + 1 < size && heap[pos] > heap[pos + 1])
		{
			long temp = heap[pos];
			heap[pos] = heap[pos + 1];
			heap[pos + 1] = temp;
		}

		int nxt = pos * 2;

		if (nxt > size)
			break;

		if ((pos + 1) * 2 <= size && heap[nxt] > heap[(pos + 1) * 2])
			nxt = (pos + 1) * 2;

		if (heap[pos] > heap[nxt])
		{
			long temp = heap[pos];
			heap[pos] = heap[nxt];
			heap[nxt] = temp;
			pos = nxt;
		}
		else
			break;
	}

	return result;
}

long extract_max(long* heap, int* end)
{
	long result = heap[3];
	heap[3] = heap[*end - 1];
	heap[*end - 1] = 0;
	--(*end);

	int size = (*end) - 1;
	int pos = 3;

	while (pos <= size)
	{
		if (heap[pos - 1] > heap[pos])
		{
			long temp = heap[pos];
			heap[pos] = heap[pos - 1];
			heap[pos - 1] = temp;
		}

		int nxt = (pos - 1) * 2 + 1;
		if (nxt > size)
			break;
		if (pos * 2 + 1 <= size && heap[nxt] < heap[pos * 2 + 1])
			nxt = pos * 2 + 1;

		if (heap[pos] < heap[nxt])
		{
			long temp = heap[pos];
			heap[pos] = heap[nxt];
			heap[nxt] = temp;

			pos = nxt;
		}
		else
			break;
	}
}
