#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

int R,C;
char board[51][51];
int count[50][50];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solve(void){
	queue<pair<pair<int,int>,int>> q;
	queue<pair<pair<int,int>,int>> d;

	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			count[i][j] = INF;

			if(board[i][j] == '*')
				q.push(make_pair(make_pair(i,j),0));
			else if(board[i][j] == 'X')
				count[i][j] = 0;
			else if(board[i][j] == 'S')
				d.push(make_pair(make_pair(i,j),0));
		}
	}

	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if(x < 0 || y < 0 || x >= R || y >= C)
			continue;

		if(count[x][y] <= c)
			continue;

		if(board[x][y] == 'D')
			continue;

		count[x][y] = c;

		for(int i = 0; i < 4; ++i)
			q.push(make_pair(make_pair(x+dx[i],y+dy[i]),c+1));
	}

	while(!d.empty()){
		int x = d.front().first.first;
		int y = d.front().first.second;
		int c = d.front().second;
		
		d.pop();
	
		if(x < 0 || y < 0 || x >= R || y >= C)
			continue;

		if(board[x][y] == 'D')
			return c;

		if(count[x][y] <= c)
			continue;

		count[x][y] = c;


		for(int i = 0; i < 4; ++i)
				d.push(make_pair(make_pair(x+dx[i],y+dy[i]),c+1));
	}
	
	return -1;
}

int main(void){
	cin >> R >> C;

	for(int i = 0; i < R; ++i)
		cin >> board[i];

	int ret = solve();

	if(ret < 0)
		cout << "KAKTUS\n";
	else
		cout << ret << endl;

	return 0;
}
