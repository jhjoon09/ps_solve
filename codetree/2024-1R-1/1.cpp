#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int Board[5][5];
queue<int> q;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int bfs(int board[5][5]){
	int ret = 0;
	int visit[5][5] = {0, };

	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(visit[i][j] != 0)
				continue;
			vector<pair<int,int>> node;
			int num =  board[i][j];
			visit[i][j] = 1;

			node.push_back({i,j});

			for(int a = 0; a < node.size(); ++a){
				pair<int,int> pos = node[a];

				for(int k = 0; k < 4; ++k){
					int ny = pos.first + dy[k];
					int nx = pos.second + dx[k];

					if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
						continue;

					if(visit[ny][nx] != 0 || board[ny][nx] != num)
						continue;
	
					visit[ny][nx] = 1;

					node.push_back({ny,nx});
				}
			}

			if(node.size() >= 3){
				ret += node.size();
	
				for(int a = 0; a < node.size(); ++a){
					board[node[a].first][node[a].second] = 0;
				}
			}
		}
	}

	return ret;
}

int turn_right(int board[3][3]){
	int temp[3][3];

	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			temp[i][j] = board[2-j][i];
		}
	}

	copy(&temp[0][0], &temp[0][0] + 9, &board[0][0]);

	return 0;
}

int turn_board(int board[5][5], pair<int,int> p, int d){
	int temp[3][3];


	for(int i = -1; i <= 1; ++i){
		for(int j = -1; j <= 1; ++j){
			temp[i+1][j+1] = board[p.first + i][p.second + j];
		}
	}

	while(d-- >= 0){
		turn_right(temp);
	}

	for(int i = -1; i <= 1; ++i){
		for(int j = -1; j <= 1; ++j){
			board[p.first + i][p.second +j] = temp[i+1][j+1];
		}
	}

	return bfs(board);
}

int get_treasure(void){
	
	for(int j = 0; j < 5; ++j){
		for(int i = 4; i >= 0; --i){
			if(Board[i][j] == 0){
				Board[i][j] = q.front();
				q.pop();
			}
		}
	}

	return bfs(Board);
}

pair<pair<int,int>, int> cal_turn(void){
	pair<pair<int,int>, int> ret;
	int t_board[5][5];
	int max = 0;

	for(int d = 0; d < 3; ++d){
		for(int i = 1; i < 4; ++i){
			for(int j = 1; j < 4; ++j){
				copy(&Board[0][0], &Board[0][0]+25, &t_board[0][0]);
				int temp = turn_board(t_board, {j,i}, d);

				if(temp > max){
					max = temp;
					ret = {{j,i}, d};
				}
			}
		}
	}

	return ret;
}

int main(void){
	int K,M;

	cin >> K >> M;

	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			cin >> Board[i][j];
		}
	}
	
	for(int i = 0; i < M; ++i){
		int t;
		cin >> t;
		q.push(t);
	}

	while(--K >= 0){
		pair<pair<int,int>, int> max_data = cal_turn();

		int ret = turn_board(Board, max_data.first, max_data.second);

		if(ret == 0)
			break;

		int plus = 0;
		
		do{
			plus = get_treasure();
			ret += plus;
		}while(plus != 0);

		cout << ret << " ";
	}

	cout << endl;

	return 0;
}
