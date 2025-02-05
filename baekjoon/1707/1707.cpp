#include <iostream>
#include <queue>

#define MAX 20001

using namespace std;

int N,E;
int visited[MAX];
vector<int> graph[MAX];

int init(void){
	for(int i = 0; i <= N; ++i){
		visited[i] = 0;
		graph[i].clear();
	}

	return 0;
}

int bfs(int e, int group){
	queue<pair<int,int>> q;

	q.push(make_pair(e,group));

	while(!q.empty()){
		int e = q.front().first;
		int g = q.front().second;
		q.pop();

		if(visited[e] == g)
			continue;

		if(visited[e] != 0)
			return 0;
		
		visited[e] = g;

		g *= -1;

		for(auto& i : graph[e]){
			q.push(make_pair(i,g));
		}
	}

	return 1;
}

int solve(void){
	int ret = 1;

	cin >> N >> E;

	for(int i = 0; i < E; ++i){
		int a,b;
		cin >> a >> b;

		--a;
		--b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 0; i < N; ++i){
		if(visited[i] == 0){
			if(bfs(i,1) == 0){
				ret = 0;
			}
		}

		if(ret == 0)
			break;
	}

	init();

	return ret;
}

int main(void){
	int K;

	cin >> K;

	while(--K>=0){
		int ret = solve();
		cout << (ret == 0 ? "NO" : "YES" ) << endl;
	}

	return 0;
}
