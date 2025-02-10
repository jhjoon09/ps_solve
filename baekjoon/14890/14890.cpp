#include <iostream>

using namespace std;

int N,L;
int board[100][100];

pair<int,int> dir;

int move(int x, int y){
	int h = board[x][y];
	int length = 0;
	int set = 0;

	while(x < N && y < N){

		if(set && length >= L){
			set = 0;
			length = 0;
		}

		if(abs(h - board[x][y]) >= 2)
			return 0;

		if(h > board[x][y]){
			if(set)
				return 0;
	
			set = 1;
			length = 0;

		}else if(h < board[x][y]){
			if(set)
				return 0;

			if(length < L)
				return 0;

			length = 0;
		}
		
		h = board[x][y];
		++length;

		x += dir.first;
		y += dir.second;
	}

	if(set && length < L)
		return 0;

	return 1;
}

int solve(void){
	int sum = 0;

	dir = make_pair(0,1);

	for(int i = 0; i < N; ++i){
		sum += move(i,0);
	}

	dir = make_pair(1,0);

	for(int i = 0; i < N; ++i){
		sum += move(0,i);
	}

	return sum;
}

int main(void){
	cin >> N >> L;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}

	cout << solve() << endl;

	return 0;
}
