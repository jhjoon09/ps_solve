#include <iostream>
#include <queue>

using namespace std;

int solve(void){
	int l;
	pair<int,int> start;
	pair<int,int> dest;
	int visit[300][300] = {0 ,};
	
	int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
	int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

	cin >> l >> start.first >> start.second >> dest.first >> dest.second;

	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(make_pair(start.first, start.second), 0));

	while(!q.empty()){
		pair<int,int> pos = q.front().first;
		int count = q.front().second;
		q.pop();

		if(pos.first < 0 || pos.first >= l || pos.second < 0 || pos.second >= l)
			continue;

		if(visit[pos.first][pos.second] == 1)
			continue;
		
		visit[pos.first][pos.second] = 1;

		if(pos.first == dest.first && pos.second == dest.second)
			return count;

		for(int i = 0; i < 8; ++i){
			q.push(make_pair(make_pair(pos.first + dx[i], pos.second + dy[i]), count+1));
		}
		
	}	

	return 987654321;
}

int main(void){
	int N;
	cin >> N;

	while(--N >= 0){
		cout << solve() << endl;
	}

	return 0;
}
