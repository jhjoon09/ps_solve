#include <iostream>

using namespace std;

int board[101][101];
int N;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int dd[] = {3,0,1,2};

int mark(int x, int y){
	if(x < 0 || y< 0 || x > 100 || y > 100)
		return 0;

	board[x][y] = 1;

	return 1;
}

pair<int,int> draw(int x, int y, int d, int g){
	if(g == 0){
		mark(x,y);
		mark(x+dx[d],y+dy[d]);
		return make_pair(x+dx[d], y+dy[d]);
	}

	pair<int,int> e_pos = draw(x,y,d,g-1);
	int s_x = e_pos.first + (e_pos.second - y);
	int s_y = e_pos.second - (e_pos.first - x);
	

	draw(s_x, s_y, dd[d], g-1);

	return make_pair(s_x,s_y);
}

int count(void){
	int ret = 0;
	
	for(int i = 0; i < 100; ++i){
		for(int j = 0; j < 100; ++j){
			if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
				++ret;
		}
	}

	return ret;
}

int main(void){
	cin >> N;

	while(--N >= 0){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		draw(a,b,c,d);
	}

	cout << count() << endl;

	return 0;
}
