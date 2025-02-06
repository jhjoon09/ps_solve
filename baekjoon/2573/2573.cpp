#include <iostream>

using namespace std;

int N,M;
int board[300][300];
int visit[300][300];

int dx[4] = { 0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int melt(void){
	int temp[300][300];

	for(int i = 1; i < N-1; ++i){
		for(int j = 1; j < M-1; ++j){
			int cnt = 0;

			for(int k = 0; k < 4; ++k)
				cnt += (board[i+dx[k]][j+dy[k]] == 0 ? 1 : 0);
			
			temp[i][j] = board[i][j] - cnt;

			if(temp[i][j] < 0)
				temp[i][j] = 0;
		}
	}


	for(int i = 1; i < N-1; ++i){
		for(int j = 1; j < M-1; ++j)
			board[i][j] = temp[i][j];
	}

	return 0;
}

int dfs(int x, int y){
	if(x < 0 || y < 0 || x >= N || y >= M)
		return 0;

	if(visit[x][y] != 0)
		return 0;

	if(board[x][y] == 0)
		return 0;

	visit[x][y] = 1;

	for(int i = 0; i < 4; ++i)
		dfs(x + dx[i], y + dy[i]);

	return 1;
}

int get_count(void){

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j)
			visit[i][j] = 0;
	}

	int count = 0;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			if(board[i][j] != 0 && visit[i][j] == 0){
				dfs(i,j);	
				++count;
			}
		}
	}


	return count;
}

int solve(){
	int ret = 0;

	while(1){
		melt();
		++ret;

		int c = get_count();

		if(c == 0){
			ret = 0;
			break;
		}

		if(c != 1){
			break;
		}
	}

	return ret;
}

int main(void){
	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j)
			cin >> board[i][j];
	}

	cout << solve() << endl;

	return 0;
}
