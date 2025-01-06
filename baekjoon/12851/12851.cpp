#include <stdio.h>
#include <limits.h>
#include <queue>

using namespace std;

#define MAX 100000

struct Move
{
	int pos;
	int time;

	Move(int p, int t) : pos(p), time(t) {}
};

struct cmp 
{
	bool operator()(Move a, Move b)
	{
		return a.time > b.time;
	}
};

int time_count[2*MAX +1][2];
int N,K;

int check_able(int, int);

int main(void)
{
	scanf("%d %d", &N, &K);

	if(N >= K)
	{
		printf("%d\n1\n", N-K);
		return 0;
	}

	for(int i = 0; i <= MAX; ++i)
		time_count[i][0] = INT_MAX;

	time_count[N][0] = 0;
	time_count[N][1] = 1;

	priority_queue<Move, vector<Move>, cmp> pq;

	pq.push(Move(N, 0));

	while (pq.empty() == false)
	{
		Move m_temp = pq.top();
		pq.pop();
	
		int t_time = m_temp.time;
		int t_pos = m_temp.pos;

		if(t_time > time_count[K][0])
			break;

		if(t_time > time_count[t_pos][0])
			continue;

		int input = t_pos+1;

		if(check_able(input, t_time+1) == 1)
		{
			if(time_count[input][0] >= t_time + 1)
			{
				if(time_count[input][0] == t_time+1)
				{
					time_count[input][1] += time_count[t_pos][1];
				}
				else
				{
					time_count[input][0] = t_time+1;
					time_count[input][1] = time_count[t_pos][1];

					pq.push(Move(input, t_time+1));
				}
			}
		}


		input = t_pos-1;

		if(check_able(input, t_time+1) == 1)
		{
			if(time_count[input][0] >= t_time + 1)
			{
				if(time_count[input][0] == t_time+1)
				{
					time_count[input][1] += time_count[t_pos][1];
				}
				else
				{
					time_count[input][0] = t_time+1;
					time_count[input][1] = time_count[t_pos][1];

					pq.push(Move(input, t_time+1));
				}
			}
		}

		input = t_pos*2;

		if(check_able(input, t_time+1) == 1)
		{
			if(time_count[input][0] >= t_time + 1)
			{
				if(time_count[input][0] == t_time+1)
				{
					time_count[input][1] += time_count[t_pos][1];
				}
				else
				{
					time_count[input][0] = t_time+1;
					time_count[input][1] = time_count[t_pos][1];

					pq.push(Move(input, t_time+1));
				}
			}
		}
	}

	printf("%d\n%d\n", time_count[K][0], time_count[K][1]);

	return 0;
}

int check_able(int pos, int time)
{
	if(pos < 0)
		return 0;

	if(pos == N)
		return 0;

	if(pos >= 2 * MAX)
		return 0;

	if(pos > K)
	{
		if(pos-K+time > K-N)
			return 0;
	}

	return 1;
}    
