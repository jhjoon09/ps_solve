#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

int main(void)
{
	cin.tie(NULL);

	int N, M;

	scanf("%d %d", &N, &M);

	unordered_map<string, int> num_pocket;

	for (int i = 1; i <= N; ++i)
	{
		string name;

		cin >> name;

		num_pocket.insert(make_pair(name, i));
	}

	priority_queue<string, vector<string>, greater<string>> pq;

	for (int i = 0; i < M; ++i)
	{
		string name;

		cin >> name;
		
		if(num_pocket.count(name) != 0)
		{
			pq.push(name);
		}
	}

	cout << pq.size() << '\n';

	while(pq.empty() != true)
	{
		cout << pq.top() << '\n';

		pq.pop();
	}

	return 0;
}
