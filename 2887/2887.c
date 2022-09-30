#include <stdio.h>
#define MAX 100000

int plan[MAX][3];

int cal_dis(int, int);

int main(void)
{
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; ++i)
		scanf("%d %d %d", plan[i]+0, plan[i]+1, plan[i]+2);


}

int cal_dis(int a, int b)
{
	int x = plan[a][0] - plan[b][0];
	int y = plan[a][1] - plan[b][1];

	x = x>0 ? x : -x;
	y = y>0 ? y : -y;

	if(x>y)
		x = y;

	y = plan[a][2] - plan[b][2];

	y = y>0 ? y : -y;

	if(x>y)
		return y;
	else
		return x;
}
