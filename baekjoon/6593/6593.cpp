#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int L,R,C;
char Building[31][31][31];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int solve(void){
	queue<pair<tuple<int,int,int>, int>> q;
	
	for(int i = 0; i < L; ++i){
		for(int j = 0; j < R; ++j){
			for(int k = 0; k < C; ++k){
				if(Building[i][j][k] == 'S'){
					q.push(make_pair(make_tuple(i,j,k),0));
				}
			}
		}
	}

	while(!q.empty()){
		int l = get<0>(q.front().first);
		int r = get<1>(q.front().first);
		int c = get<2>(q.front().first);
		int count = q.front().second;
		q.pop();

		if(l < 0 || l >= L || r < 0 || r >= R || c < 0 || c >= C)
			continue;

		if(Building[l][r][c] == 'E')
			return count;

		if(Building[l][r][c] == '#')
			continue;

		Building[l][r][c] = '#';

		for(int i = 0; i < 6; ++i)
			q.push(make_pair(make_tuple(l + dx[i], r + dy[i], c + dz[i]), count+1));

	}

	return -1;
}

int main(void){
	char temp;
	while(true){
		cin >> L >> R >> C;

		if(!(L || R || C))
			break;

		for(int i = 0; i < L; ++i){
			for(int j = 0; j < R; ++j){
				for(int k = 0; k < C; ++k){
					cin >> Building[i][j][k];
				}
			}
		}	

		int ret = solve();

		if(ret == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in "<< ret <<" minute(s)." << endl;
	}

	return 0;
}
