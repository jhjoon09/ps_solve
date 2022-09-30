#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int u_sort(long**, int);
int l_sort(long**, int);

int main(void)
{
	int n, op;
	int end = 1;

	scanf("%d", &n);

	long* heap = (long*)malloc(sizeof(long) * (n + 1));
	memset(heap, 0, sizeof(long) * (n + 1));

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &op);

		if (op == 0)
		{
			if (*(heap + 1) != 0)
			{
				printf("%ld\n", *(heap + 1));
				*(heap + 1) = *(heap + end - 1);
				*(heap + end - 1) = 0;
				--end;

				u_sort(&heap, end);
			}
			else
				printf("0\n");
		}
		else
		{
			*(heap + end) = op;
			++end;

			l_sort(&heap, end);
		}
	}

	free(heap);

	return 0;
}

int u_sort(long** pHeap, int end)
{
	int n = 1;

	while (n < end)
	{
		if (n * 2 + 1 < end)
		{
			if ((*pHeap)[n * 2] > (*pHeap)[n * 2 + 1])
			{
				if ((*pHeap)[n * 2 + 1] < (*pHeap)[n])
				{
					long temp = (*pHeap)[n];
					(*pHeap)[n] = (*pHeap)[n * 2 + 1];
					(*pHeap)[n * 2 + 1] = temp;

					n = n * 2 + 1;
				}
				else
					return 1;
			}
			else if ((*pHeap)[n * 2 + 1] >= (*pHeap)[n * 2])
			{
				if ((*pHeap)[n] >  (*pHeap)[n * 2])
				{
					long temp = (*pHeap)[n];
					(*pHeap)[n] = (*pHeap)[n * 2];
					(*pHeap)[n * 2] = temp;
					n = n * 2;
				}
				else
					return 1;
			}
			else
				return 1;

		}
		else if (n * 2 < end)
		{
			if ((*pHeap)[n] > (*pHeap)[n * 2])
			{
				long temp = (*pHeap)[n];
				(*pHeap)[n] = (*pHeap)[n * 2];
				(*pHeap)[n * 2] = temp;

				n *= 2;
			}
			else
				return 1;
		}
		else
		{
			return 1;
		}
	}

	return 1;
}

int l_sort(long** pHeap, int end)
{
	int pos = end - 1;

	while (pos > 1)
	{
		if ((*pHeap)[pos] < (*pHeap)[pos / 2])
		{
			long temp = (*pHeap)[pos];
			(*pHeap)[pos] = (*pHeap)[pos / 2];
			(*pHeap)[pos / 2] = temp;

			pos /= 2;
		}
		else
			return 1;
	}

	return 1;
}
