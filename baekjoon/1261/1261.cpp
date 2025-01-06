#include <iostream>
#include <queue>

#define MAX 100
#define INF 1234567890

using namespace std;

int W,H;
int board[MAX][MAX];
int count[MAX][MAX];

void move(queue<pair<int,int>>* queue, int x, int y){
	queue->push(make_pair(x-1,y));
	queue->push(make_pair(x+1,y));
	queue->push(make_pair(x,y-1));
	queue->push(make_pair(x,y+1));
}

int solve(void){
	int ret = 0;
	queue<pair<int,int>> now;
	queue<pair<int,int>> next;

	now.push(make_pair(0,0));

	while(true){
		if(now.empty()){
			++ret;
			swap(now,next);
		}

		pair<int,int> temp = now.front();
		now.pop();
		int x = temp.first;
		int y = temp.second;

		if(x < 0 || y < 0 || x >= W || y >= H)
			continue;

		if(count[y][x] <= ret)
			continue;

		count[y][x] = ret;

		if(x == W-1 && y == H-1)
			return ret;

		if(board[y][x] == 0){
			move(&now, x, y);
		}else{
			move(&next, x, y);
		}
	}

	return INF;
}

int main(void){
	char temp;

	cin >> W >> H;
	
	for(int y = 0; y < H; ++y){
		for(int x = 0; x < W; ++x){
			cin >> temp;

			board[y][x] = temp == '0' ? 0 : 1;
			count[y][x] = INF;
		}
	}

	cout << solve() << endl;	

	return 0;
}

