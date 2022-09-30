#include <stdio.h>
#include <limits.h>
#define AVS(a) ((a)>0) ? (a) : -(a)

int n, m;
int home[100][2];
int chick[15][2];
int h_count;
int c_count;
int live[15];

int live_chick(int, int);
int cal_dis(void);

int main(void)
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < 15; ++i)
		live[i] = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		int temp;

		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &temp);

			if (temp == 1)
			{
				home[h_count][0] = i;
				home[h_count][1] = j;
				++h_count;
			}
			else if (temp == 2)
			{
				chick[c_count][0] = i;
				chick[c_count][1] = j;
				++c_count;
			}
		}
	}

	printf("%d\n", live_chick(0, 0));

	return 0;
}

int live_chick(int pos, int count)
{
	if (pos >= c_count)
		return INT_MAX;

	live[count] = pos;

	int a = INT_MAX;
	if (count + 1 == m)
		a = cal_dis();
	else
		a = live_chick(pos + 1, count + 1);

	int b = live_chick(pos + 1, count);

	return a < b ? a : b;
}

int cal_dis(void)
{
	int sum = 0;

	for (int i = 0; i < h_count; ++i)
	{
		int temp = INT_MAX;

		for (int j = 0; j < m; ++j)
		{
			int a = 0;
			for (int k = 0; k <= 1; ++k)
				a += AVS(home[i][k] - chick[live[j]][k]);

			if (temp > a)
				temp = a;
		}

		sum += temp;
	}

	return sum;
}
