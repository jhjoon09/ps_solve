#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;
int soil[10][10];
int refill[10][10];
int dead[10][10];
vector<int> q[10][10];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(void){
	cin >> N >> M >> K;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> refill[i][j];
			soil[i][j] = 5;
		}
	}

	for(int i = 0; i < M; ++i){
		int a,b,c;
		cin >> a >> b >> c;

		q[a-1][b-1].push_back(c);
	}

	while(--K >= 0){
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				vector<int> temp;
				int sum = 0;
				sort(q[i][j].begin(), q[i][j].end());

				for(int k = 0; k < q[i][j].size(); ++k){
					int t = q[i][j][k];
					if(soil[i][j] >= t){
						soil[i][j] -= t;
						temp.push_back(t+1);

						if((t+1) % 5 == 0)
							++dead[i][j];

					}else{
						sum += (t/2);
					}
				}

				soil[i][j] += sum;
				q[i][j].clear();

				for(int k = 0; k < temp.size(); ++k)
					q[i][j].push_back(temp[k]);
			}
		}

		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				for(int k = 0; k < 8; ++k){
					int x = i + dx[k];
					int y = j + dy[k];

					if(x < 0 || y < 0 || x >= N || y >= N)
						continue;

					for(int l = 0; l < dead[i][j]; ++l){
						q[x][y].push_back(1);
					}
				}

				dead[i][j] = 0;	
			}
		}

		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				soil[i][j] += refill[i][j];
			}
		}
	}

	int ret = 0;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			ret += q[i][j].size();
		}
	}

	cout << ret << endl;

	return 0;
}
