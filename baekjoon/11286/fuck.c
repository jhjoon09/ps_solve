#include <stdio.h>
#define MAX 100000

long heap[MAX];

int up_sort(int);
int down_sort(int);
int compare(long, long);

int main(void)
{

	int n = 0;
	scanf("%d",&n);

	int end = 1;

	for(int i = 0; i < n; ++i)
	{
		int input = 0;
		scanf("%d", &input);
	
		if(input == 0)
		{
			if(end == 1)
				printf("0\n");
			else
			{
				printf("%ld\n", heap[1]);
				heap[1] = heap[end-1];
				heap[end-1] = 0;
				--end;

				down_sort(end);
			}
		}
		else
		{
			heap[end] = input;
			++end;
			up_sort(end);
		}
	}

	return 0;
}

int up_sort(int end)
{
	int pos = end-1;

	while(pos > 1)
	{
		if(compare(heap[pos/2] , heap[pos]) == 1)
		{
			long temp = heap[pos];
			heap[pos] = heap[pos/2];
			heap[pos/2] = temp;
			pos /= 2;
		}
		else
			return 1;
		
	}

	return 0;
}

int down_sort(int end)
{
	int pos = 1;

	while(pos*2 < end)
	{
		if(pos*2 + 1 < end)
		{
			if(compare(heap[pos*2], heap[pos*2+1]) == 1)
			{
				if(compare(heap[pos], heap[pos*2+1]) == 1)
				{
					long temp = heap[pos*2 + 1];
					heap[pos*2 + 1] = heap[pos];
					heap[pos] = temp;
					pos = pos*2 + 1;
				}
				else return 1;
			}
			else if(compare(heap[pos], heap[pos * 2]) == 1)
			{
				long temp = heap[pos];
				heap[pos] = heap[pos * 2];
				heap[pos * 2] = temp;
				pos *= 2;
			}
			else
				return 0;
		}
		else if(compare(heap[pos], heap[pos * 2]) == 1)
		{
			long temp = heap[pos];
			heap[pos] = heap[pos * 2];
			heap[pos * 2] = temp;
			pos *= 2;
		}
		else
			return 0;

	}

	return 0;

}

int compare(long a, long b)
{
	int ab_a = a>0 ? a : -a;
	int ab_b = b>0 ? b : -b;

	if(ab_a > ab_b)
		return 1;
	else if(ab_a == ab_b && a > b)
		return 1;
	else
		return 0;

}

