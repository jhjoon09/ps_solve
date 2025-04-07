#include <iostream>
#include <vector>
#include <set>

using namespace std;

int X,Y,D;
int board[15][15];
int t_board[15][15];

int get_pos(vector<pair<int,int>>* pos, int y, int x){
	for(int i = 1; i <= D; ++i){
		int tx = x-i;
		int ty = y;
		int dx = 1;
		int dy = -1;

		do{
			tx += dx;
			ty += dy;

			if(tx == x){
				dy = 1;
			}

			if(tx < 0 || tx > X || ty < 0 || ty >= y)
				continue;

			if(t_board[ty][tx] == 1){
				pos->push_back(make_pair(ty, tx));
				return 1;
			}
		}while(ty <= y);
	}

	return 0;
}

int cal(vector<int> pos){
	int level = Y;
	int count = 0;

	for(int i = 0; i < Y; ++i){
		for(int j = 0; j < X; ++j){
			t_board[i][j] = board[i][j];
			count += board[i][j];
		}
	}

	while(level > 0){
		vector<pair<int,int>> t;
		for(int i = 0; i < 3; ++i){
			get_pos(&t, level, pos[i]);	
		}

		for(int i = 0; i < t.size(); ++i){
			int y = t[i].first;
			int x = t[i].second;
			t_board[y][x] = 0;
		}

		--level;
	}

	for(int i = 0; i < Y; ++i){
		for(int j = 0; j < X; ++j){
			count -= t_board[i][j];
		}
	}

	return count;
}

int solve(vector<int> lst, int pos){
	if(lst.size() == 3){
		return cal(lst);
	}

	if(pos >= X)
		return 0;

	int a = solve(lst, pos+1);
	lst.push_back(pos);
	int b = solve(lst, pos+1);

	return a > b ? a : b;
}

int main(void){
	cin >> Y  >> X >> D;

	for(int i = 0; i < Y; ++i){
		for(int j = 0; j < X; ++j){
			cin >> board[i][j];
		}
	}
	vector<int> lst;

	cout << solve(lst, 0) << endl;

	return 0;
}
