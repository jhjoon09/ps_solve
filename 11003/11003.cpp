#include <stdio.h>
#include <iostream>
#include <queue>
#define MAX 5000000

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, L;

	cin >> N >> L;
	//scanf("%d %d", &N, &L);

	priority_queue<pair<int, int>> min_data;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		//scanf("%d", &temp);

		cin >> temp;

		min_data.push({-temp, i});

		while(min_data.top().second <= i - L)
			min_data.pop();

		cout << -(min_data.top().first) << ' ';
		//printf("%d ", -min_data.top().first);
	}

	return 0;
}
