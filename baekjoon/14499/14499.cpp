#include <iostream>

enum FACE{
	UP,
	FT,
	RT,
	LT,
	DN,
	BK
};

using namespace std;

int N,M;
int board[20][20];
int dice[6]; //up, front, right, left, down, back
int X,Y;

int roll(int dir){
	int temp;
	//east, west, north, south
	switch(dir){
		case 1:
			temp = dice[UP];
			dice[UP] = dice[RT];
			dice[RT] = dice[DN];
			dice[DN] = dice[LT];
			dice[LT] = temp;
			break;
		case 2:
			temp = dice[UP];
			dice[UP] = dice[LT];
			dice[LT] = dice[DN];
			dice[DN] = dice[RT];
			dice[RT] = temp;

			break;
		case 3:
			temp = dice[UP];
			dice[UP] = dice[BK];
			dice[BK] = dice[DN];
			dice[DN] = dice[FT];
			dice[FT] = temp;
			break;
		case 4:
			temp = dice[UP];
			dice[UP] = dice[FT];
			dice[FT] = dice[DN];
			dice[DN] = dice[BK];
			dice[BK] = temp;
			break;
	}

	if(board[X][Y] == 0)
		board[X][Y] = dice[DN];
	else{
		dice[DN] = board[X][Y];
		board[X][Y] = 0;
	}

	return dice[UP];
}

int move(void){
	int dir;
	cin >> dir;

	switch(dir){
		case 1:
			if(Y >= M-1)
				return -1;

			++Y;
			break;

		case 2:
			if(Y <= 0)
				return -1;
			--Y;
			break;
		case 3:
			if(X <= 0)
				return -1;

			--X;
			break;
		case 4:
			if(X >= N-1)
				return -1;
			++X;
			break;
	}

	return roll(dir);
}

int main(void){

	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> N >> M >> X >> Y >> K;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j)
			cin >> board[i][j];
	}

	while(--K >= 0){
		int temp = move();

		if(temp != -1)
			cout << temp << endl;
	}

	return 0;
}

