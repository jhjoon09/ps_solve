#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int t, n, m;
int input[2][MAX];
int sub_a[MAX * MAX];
int sub_b[MAX * MAX];

int make_sub(int*, int*, int);
int compare(const void*, const void*);
long long div_search(int, int);

int main(void)
{
	scanf("%d", &t);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", input[0] + i);

	scanf("%d", &m);

	for (int i = 0; i < m; ++i)
		scanf("%d", input[1] + i);

	int a_num = make_sub(input[0], sub_a, n);
	int b_num = make_sub(input[1], sub_b, m);

	qsort(sub_a, a_num, sizeof(int), compare);
	qsort(sub_b, b_num, sizeof(int), compare);

	long long ret = div_search(a_num, b_num);

	printf("%lld\n", ret);

	return 0;
}

int make_sub(int* input, int* out, int num)
{
	int pos = 0;
	int sum = 0;

	for (int i = 0; i < num; ++i)
	{
		sum = 0;

		for (int j = i; j < num; ++j)
		{
			sum += input[j];
			out[pos] = sum;
			++pos;
		}
	}

	return pos;
}

int compare(const void* a, const void* b)
{
	int x = *((int*)a);
	int y = *((int*)b);

	if (x > y)
		return 1;
	else if (x == y)
		return 0;
	else
		return -1;
}

long long div_search(int num_a, int num_b)
{
	int i = 0;
	int j = num_b - 1;

	long long count = 0;

	while (i < num_a && j >= 0)
	{
		if (sub_a[i] + sub_b[j] > t)
			--j;
		else if (sub_a[i] + sub_b[j] < t)
			++i;
		else
		{
			int temp = sub_a[i];
			long long a = 0;
			while (i < num_a)
			{
				if (temp == sub_a[i])
					++i, ++a;
				else
					break;
			}

			temp = sub_b[j];
			long long b = 0;

			while (j >= 0)
			{
				if (temp == sub_b[j])
					--j, ++b;
				else
					break;
			}

			count += a * b;
		}
	}

	return count;
}
