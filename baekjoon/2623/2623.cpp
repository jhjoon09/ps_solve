#include <iostream>
#include <queue>

using namespace std;

int N,M;
int count[1001];
vector<int> lst[1001];

int main(void){
	vector<int> ret;
	queue<int> q;

	cin >> N >> M;

	for(int i = 0; i < M; ++i){
		int c;
		vector<int> t_lst;
		cin >> c;

		for(int j = 0; j < c; ++j){
			int temp;
			cin >> temp;

			t_lst.push_back(temp);
		}

		for(int j = 0; j < t_lst.size(); ++j){
			for(int k = j+1; k < t_lst.size(); ++k){
				lst[t_lst[j]].push_back(t_lst[k]);
				++count[t_lst[k]];	
			}
		}
	}

	for(int i = 1;i <= N; ++i){
		if(count[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int n = q.front();
		q.pop();
		ret.push_back(n);

		for(int i = 0; i < lst[n].size(); ++i){
			--count[lst[n][i]];

			if(count[lst[n][i]] == 0)
				q.push(lst[n][i]);
		}
	}

	if(ret.size() != N){
		cout << 0 << endl;
	}else{
		for(int i = 0; i < ret.size(); ++i)
			cout << ret[i] << endl;
	}

	return 0;
}
