#include <iostream>
#include <queue>

using namespace std;

int N,M;
vector<int> lst[32001];
int count[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
	vector<int> ret;

	cin >> N >> M;

	for(int i = 0; i < M; ++i){
		int a,b;
		cin >> a >> b;
		
		lst[a].push_back(b);
		++count[b];
	}

	for(int i = 1; i <= N; ++i){
		if(count[i] == 0)
			pq.push(i);
	}

	
	while(!pq.empty()){
		int pos = pq.top();
		pq.pop();
		ret.push_back(pos);

		for(int i = 0; i < lst[pos].size(); ++i){
			--count[lst[pos][i]];

			if(count[lst[pos][i]] == 0)
				pq.push(lst[pos][i]);
		}
	}

	for(int i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";

	cout << endl;

	return 0;
}
