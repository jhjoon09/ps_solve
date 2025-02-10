#include <iostream>
#include <queue>

using namespace std;

int N,M;
int board[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int count(void){
	int ret = 0;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j)
			ret += board[i][j];
	}

	return ret;
}

int melt(void){
	int visit[100][100] = {0 ,};
	queue<pair<int,int>> q;

	q.push(make_pair(0,0));

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; ++i){
			int tx = x + dx[i];
			int ty = y + dy[i];

			if(tx < 0 || ty < 0 || tx >= N || ty >= M)
				continue;

			if(visit[tx][ty] == 1)
				continue;

			visit[tx][ty] = 1;

			if(board[tx][ty] == 1){
				board[tx][ty] = 0;
				continue;
			}

			q.push(make_pair(tx,ty));
		}
	}
	

	return count();
}

pair<int,int> solve(void){
	int c = 0;
	int ret = count();
	int next = ret;

	while(1){
		++c;
		next = melt();
		if(next == 0){
			break;
		}

		ret = next;
	}	

	return make_pair(c,ret);
}

int main(void){
	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> board[i][j];
		}
	}

	pair<int,int> ret = solve();

	cout << ret.first << endl << ret.second << endl;

	return 0;
}
