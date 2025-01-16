#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

int N,M,K;
int board[1000][1000];
bool visit[1000][1000][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve(){
	queue<pair<pair<int,int>, pair<int,int>>> Q;
	Q.push(make_pair(make_pair(0,0), make_pair(1,0)));

	while(!Q.empty()){
		pair<int,int> pos = Q.front().first;
		int cnt = Q.front().second.first;
		int bc = Q.front().second.second;

		Q.pop();

		if(pos.first == N-1 && pos.second == M-1)
			return cnt;

		if(pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= M)
			continue;

		if(board[pos.first][pos.second] == 1)
			++bc;

		if(bc > K)
			continue;

		if(visit[pos.first][pos.second][bc] == true)
			continue;

		visit[pos.first][pos.second][bc] = true;

		++cnt;
		

		for(int i = 0; i < 4; ++i)
			Q.push(make_pair(make_pair(pos.first + dx[i], pos.second + dy[i]), make_pair(cnt, bc)));
	}

	return -1;
}

int main(void){
	cin >> N >> M >> K;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			char temp;
			cin >> temp;
			board[i][j] = temp == '0' ? 0 : 1;
		}
	}

	cout << solve() << endl;	

	return 0;
}
