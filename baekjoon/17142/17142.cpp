#include <iostream>
#include <queue>

#define MAX 123456789

using namespace std;

int N,M;
int board[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int spread(queue<pair<int,int>> q){
	int time = 0;
	int count = 0;
	int visit[50][50];
	queue<pair<int,int>> n_q = q;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			switch(board[i][j]){
				case 0:
					++count;
				case 2:
					visit[i][j] = 0;
					break;
				case 1:
					visit[i][j] = 1;
					break;
			}
		}
	}

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visit[x][y] = 1;
	}

	swap(n_q, q);

	while(count != 0 && !q.empty()){
		++time;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for(int i = 0; i < 4; ++i){
				int nx = x + dx[i];
				int ny = y + dy[i];

				if(nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if(visit[nx][ny] == 1)
					continue;

				if(board[nx][ny] == 0)
					--count;

				visit[nx][ny] = 1;

				n_q.push(make_pair(nx,ny));
			}
		}

		swap(n_q, q);
	}

	if(count != 0)
		time = MAX;

	return time;
}

int solve(queue<pair<int,int>> q, int pos){
	if(q.size() == M)
		return spread(q);

	if(pos >= N*N)
		return MAX;

	int x = pos % N;
	int y = pos / N;

	if(board[x][y] != 2)
		return solve(q, pos+1);

	int a = solve(q,pos+1);
	q.push(make_pair(x,y));
	int b = solve(q, pos+1);

	return a < b ? a : b;
}

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cin >> board[i][j];
	}

	queue<pair<int,int>> q;

	int ret = solve(q, 0);

	if(ret == MAX)
		ret = -1;

	cout << ret << endl;

	return 0;
}
