#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int lst[501];
int graph[501][501];
int M;

vector<int> cal_rank(void){
	queue<int> wait[501];
	vector<int> ret;
	int visit[501] = {0, };
	int flag = 1;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(graph[i][j] == 0)
				continue;
			wait[i].push(j);
		}
	}

	while(flag && ret.size() < N){
		int next = -1;

		for(int i = 0; i < N; ++i){
			if(visit[i] == 1)
				continue;

			while(!wait[i].empty()){
				int t = wait[i].front();
				
				if(visit[t] == 0)
					break;

				wait[i].pop();
			}

			if(!wait[i].empty())
				continue;

			if(next != -1){
				flag = 0;
				break;
			}

			next = i;
		}
		if(next == -1){
			break;
		}

		ret.push_back(next);
		visit[next] = 1;
	}

	return ret;
}

int input(void){
	cin >> N;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			graph[i][j] = 0;
		}
	}
	for(int i = 0; i < N; ++i){
		cin >> lst[i];
		--lst[i];

		for(int j = 0; j < i; ++j){
			graph[lst[i]][lst[j]] = 1;
		}
	}

	cin >> M;

	for(int i = 0; i < M; ++i){
		int a,b;
		cin >> a >> b;
		--a;
		--b;

		int temp = graph[a][b];
		graph[a][b] = graph[b][a];
		graph[b][a] = temp;
	}

	return 0;
}

int solve(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	vector<int> ret = cal_rank();

	if(ret.size() < N)
		cout << "IMPOSSIBLE\n";
	else{
		for(vector<int>::iterator iter = ret.begin(); iter != ret.end(); ++iter){
			cout << (*iter)+1 << " ";
		}
		cout << endl;
	}

	return 0;
}

int main(void){
	int T;
	cin >> T;

	while(--T >= 0){
		solve();
	}

	return 0;
}
