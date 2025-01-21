#include <iostream>

#define INF 987654321

using namespace std;

int N,M,H;
int board[30][12];

int check_board(void){

	for(int i = 1; i <= N; ++i){

		int pos = i;

		for(int h = 0; h < H; ++h){

			if(board[h][pos-1] == 1){
				--pos;
			}else if(board[h][pos] == 1){
				++pos;
			}
		}

		if(pos != i)
			return 0;
	}

	return 1;
}

int dfs(int pos, int depth){
	if(pos >= N * H)
		return INF;

	if(check_board())
		return depth;

	if(depth >= 3)
		return INF;

	int n = pos % N + 1;
	int h = pos / N;
	
	if(board[h][n-1] || board[h][n] || board[h][n+1])
		return dfs(pos+1,depth);

	board[h][n] = 1;
	int t1 = dfs(pos+1, depth+1);
	board[h][n] = 0;
	int t2 = dfs(pos+1, depth);

	return t1>t2? t2 : t1;
}

int solve(void){
	int ret = dfs(0,0);

	return ret == INF ? -1 : ret;
}

int main(void){
	cin >> N >> M >> H;

	for(int i = 0; i < M; ++i){
		int A,B;

		cin >> A >> B;

		board[A-1][B] = 1;
	}	

	cout << solve() << endl;

	return 0;
}
