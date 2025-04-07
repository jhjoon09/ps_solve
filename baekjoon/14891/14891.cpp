#include <iostream>

using namespace std;

int state[4][8];
int pos[4];

int turn(void){
	int n,d;
	int turning[4] = {0, };
	cin >> n >> d;
	--n;
	turning[n] = d;

	for(int i = n+1; i < 4; ++i){
		int p1 = (pos[i-1] + 2)	% 8;
		int p2 = (pos[i] + 6) % 8;

		int e1 = state[i-1][p1];
		int e2 = state[i][p2];

		if(e1 == e2)
			break;
	
		turning[i] = (-1) * turning[i-1];
	}

	for(int i = n-1; i >= 0; --i){
		int p1 = (pos[i] + 2) % 8;
		int p2 = (pos[i+1] + 6) % 8;

		int e1 = state[i][p1];
		int e2 = state[i+1][p2];

		if(e1 == e2)
			break;

		turning[i] = (-1) * turning[i+1];
	}

	for(int i = 0; i < 4; ++i){
		pos[i] = (pos[i] - turning[i] + 8) % 8;
	}

	return 0;
}

int main(void){
	char temp[9];
	for(int i = 0; i < 4; ++i){
		cin >> temp;
		for(int j = 0; j < 8; ++j){
			state[i][j] = temp[j] - '0';
		}
	}

	int K;
	cin >> K;

	while(--K >= 0){
		turn();
	}

	int ret = 0;

	for(int i = 0; i < 4; ++i){
		ret += (1 << i) * state[i][pos[i]];
	}

	cout << ret << endl;

	return 0;
}
