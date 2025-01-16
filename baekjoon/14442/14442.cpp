#include <iostream>
#define INF 987654321

using namespace std;

int n,m,k;
int board[1000][1000];
int dp[1000][1000][11];

int move(int y, int x, int b, int c){
	if(y < 0 || y >= n || x < 0 || x >= m)
		return -1;

	if(board[y][x] == 1)
		++b;

	if(b > k)
		return -1;

	if(dp[y][x][b] <= c)
		return 1;

	for(int i = b; i <= k; ++i)
		dp[y][x][i] = dp[y][x][i] > c ? c : dp[y][x][i];

	++c;

	move(y+1,x,b,c);
	move(y-1,x,b,c);
	move(y,x+1,b,c);
	move(y,x-1,b,c);

	return 0;
}

int main(void){
	cin >> n >> m >> k;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char temp;
			cin >> temp;
			board[i][j] = temp == '0' ? 0 : 1;
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			for(int x = 0; x <= k; ++x)
				dp[i][j][x] = INF;
		}
	}

	move(0,0,0,1);

	int ret = dp[n-1][m-1][k];

	ret = ret == INF ? -1 : ret;
	cout << ret << endl;

	return 0;
}
