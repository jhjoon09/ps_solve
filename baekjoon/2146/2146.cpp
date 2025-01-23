#include <iostream>
#include <queue>
#include <set>

#define INF 987654321;

using namespace std;

int N;
int board[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int spread(int x, int y, int c){
	if(x < 0 || x >= N || y < 0 || y >= N)
		return 1;

	if(board[x][y] != 1)
		return 1;

	board[x][y] = c;


	for(int i = 0; i < 4; ++i)
		spread(x+dx[i], y+dy[i], c);

	return 0;	
}

int color(void){
	int c = 1;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(board[i][j] == 1){
				spread(i,j,++c);
			}
		}
	}

	return c;
}

int solve(void){
	set<pair<pair<int,int>,int>> visited;
	int min = INF;
	color();

	queue<pair<pair<int,int>,pair<int,int>>> q;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(board[i][j] != 0){
				q.push(make_pair(make_pair(i,j), make_pair(0,board[i][j])));
			}
		}
	}

	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;

		int n = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if(x < 0 || y < 0 || x >= N || y >= N)
			continue;

		if(visited.find(make_pair(make_pair(x,y),c)) != visited.end())
			continue;

		visited.insert(make_pair(make_pair(x,y),c));

		if(board[x][y] != 0 && board[x][y] != c)
			return n-1;
		
		for(int i = 0; i < 4; ++i)
			q.push(make_pair(make_pair(x+dx[i],y+dy[i]), make_pair(n+1, c)));		
	}

	return min;
}

int main(void){
	cin >> N;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cin >> board[i][j];
	}

	cout << solve() << endl;

	return 0;
}
