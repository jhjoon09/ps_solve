#include <iostream>
#include <vector>

using namespace std;

int R,C,M;
pair<pair<int,int>, int> board[100][100];

int move_shark(void){
	pair<pair<int,int>, int> t_board[100][100];

	for(int i = 0; i < C; ++i){
		for(int j = 0; j < R; ++j){
			if(board[j][i].second == 0)
				continue;
			int x = i;
			int y = j;
			int s = board[j][i].first.first;
			int d = board[j][i].first.second;
			int z = board[j][i].second;
			int count = s;

			while(count > 0){
				switch(d){
					case 1:
						if(y-count < 0){
							count -= y;
							y = 0;
							d = 2;
						}else{
							y -= count;
							count = 0;
						}
						break;
					case 2:
						if(y + count > R-1){
							count -= R-1 -y;
							y = R-1;
							d = 1;
						}else{
							y += count;
							count = 0;
						}
						break;
					case 3:
						if(x+count > C-1){
							count -= C-1 -x;
							x = C-1;
							d = 4;
						}else{
							x += count;
							count = 0;
						}
						break;
					case 4:
						if(x - count < 0){
							count -= x;
							x = 0;
							d = 3;
						}else{
							x -= count;
							count = 0;
						}
						break;
				}

			}

			if(t_board[y][x].second > z)
				continue;

			t_board[y][x] = make_pair(make_pair(s,d), z);
		}
	}

	for(int i = 0; i < C; ++i){
		for(int j = 0; j < R; ++j){
			board[j][i] = t_board[j][i];
		}
	}
	return 0;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C >> M;

	for(int i = 0; i < M; ++i){
		int r,c,s,d,z;
		cin >> r >> c >> s >> d >> z;

		--r;
		--c;
		board[r][c] = make_pair(make_pair(s,d),z); 
	}
	
	int ret = 0;

	for(int i = 0; i < C; ++i){
		for(int j = 0; j < R; ++j){
			if(board[j][i].second != 0){
				ret += board[j][i].second;
				board[j][i] = make_pair(make_pair(0,0), 0);

				break;
			}
		}
		move_shark();
	}

	cout << ret << endl;
}
