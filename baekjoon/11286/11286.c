#include <stdio.h>
#define ABS(a) (((a)>0)?(a):(-a))
#define MAX 100000

long heap[MAX + 1];

int compare(long, long);
int insert_heap(long, int*);
long delete_heap(int*);

int upper_sort(int*);
int lower_sort(int*);

int main(void)
{
	int n;

	scanf("%d", &n);

	int end = 1;

	for (int i = 0; i < n; ++i)
	{
		long input = 0;
		scanf("%ld", &input);

		if (input == 0)
		{
			printf("%ld\n", delete_heap(&end));
		}
		else
		{
			insert_heap(input, &end);
		}
	}

	return 0;
}

int compare(long a, long b)
{
	if (a == 0)
		return 1;
	if (b == 0)
		return -1;
	if (ABS(a) > ABS(b))
		return 1;
	else if (ABS(a) == ABS(b) && a>b)
		return 1;
	else
		return -1;
}

int insert_heap(long input, int* pEnd)
{
	heap[*pEnd] = input;
	++(*pEnd);

	upper_sort(pEnd);

	return 0;
}

long delete_heap(int* pEnd)
{
	if (*pEnd == 1)
		return 0;

	long result = heap[1];

	heap[1] = heap[(*pEnd) - 1];
	heap[(*pEnd) - 1] = 0;
	--(*pEnd);

	lower_sort(pEnd);

	return result;
}

int upper_sort(int* pEnd)
{
	int i = *pEnd - 1;

	while (i > 1 && (compare(heap[i/2], heap[i]) == 1))
	{
		long temp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = temp;

		i /= 2;
	}

	return 0;
}

int lower_sort(int* pEnd)
{
	int i = 1;

	while (i*2 <= *pEnd-1)
	{

		if (i * 2 + 1 <= *pEnd - 1)
		{
			if (compare(heap[i], heap[i * 2 + 1]) == 1)
			{
				if (compare(heap[i * 2 + 1], heap[i * 2]) == 1)
				{
					long temp = heap[i * 2];
					heap[i * 2] = heap[i];
					heap[i] = temp;
					i *= 2;

					continue;
				}
				else
				{
					long temp = heap[i * 2 + 1];
					heap[i * 2 + 1] = heap[i];
					heap[i] = temp;
					i = i * 2 + 1;

					continue;
				}
			}
		}
		else if (compare(heap[i], heap[i * 2]) == 1)
		{
			long temp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = temp;
			i *= 2;

			continue;
		}

		break;
	}

	return 0;
}
