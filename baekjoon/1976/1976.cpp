#include <iostream>

using namespace std;

int N,M;

int board[200][200];
int city[200];

int color(int pos, int c){
	if(city[pos] == c)
		return 0;

	city[pos] = c;

	for(int i = 0; i < N; ++i){
		if(board[pos][i] == 1 && city[i]  == 0)
			color(i,c);
	}

	return 0;
}

int connect(void){
	int num = 0;

	for(int i = 0; i < N; ++i){
		if(city[i] == 0)
			color(i,++num);
	}

	return 0;
}

int main(void){
	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cin >> board[i][j];
	}
	
	connect();
	
	int pos;
	int flag = 1;
	cin >> pos;
	--pos;

	for(int i = 1; i < M; ++i){
		int temp;
		cin >> temp;
		--temp;

		if(city[pos] != city[temp]){
			flag = 0;
		}
	}

	cout << (flag == 1 ? "YES\n" : "NO\n");

	return 0;
}
