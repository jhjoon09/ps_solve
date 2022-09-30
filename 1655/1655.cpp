#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
	int n;

	scanf("%d", &n);

	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;

	for(int i = 0; i < n; ++i)
	{
		int temp;

		scanf("%d", &temp);

		if(i == 0)
		{
			pq1.push(temp);
		}
		else if(i == 1)
		{
			if(pq1.top() > temp)
			{
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(temp);
			}
			else
				pq2.push(temp);
		}
		else if(i % 2 == 0)
		{
			if(temp > pq2.top())
			{
				pq2.push(temp);
				pq1.push(pq2.top());
				pq2.pop();
			}
			else
				pq1.push(temp);
		}
		else
		{
			if(temp < pq1.top())
			{
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(temp);
			}
			else
				pq2.push(temp);

		}

		printf("%d\n", pq1.top());
	}


	return 0;
}
