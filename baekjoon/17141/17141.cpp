#include <iostream>
#include <queue>

#define MAX 123456789

using namespace std;

int N,M;
int board[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int spread(queue<pair<int,int>> q){
	int count = 0;
	int time = 0;
	int t_board[50][50];
	queue<pair<int,int>> n_q = q;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(board[i][j] == 1){
				t_board[i][j] = 1;
			}else{
				t_board[i][j] = 0;
				++count;
			}
		}
	}

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		t_board[x][y] = 1;
	}

	swap(q, n_q);

	while(!q.empty()){
		++time;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			--count;

			for(int i = 0; i < 4; ++i){
				int n_x = x + dx[i];
				int n_y = y + dy[i];

				if(n_x < 0 || n_y < 0 || n_x >= N || n_y >= N)
					continue;

				if(t_board[n_x][n_y] != 0)
					continue;
				t_board[n_x][n_y] = 1;
				n_q.push(make_pair(n_x, n_y));
			}
		}
		swap(q,n_q);
	}


	if(count != 0)
		time = MAX;
	else
		--time;

	return time;
}

int solve(queue<pair<int,int>> q, int pos){
	if(q.size() == M)
		return spread(q);

	if(pos >= N*N)
		return MAX;

	int x = pos % N;
	int y = pos / N;

	if(board[x][y] == 2){

		int a = solve(q, pos+1);
		q.push(make_pair(x,y));
		int b = solve(q, pos+1);

		return a < b ? a : b;
	}else{
		return solve(q, pos+1);
	}
}

int main(void){
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}
	queue<pair<int,int>> q;

	int ret = solve(q, 0);

	if(ret == MAX)
		ret = -1;

	cout << ret << endl;

	return 0;
}
