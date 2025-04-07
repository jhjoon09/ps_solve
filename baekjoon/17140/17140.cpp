#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R,C,K;
int x,y;
int board[101][101];

int cal_r(void){
	int max_x = 0;

	for(int Y = 0; Y < y; ++Y){
		int count[100] = {0, };

		for(int i = 0; i < x; ++i){
			count[board[Y][i] -1]++;
		}

		vector<pair<int,int>> lst;

		for(int i = 0; i < 100; ++i){
			if(count[i] == 0)
				continue;

			lst.push_back(make_pair(count[i], i+1));
		}

		sort(lst.begin(), lst.end());
		for(int i = 0; i < lst.size(); i++){
			if(i >= 50)
				break;

			board[Y][i*2] = lst[i].second;
			board[Y][i*2 + 1] = lst[i].first;
		}

		for(int i = lst.size() * 2; i < x; ++i)
			board[Y][i] = 0;

		max_x = max_x > lst.size() * 2 ? max_x : lst.size() * 2;
		
		max_x = max_x > 100 ? 100 : max_x;
	}

	x = max_x;

	return 0;
}

int cal_c(void){
	int max_y = 0;

	for(int X = 0; X < x; ++X){
		int count[100] = {0, };

		for(int i = 0; i < y; ++i)
			count[board[i][X] -1]++;

		vector<pair<int,int>> lst;

		for(int i = 0; i < 100; ++i){
			if(count[i] == 0)
				continue;

			lst.push_back(make_pair(count[i], i+1));
		}

		sort(lst.begin(), lst.end());

		for(int i = 0; i < lst.size(); ++i){
			if(i >= 50)
				break;

			board[i*2][X] = lst[i].second;
			board[i*2 + 1][X] = lst[i].first;
		}

		for(int i = lst.size() * 2; i < y; ++i)
			board[i][X] = 0;

		max_y = max_y > lst.size() * 2 ? max_y : lst.size() * 2;
		max_y = max_y > 100 ? 100 : max_y;
	}

	y = max_y;

	return 0;
}

int main(void){
	int time = 0;
	x = 3;
	y = 3;
	cin >> R  >> C >> K;
	--R;
	--C;

	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> board[i][j];
		}
	}

	while(time <= 100 && board[R][C] != K){
		++time;
		if(y >= x)
			cal_r();
		else
			cal_c();
	}

	if(time > 100)
		time = -1;
	
	cout << time << endl;

	return 0;
}
