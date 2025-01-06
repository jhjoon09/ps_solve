#include <stdio.h>

int data[1000000];
int end;

int up_sort(int);
int down_sort(int);
int deque_max(void);
int deque_min(void);
int enque(int);
int pri_que(int);
int find(void);

int main(void)
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		int k;
		scanf("%d", &k);

		end = 1;

		for (int j = 0; j < k; ++j)
		{
			char oper = '0';
			int input = 0;
			while (getchar() != '\n');
			scanf("%c", &oper);
			scanf("%d", &input);

			if (oper == 'I')
			{
				enque(input);
			}
			else if (oper == 'D')
			{
				if (input == 1)
				{
					deque_max();
				}
				else
				{
					deque_min();
				}
			}
		}

		if (end == 1)
			printf("EMPTY\n");
		else
		{
			printf("%d %d\n", pri_que(1), pri_que(-1));
		}
	}

	return 0;
}

int up_sort(int pos)
{
	if (pos >= end)
		return 1;

	while (pos > 1)
	{
		if (data[pos / 2] < data[pos])
		{
			long temp = data[pos];
			data[pos] = data[pos / 2];
			data[pos / 2] = temp;
			pos /= 2;
		}
		else
			return 1;

	}

	return 0;
}

int down_sort(int pos)
{
	while (pos * 2 < end)
	{
		if (pos * 2 + 1 < end)
		{
			if (data[pos * 2] < data[pos * 2 + 1])
			{
				if (data[pos] < data[pos * 2 + 1])
				{
					long temp = data[pos * 2 + 1];
					data[pos * 2 + 1] = data[pos];
					data[pos] = temp;
					pos = pos * 2 + 1;
				}
				else return 1;
			}
			else if (data[pos] < data[pos * 2])
			{
				long temp = data[pos];
				data[pos] = data[pos * 2];
				data[pos * 2] = temp;
				pos *= 2;
			}
			else
				return 0;
		}
		else if (data[pos] < data[pos * 2])
		{
			long temp = data[pos];
			data[pos] = data[pos * 2];
			data[pos * 2] = temp;
			pos *= 2;
		}
		else
			return 0;

	}

	return 0;
}

int deque_max(void)
{
	if (end == 1)
		return 0;

	int temp = data[1];
	data[1] = data[end - 1];
	data[end - 1] = 0;
	--end;

	down_sort(1);

	return temp;
}

int deque_min(void)
{
	if (end == 1)
		return 0;

	int pos = find();
	int temp = data[pos];
	data[pos] = data[end - 1];
	data[end - 1] = 0;
	--end;

	down_sort(pos);
	up_sort(pos);

	return temp;
}

int enque(int input)
{
	data[end] = input;
	++end;

	up_sort(end - 1);

	return 0;
}

int pri_que(int a)
{
	if (a == 1)
		return data[1];
	else
		return data[find()];
}

int find()
{
	int temp = 1;

	for (int i = 1; i < end; ++i)
	{
		if (data[temp] >= data[i])
		{
			temp = i;
		}
	}

	return temp;
}

