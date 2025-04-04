#include <iostream>
#include <queue>

using namespace std;

int N;
int board[20][20];

int move(queue<int> dir){
	int t_board[20][20];
	queue<int> copy = dir;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			t_board[i][j] = board[i][j];
		}
	}

	while(!dir.empty()){
		int t = dir.front();
		dir.pop();

		switch(t){
			//right
			case 0:
				for(int i = 0; i < N; ++i){
					queue<int> lst;
					for(int j = N-1; j >= 0; --j){
						if(t_board[i][j] != 0)
							lst.push(t_board[i][j]);
					}
					int pos = N-1;
					int top = 0;
					if(!lst.empty()){
						top = lst.front();
						lst.pop();
					}

					while(!lst.empty()){
						int temp = lst.front();
						lst.pop();
						if(temp == top){
							top *= 2;
							if(lst.empty())
								break;

							t_board[i][pos] = top;
							--pos;
							top = lst.front();
							lst.pop();
						}else{
							t_board[i][pos] = top;
							top = temp;
							--pos;
						}
					}
					t_board[i][pos] = top;
					for(int j = pos-1; j >= 0; --j){
						t_board[i][j] = 0;
					}
				}
				break;
				//left
			case 1:
				for(int i = 0; i < N; ++i){
					queue<int> lst;
					for(int j = 0; j < N; ++j){
						if(t_board[i][j] != 0)
							lst.push(t_board[i][j]);
					}

					int pos = 0;
					int top = 0;
					if(!lst.empty()){
						top = lst.front();
						lst.pop();
					}
					while(!lst.empty()){
						int temp = lst.front();
						lst.pop();
						if(temp == top){
							top *= 2;
							if(lst.empty())
								break;

							t_board[i][pos] = top;
							++pos;
							top = lst.front();
							lst.pop();
						}else{
							t_board[i][pos] = top;
							top = temp;
							++pos;
						}
					}
					t_board[i][pos] = top;
					for(int j = pos+1; j < N; ++j)
						t_board[i][j] = 0;
				}
				break;
				//up
			case 2:
				for(int i = 0; i < N; ++i){
					queue<int> lst;
					for(int j = 0; j < N; ++j){
						if(t_board[j][i] != 0)
							lst.push(t_board[j][i]);
					}
					int pos = 0;
					int top = 0;
					if(!lst.empty()){
						top = lst.front();
						lst.pop();
					}
					while(!lst.empty()){
						int temp = lst.front();
						lst.pop();
						if(temp == top){
							top *= 2;

							if(lst.empty())
								break;

							t_board[pos][i] = top;
							++pos;
							top = lst.front();
							lst.pop();
						}else{
							t_board[pos][i] = top;
							top = temp;
							++pos;
						}
					}
					t_board[pos][i] = top;
					for(int j = pos+1; j < N; ++j)
						t_board[j][i] = 0;
				}
				break;
				//down
			case 3:
				for(int i = 0; i < N; ++i){
					queue<int> lst;

					for(int j = N-1; j >= 0; --j){
						if(t_board[j][i] != 0)
							lst.push(t_board[j][i]);
					}
					int pos = N-1;
					int top = 0;
					if(!lst.empty()){
						top = lst.front();
						lst.pop();
					}
					while(!lst.empty()){
						int temp = lst.front();
						lst.pop();
						if(temp == top){
							top *= 2;

							if(lst.empty())
								break;

							t_board[pos][i] = top;
							--pos;
							top = lst.front();
							lst.pop();
						}else{
							t_board[pos][i] = top;
							top = temp;
							--pos;
						}

					}
					t_board[pos][i] = top;
					for(int j = pos-1; j >= 0; --j)
						t_board[j][i] = 0;
				}
				break;
		}
	}
	int max = -1;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			max = max > t_board[i][j] ? max : t_board[i][j];
		}
	}

	return max;
}

int solve(queue<int> q){
	if(q.size() == 5)
		return move(q);

	int max = -1;

	for(int i = 0; i < 4; ++i){
		queue<int> n_q = q;
		n_q.push(i);
		int t = solve(n_q);
		max = t > max ? t : max;
	}

	return max;
}

int main(void){
	cin >> N;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}

	queue<int> q;
	cout << solve(q) << endl;

	return 0;
}
