#include <iostream>

using namespace std;

int N;
int board[500][500];
int dp[500][500];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y){
	int max = 0;

	if(dp[x][y] != 0)
		return dp[x][y];

	dp[x][y] = 1;

	for(int i = 0; i < 4; ++i){
		int t_x = x + dx[i];
		int t_y = y + dy[i];
	
		if(t_x < 0 || t_y < 0 || t_x >= N || t_y >= N)
			continue;	

		if(board[t_x][t_y] <= board[x][y])
			continue;

		int temp = dfs(t_x, t_y);

		max = max > temp ? max : temp;
	}		

	dp[x][y] = max+1;

	return dp[x][y];
}

int solve(){
	int max = 0;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			int temp = dfs(i,j);
			max = max>temp ? max : temp;			
		}
	}

	return max;
}

int main(void){
	cin >> N;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}

	cout << solve() << endl;

	return 0;
}
