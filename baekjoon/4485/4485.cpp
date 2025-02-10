#include <iostream>
#include <queue>

using namespace std;

int N;
int board[125][125];
int dp[125][125];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct compare{
	bool operator()(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
		if(a.second < b.second)
			return false;

		return true;
	}
};

int move(){
	priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, compare> pq;
	pq.push(make_pair(make_pair(0,0), board[0][0]));

	while(!pq.empty()){
		int x = pq.top().first.first;
		int y = pq.top().first.second;
		int c = pq.top().second;
		pq.pop();
	
		if(dp[x][y] != -1)
			continue;

		dp[x][y] = c;

		if(x == N-1 && y == N-1)
			break;

		for(int i = 0; i < 4; ++i){
			int tx = x + dx[i];
			int ty = y + dy[i];

			if(tx < 0 || ty < 0 || tx >= N || ty >= N)
				continue;
				
			pq.push(make_pair(make_pair(tx, ty),c+board[tx][ty]));
		}
	}

	return dp[N-1][N-1];	
}

int solve(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	return move();
}

int main(void){
	int t = 0;
	
	cin >> N;
	while(N != 0){
		int ret = solve();
		cout << "Problem " << ++t << ": " << ret << endl;
		cin >> N;
	}

	return 0;
}
