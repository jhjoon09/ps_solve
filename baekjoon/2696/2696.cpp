#include <stdio.h>
#include <queue>

using namespace std;

int find_mid(void);

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t > 0)
	{
		--t;
		find_mid();
	}
}

int find_mid(void)
{
	int n;
	scanf("%d", &n);

	printf("%d\n", (n+1)/2);

	priority_queue<int, vector<int>, less<int>> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	
	int count = 1;
	int temp;
	scanf("%d", &temp);

	printf("%d ", temp);

	max_pq.push(temp);
	
	for(int i = 1; i < (n+1)/2; ++i)
	{
		count = (count+1)%10;

		scanf("%d", &temp);
		max_pq.push(temp);
		scanf("%d", &temp);
		max_pq.push(temp);

		min_pq.push(max_pq.top());
		max_pq.pop();
		min_pq.push(max_pq.top());
		max_pq.pop();
		max_pq.push(min_pq.top());
		min_pq.pop();

		printf("%d ", max_pq.top());
		
		if(count == 0)
			printf("\n");
	}

	if(count != 0)
		printf("\n");

	return 0;
}
