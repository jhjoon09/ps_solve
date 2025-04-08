#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
int sx,sy,ex,ey;
queue<pair<int,int>> war;
int board[50][50];

pair<int,int> snakePos;

//left right up down
int dw[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
//up down left right
int ds[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int onSight[50][50];

queue<pair<int,int>> stone;

int input(void);
vector<pair<int,int>> makeRoute(void);
int lookAt(void);
int makeStone(int);
int resetWarrior(void);

int isAvail(pair<int,int>);
int getDist(pair<int,int>);

pair<int,int> makeMove(pair<int,int>,int);
int moveWarrior(int);

int removeWarrior(void);

int main(void){
	input();
	vector<pair<int,int>> lst = makeRoute();
	if(lst.size() == 0){
		cout << "-1\n";
		return 0;
	}
	

	for(int i = 1; i < lst.size()-1; ++i){
		snakePos = lst[i];
		removeWarrior();
		int stoneCount = lookAt();
		int moveCount = moveWarrior(0);
		moveCount += moveWarrior(1);
		int attackCount = removeWarrior();
		
		cout << moveCount << " " << stoneCount << " " << attackCount << "\n";
	}

	cout << "0\n";

	return 0;
}

int input(void){
	cin >> N >> M;
	cin >> sy >> sx >> ey >> ex;

	for(int i = 0; i < M; ++i){
		int x,y;
		cin >> y >> x;
		war.push(make_pair(y,x));
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}

	return 0;
}

vector<pair<int,int>> makeRoute(void){
	vector<pair<int,int>> lst;
	vector<int> trace;

	lst.push_back(make_pair(sy,sx));
	trace.push_back(-1);
	board[sy][sx] = 1;
	for(int i = 0; i < lst.size(); ++i){
		int y = lst[i].first;
		int x = lst[i].second;
		int count = board[y][x];

		for(int j = 0; j < 4; ++j){
			int ny = y + ds[j][0];
			int nx = x + ds[j][1];

			if(!isAvail(make_pair(ny,nx)))
				continue;

			if(board[ny][nx] != 0)
				continue;

			board[ny][nx] = count+1;
			lst.push_back(make_pair(ny,nx));
			trace.push_back(i);

			if(ny == ey && nx == ex){
				break;
			}
		}

		if(lst.back().first == ey && lst.back().second == ex)
			break;
	}

	vector<pair<int,int>> ret;

	if(lst.back().first != ey || lst.back().second != ex)
		return ret;

	int pos = lst.size() -1;
	while(pos != -1){
		ret.push_back(lst[pos]);
		pos = trace[pos];
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int isAvail(pair<int,int> pos){
	if(pos.first < 0 || pos.second < 0 || pos.first >= N || pos.second >= N)
		return 0;

	return 1;
}

int getDist(pair<int,int> p1, pair<int,int> p2){
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int lookAt(void){
	int max = -1;
	int dir;
	for(int i = 0; i < 4; ++i){
		int temp = makeStone(i);

		if(max < temp){
			max = temp;
			dir = i;
		}
	}

	return makeStone(dir);
}

int makeStone(int dir){
	int count = 0;
	int warBoard[50][50];
	resetWarrior();

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			onSight[i][j] = 0;
			warBoard[i][j] = 0;
		}
	}

	while(!war.empty()){
		pair<int,int> pos = war.front();
		war.pop();

		warBoard[pos.first][pos.second]++;
	}
	
	pair<int,int> dxy[3];

	switch(dir){
	//UP
		case 0:
			dxy[1] = make_pair(-1, 0);
			dxy[0] = make_pair(-1,-1);
			dxy[2] = make_pair(-1,1);
			break;
	//DOWN
		case 1:
			dxy[1] = make_pair(1, 0);
			dxy[0] = make_pair(1, -1);
			dxy[2] = make_pair(1, 1);
			break;
	//LEFT
		case 2:
			dxy[1] = make_pair(0, -1);
			dxy[0] = make_pair(1, -1);
			dxy[2] = make_pair(-1, -1);
			break;
	//RIGHT
		case 3:
			dxy[1] = make_pair(0, 1);
			dxy[0] = make_pair(1, 1);
			dxy[2] = make_pair(-1, 1);
			break;
	}

	queue<pair<int,int>> bfs;
	queue<pair<int,int>> stonePos;
	pair<int,int> p0 = snakePos;
	while(isAvail(p0)){
		onSight[p0.first][p0.second] = 1;
		if(warBoard[p0.first][p0.second] != 0){
			break;
		}

		p0 = make_pair(p0.first + dxy[1].first, p0.second + dxy[1].second);
	}

	pair<int,int> p1 = make_pair(snakePos.first + dxy[0].first, snakePos.second + dxy[0].second);
	if(isAvail(p1)){
		bfs.push(p1);
		onSight[p1.first][p1.second] = 1;
	}

	while(!bfs.empty()){
		pair<int,int> t = bfs.front();
		bfs.pop();

		if(warBoard[t.first][t.second] != 0){
			for(int i = 0; i <= 1; ++i){
				pair<int,int> tPos = make_pair(t.first + dxy[i].first, t.second + dxy[i].second);
				
				if(!isAvail(tPos))
					continue;

				stonePos.push(tPos);
			}
			continue;
		}
		for(int i = 0; i <= 1; ++i){
			pair<int,int> nPos = make_pair(t.first + dxy[i].first, t.second + dxy[i].second);
			
			if(!isAvail(nPos))
				continue;

			if(onSight[nPos.first][nPos.second] != 0)
				continue;

			onSight[nPos.first][nPos.second] = 1;

			bfs.push(nPos);
		}
	}

	while(!stonePos.empty()){
		pair<int,int> t = stonePos.front();
		onSight[t.first][t.second] = 0;
		stonePos.pop();

		for(int i = 0; i <= 1; ++i){
			pair<int,int> nPos = make_pair(t.first + dxy[i].first, t.second +dxy[i].second);

			if(!isAvail(nPos))
				continue;

			if(onSight[nPos.first][nPos.second] == 0)
				continue;

			onSight[nPos.first][nPos.second] = 0;

			stonePos.push(nPos);

		}
	}

	pair<int,int> p2 = make_pair(snakePos.first + dxy[2].first, snakePos.second + dxy[2].second);
	if(isAvail(p2)){
		bfs.push(p2);
		onSight[p2.first][p2.second] = 1;
	}

	while(!bfs.empty()){
		pair<int,int> t = bfs.front();
		bfs.pop();

		if(warBoard[t.first][t.second] != 0){
			for(int i = 1; i<=2; ++i){
				pair<int,int> tPos = make_pair(t.first + dxy[i].first, t.second + dxy[i].second);

				if(!isAvail(tPos))
					continue;

				stonePos.push(tPos);
			}
			continue;
		}

		for(int i = 1; i <= 2; ++i){
			pair<int,int> nPos = make_pair(t.first + dxy[i].first, t.second + dxy[i].second);
			
			if(!isAvail(nPos))
				continue;

			if(onSight[nPos.first][nPos.second] != 0)
				continue;

			onSight[nPos.first][nPos.second] = 1;

			bfs.push(nPos);
		}
	}

	while(!stonePos.empty()){
		pair<int,int> t = stonePos.front();
		onSight[t.first][t.second]= 0;
		stonePos.pop();

		for(int i = 1; i <= 2; ++i){
			pair<int,int> nPos = make_pair(t.first + dxy[i].first, t.second + dxy[i].second);

			if(!isAvail(nPos))
				continue;

			if(onSight[nPos.first][nPos.second] == 0)
				continue;

			onSight[nPos.first][nPos.second] = 0;

			stonePos.push(nPos);

		}
	}

	onSight[snakePos.first][snakePos.second] = 0;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(warBoard[i][j] == 0)
				continue;

			if(onSight[i][j] == 1){
				for(int k = 0; k < warBoard[i][j]; ++k){
					stone.push(make_pair(i,j));
					++count;
				}
			}else{
				for(int k = 0; k < warBoard[i][j]; ++k){
					war.push(make_pair(i,j));
				}
			}
		}
	}

	return count;
}

int resetWarrior(void){
	while(!stone.empty()){
		war.push(stone.front());
		stone.pop();
	}

	return 0;
}

pair<int,int> makeMove(pair<int,int> warPos, int n){
	int min = getDist(warPos, snakePos);
	if(n == 1){
		for(int i = 0; i < 4; ++i){
			pair<int,int> tempPos = make_pair(warPos.first + dw[i][0], warPos.second + dw[i][1]);

			if(!isAvail(tempPos))
				continue;

			if(onSight[tempPos.first][tempPos.second] != 0)
				continue;

			int temp = getDist(tempPos, snakePos);

			if(temp < min)
				return tempPos;
		}}else{
			for(int i = 3; i >= 0; --i){

				pair<int,int> tempPos = make_pair(warPos.first + dw[i][0], warPos.second + dw[i][1]);

				if(!isAvail(tempPos))
					continue;

				if(onSight[tempPos.first][tempPos.second] != 0)
					continue;

				int temp = getDist(tempPos, snakePos);

				if(temp < min)
					return tempPos;

			}
		}

	return warPos;
}

int moveWarrior(int n){
	int count = 0;
	queue<pair<int,int>> tempQ;

	while(!war.empty()){
		pair<int,int> warPos = war.front();
		war.pop();

		pair<int,int> moveRet = makeMove(warPos, n);
		if(warPos == moveRet){
			stone.push(warPos);
		}else{
			++count;
			tempQ.push(moveRet);
		}
	}

	swap(tempQ, war);

	return count;
}

int removeWarrior(void){
	int count = 0;
	resetWarrior();

	queue<pair<int,int>> tempQ;

	while(!war.empty()){
		pair<int,int> warPos = war.front();
		war.pop();

		if(warPos == snakePos){
			++count;
			continue;
		}

		tempQ.push(warPos);
	}

	swap(tempQ, war);

	return count;
}
