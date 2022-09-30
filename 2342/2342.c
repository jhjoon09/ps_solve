#include <stdio.h>
#include <limits.h>
#define MAX 100001

int end;
int list[MAX];
int dp[MAX][13];

int alter_pos(int);
int move_leg(int, int, int);
int cal_power(int, int);

int main(void)
{
	int temp;
	end = 0;

	do
	{
		scanf("%d", &temp);

		list[end] = alter_pos(temp);
		++end;
	} while (temp != 0);

	--end;

	int min_power = move_leg(0, 0, 0);

	printf("%d\n", min_power);

	return 0;
}

int alter_pos(int t)
{
	if (t == 3)
		return 4;
	else if(t == 4)
		return 8;

	return t;
}

int move_leg(int pos, int left, int right)
{
	if (left == right && left != 0)
		return MAX * 5;


	if (pos == end)
		return 0;

	if (dp[pos][left + right] != 0)
		return dp[pos][left + right];

	int po_left = cal_power(list[pos], left) + move_leg(pos + 1, list[pos], right);

	int po_right = cal_power(list[pos], right) + move_leg(pos + 1, left, list[pos]);

	dp[pos][left + right] = (po_left > po_right) ? po_right : po_left;

	return dp[pos][left + right];
}

int cal_power(int to, int from)
{
	if (from == to)
		return 1;

	if (from == 0)
		return 2;

	if (from + to == 10 || from + to == 5)
		return 4;

	return 3;
}
