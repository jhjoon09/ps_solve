#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Y,X;
int board[73][70];
int exit_pos[73][70];
int count;

int dx[] = {0 ,0 ,0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};

int dd[3][2] = {{1, -1}, {2, 0}, {1, 1}};
int dr[5][2] = {{-1, 1}, {0, 2}, {1, 1}, {2,1}, {1,2}};
int dl[5][2] = {{-1,-1}, {0,-2}, {1, -1}, {2, -1}, {1,-2}};


int isAvail(int y, int x){
	if(y < 0 || x < 0 || y >= Y+3 || x >= X)
		return 0;

	return 1;
}

int move_down(pair<int,int> pos){

	for(int i = 0; i < 3; ++i){
		int ny = pos.first + dd[i][0];
		int nx = pos.second + dd[i][1];

		if(isAvail(ny, nx) != 1)
			return 0;

		if(board[ny][nx] != 0)
			return 0;
	}

	return 1;
}

int move_left(pair<int,int> pos){
	for(int i = 0; i < 5; ++i){
		int ny = pos.first + dl[i][0];
		int nx = pos.second + dl[i][1];

		if(isAvail(ny,nx) != 1)
			return 0;

		if(board[ny][nx] != 0)
			return 0;
	}

	return 1;
}

int move_right(pair<int,int> pos){

	for(int i = 0; i < 5; ++i){
		int ny = pos.first + dr[i][0];
		int nx = pos.second + dr[i][1];

		if(isAvail(ny,nx) != 1)
			return 0;

		if(board[ny][nx] != 0)
			return 0;
	}

	return 1;
}

int get_out(pair<int,int> pos, int dir){
	if(pos.first-1 <= 2 || pos.second-1 < 0 || pos.second+1 >= X){
		return -1;
	}
	++count;
	int y = pos.first;
	int x = pos.second;
	int visit[73][70] = {0 ,};
	visit[y][x] = 1;
	queue<pair<pair<int,int>, int>> q;
	q.push({{y,x}, count});

	for(int i = 0; i < 5; ++i){
		board[y+dy[i]][x+dx[i]] = count;
	}

	int ret = y+1;

	switch(dir){
		//UP
		case 0:
			--y;
			break;
		case 1:
			//RIGHT
			++x;
			break;
		case 2:
			//DOWN
			++y;
			break;
		case 3:
			//LEFT
			--x;
			break;
	}

	exit_pos[y][x] = 1;

	while(!q.empty()){
		pair<int,int> pos = q.front().first;
		int num = q.front().second;
		q.pop();

		if(pos.first > ret)
			ret = pos.first;

		for(int i = 0; i < 5; ++i){
			int ny = pos.first + dy[i];
			int nx = pos.second + dx[i];

			if(isAvail(ny,nx) == 0)
				continue;

			if(board[ny][nx] == 0)
				continue;

			if(visit[ny][nx] != 0)
				continue;

			if(board[ny][nx] != num && exit_pos[pos.first][pos.second] == 0)
				continue;

			q.push({{ny,nx}, board[ny][nx]});
			visit[ny][nx] = 1;
		}
	}


	return ret-2;
}

int clear_board(void){
	count = 0;
	for(int y = 0; y < Y+3; ++y){
		for(int x = 0; x < X; ++x){
			board[y][x] = 0;
			exit_pos[y][x] = 0;
		}
	}

	return 0;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int ret = 0;
	int K;

	cin >> Y >> X;
	cin >> K;
	while(--K >= 0){
		int y,x, d;
		cin >> x >> d;
		--x;
		y = 1;
		while(true){
			if(move_down({y,x})){
				++y;
				continue;
			}

			if(move_left({y,x})){
				++y;
				--x;
				d = (d + 3) % 4;
				continue;
			}

			if(move_right({y,x})){
				++y;
				++x;
				d = (d + 1) % 4;
				continue;
			}

			break;
		}


		int t_ret = get_out({y,x}, d);

		if(t_ret > 0){
			ret += t_ret;
		}else{
			clear_board();
		}
	}

	cout << ret << endl;

	return 0;
}
