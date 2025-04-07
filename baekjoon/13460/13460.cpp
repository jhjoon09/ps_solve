#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N,M;
char board[10][11];

struct Pos{
	pair<int,int> red;
	pair<int,int> blue;

	bool operator < (const Pos &var) const{
		if(red == var.red)
			return blue < var.blue;

		return red < var.red;
	}
};

int go_right(Pos start, Pos* end){
	int flag = 0;
	
	int rx = start.red.second;
	int ry = start.red.first;
	
	int bx = start.blue.second;
	int by = start.blue.first;

	if(rx > bx){
		while(board[ry][rx+1] == '.'){
			++rx;
		}

		if(board[ry][rx+1] == 'O'){
			ry = -1;
			rx = -1;
			flag = 1;
		}

		while(board[by][bx+1] == '.'){
			if(by == ry && (bx+1) == rx)
				break;

			++bx;
		}
		
		if(board[by][bx+1] == 'O'){
			return -1;
		}

	}else{
		while(board[by][bx+1] == '.'){
			++bx;
		}

		if(board[by][bx+1] == 'O'){
			return -1;
		}

		while(board[ry][rx+1] == '.'){
			if(ry == by && (rx+1) == bx)
				break;

			++rx;
		}

		if(board[ry][rx+1] == 'O'){
			flag = 1;
		}
	}

	end->red = make_pair(ry,rx);
	end->blue = make_pair(by,bx);

	return flag;
}


int go_left(Pos start, Pos* end){
	int flag = 0;
	
	int rx = start.red.second;
	int ry = start.red.first;
	
	int bx = start.blue.second;
	int by = start.blue.first;

	if(rx < bx){

		while(board[ry][rx-1] == '.'){
			--rx;
		}

		if(board[ry][rx-1] == 'O'){
			rx = -1;
			ry = -1;
			flag = 1;
		}

		while(board[by][bx-1] == '.'){
			if(by == ry && (bx-1) == rx)
				break;
			
			--bx;
		}
		
		if(board[by][bx-1] == 'O'){
			return -1;
		}

	}else{
		while(board[by][bx-1] == '.'){
			--bx;
		}

		if(board[by][bx-1] == 'O'){
			return -1;
		}

		while(board[ry][rx-1] == '.'){
			if(ry == by && (rx-1) == bx)
				break;

			--rx;
		}

		if(board[ry][rx-1] == 'O'){
			flag = 1;
		}
	}

	end->red = make_pair(ry,rx);
	end->blue = make_pair(by,bx);

	return flag;
}


int go_up(Pos start, Pos* end){
	int flag = 0;
	
	int rx = start.red.second;
	int ry = start.red.first;
	
	int bx = start.blue.second;
	int by = start.blue.first;

	if(ry < by){
		while(board[ry-1][rx] == '.'){
			--ry;
		}

		if(board[ry-1][rx] == 'O'){
			rx = -1;
			ry = -1;
			flag = 1;
		}

		while(board[by-1][bx] == '.'){
			if((by-1) == ry && bx == rx)
				break;

			--by;
		}
		
		if(board[by-1][bx] == 'O'){
			return -1;
		}

	}else{
		while(board[by-1][bx] == '.'){
			--by;
		}

		if(board[by-1][bx] == 'O'){
			return -1;
		}

		while(board[ry-1][rx] == '.'){
			if((ry-1) == by && rx == bx)
				break;

			--ry;
		}

		if(board[ry-1][rx] == 'O'){
			flag = 1;
		}
	}

	end->red = make_pair(ry,rx);
	end->blue = make_pair(by,bx);

	return flag;
}

int go_down(Pos start, Pos* end){
	int flag = 0;
	
	int rx = start.red.second;
	int ry = start.red.first;
	
	int bx = start.blue.second;
	int by = start.blue.first;

	if(ry > by){
		while(board[ry+1][rx] == '.'){
			++ry;
		}

		if(board[ry+1][rx] == 'O'){
			rx = -1;
			ry = -1;
			flag = 1;
		}

		while(board[by+1][bx] == '.'){
			if((by+1) == ry && bx == rx)
				break;

			++by;
		}
		
		if(board[by+1][bx] == 'O'){
			return -1;
		}

	}else{
		while(board[by+1][bx] == '.'){
			++by;
		}

		if(board[by+1][bx] == 'O'){
			return -1;
		}

		while(board[ry+1][rx] == '.'){
			if((ry+1) == by && rx == bx)
				break;

			++ry;
		}

		if(board[ry+1][rx] == 'O'){
			flag = 1;
		}
	}

	end->red = make_pair(ry,rx);
	end->blue = make_pair(by,bx);

	return flag;
}

int move(Pos start, int dir, Pos* end){
	int ret;
	switch(dir){
		case 0:
			ret = go_right(start, end);
			break;
		case 1:
			ret = go_left(start, end);
			break;
		case 2:
			ret = go_up(start, end);
			break;
		case 3:
			ret = go_down(start, end);
			break;
	}

	return ret;
}

int solve(void){
	queue<Pos> q;
	queue<Pos> nq;
	set<Pos> visited;
	Pos s;
	int count = 1;

	for(int y = 0; y < N; ++y){
		for(int x = 0; x < M; ++x){
			if(board[y][x] == 'R'){
				s.red = make_pair(y,x);
				board[y][x] = '.';
			}else if(board[y][x] == 'B'){
				s.blue = make_pair(y,x);
				board[y][x] = '.';
			}
		}
	}
	visited.insert(s);
	q.push(s);

	while(count <= 10 && !q.empty()){

		while(!q.empty()){
			Pos start = q.front();
			q.pop();
			for(int i = 0; i < 4; ++i){
				Pos end;
				int ret = move(start, i, &end);
				if(ret == 1)
					return count;
				else if(ret == -1)
					continue;

				if(visited.find(end) != visited.end())
					continue;
				
				visited.insert(end);
				nq.push(end);
			}
		}

		swap(q, nq);
		++count;
	}

	return -1;
}

int main(void){
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		cin >> board[i];
	}
	
	int ret = solve();

	cout << ret << endl;

	return 0;
}
