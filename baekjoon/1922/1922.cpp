#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

struct compare{
	bool operator()(pair<int,int> &a, pair<int,int> &b){
		if(a.second > b.second)
			return true;
		if(a.second < b.second)
			return false;

		if(a.first > b. second)
			return true;

		return false;
	}
};

int N;
int visit[MAX];
vector<pair<int,int>> graph[MAX];

int main(void){
	int M;
	priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
	int count = 0;
	int ret = 0;
	int min = 987654321;
	int s,e;

	cin >> N >> M;

	while(--M >= 0){
		int a,b,c;
		cin >> a >> b >> c;

		--a;
		--b;

		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));

		if(c < min){
			s = a;
			e = b;
			min = c;
		}
	}
		
	++count;
	visit[s] = 1;
	visit[e] = 1;
	ret += min;

	for(vector<pair<int,int>>::iterator i = graph[s].begin(); i != graph[s].end(); ++i)
		pq.push(*i);

	for(vector<pair<int,int>>::iterator i = graph[e].begin(); i != graph[e].end(); ++i)
		pq.push(*i);

	while(count < N-1){
		int to = pq.top().first;
		int w = pq.top().second;
		pq.pop();

		if(visit[to] == 1)
			continue;

		visit[to] = 1;
		ret += w;
		++count;

		for(vector<pair<int,int>>::iterator i = graph[to].begin(); i != graph[to].end(); ++i)
			pq.push(*i);

	}

	cout << ret << endl;

	return 0;
}
