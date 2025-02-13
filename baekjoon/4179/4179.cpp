#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

int R,C;
int board[1000][1000];
char temp[1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void){
	queue<pair<pair<int,int>,int>> fire;
	queue<pair<pair<int,int>,int>> q;
	cin >> R >> C;

	for(int i = 0; i < R; ++i){
		cin >> temp;
		for(int j = 0; j < C; ++j){
			board[i][j] = INF;
			switch(temp[j]){
				case '#' :
					board[i][j] = 1;
					break;
				case 'J' :
					q.push(make_pair(make_pair(i,j), 1));
					break;
				case 'F' :
					fire.push(make_pair(make_pair(i,j), 1));
					break;
			}
		}
	}

	while(!fire.empty()){
		int x = fire.front().first.first;
		int y = fire.front().first.second;
		int c = fire.front().second;

		fire.pop();

		if(x < 0 || y < 0 || x >= R || y >= C)
			continue;

		if(board[x][y] <= c)
			continue;
		
		board[x][y] = c;

		for(int i = 0; i < 4; ++i){
			fire.push(make_pair(make_pair(x + dx[i], y + dy[i]), c+1));
		}
	}

	int ret = INF;

	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second;

		q.pop();

		if(x < 0 || y < 0 || x >= R || y >= C)
			continue;

		if(board[x][y] <= c)
			continue;

		board[x][y] = c;

		if(x == 0 || y == 0 || x == R-1 || y == C-1){
			ret = c;
			break;
		}

		for(int i = 0; i < 4; ++i)
			q.push(make_pair(make_pair(x+dx[i], y + dy[i]), c+1));
	}

	if(ret == INF)
		cout << "IMPOSSIBLE\n";
	else
		cout << ret << endl;

	return 0;
}
