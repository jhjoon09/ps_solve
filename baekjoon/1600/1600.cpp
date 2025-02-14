#include <iostream>
#include <queue>

using namespace std;

int K,W,H;
int board[200][200];
int dp[200][200][31];

int dw[] = {0, 0, 1, -1};
int dh[] = {1, -1, 0, 0};

int hw[] = {2, 2, -2, -2, 1, 1, -1, -1};
int hh[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct state{
	int w;
	int h;
	int k;
	int c;
};

queue<state> q;

int solve(void){
	int ret = -1;
	q.push({0,0,K,0});

	while(!q.empty()){
		state st = q.front();
		q.pop();

		if(st.w < 0 || st.h < 0 || st.w >= W || st.h >= H || st.k < 0)
			continue;
		
		if(board[st.h][st.w] == 1)
			continue;

		if(dp[st.h][st.w][st.k] != 0)
			continue;

		dp[st.h][st.w][st.k] = 1;

		if(st.w == W-1 && st.h == H-1){
			ret = st.c;
			break;
		}

		for(int i = 0; i < 4; ++i)
			q.push({st.w+dw[i], st.h + dh[i], st.k, st.c+1});

		for(int i = 0; i < 8; ++i)
			q.push({st.w+hw[i], st.h + hh[i], st.k-1, st.c+1});
	}

	return ret;
}

int main(void){
	cin >> K >> W >> H;

	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			cin >> board[i][j];
		}
	}

	cout << solve() << endl;

	return 0;
}
