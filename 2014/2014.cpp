#include <queue>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main(void)
{
	int k,n;
	int input[100];
	scanf("%d %d", &k, &n);

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 0; i < k; ++i)
	{
		scanf("%u", input + i);
		pq.push(input[i]);
	}

	long long temp = 0;

	while(n > 0)
	{
		if(pq.top() == temp)
		{
			pq.pop();
			continue;
		}

		--n;

		temp = pq.top();
		for(int i = 0; i < k; ++i)
		{
			if(temp * input[i] > INT_MAX)
				break;

			pq.push(temp * input[i]);
		}
		pq.pop();
	}

	printf("%lld\n", temp);

	return 0;
}
