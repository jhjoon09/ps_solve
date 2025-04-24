#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MIN -100'000'000
#define MAX 100'000'000

#define endl '\n'

using namespace std;

int N;
int D;
vector<pair<int,int>> lst;
priority_queue<int,vector<int>, greater<int>> pq;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second)
		return a.first > b.first;

	return a.second < b.second;
}


int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	lst.resize(N);

	for(int i = 0; i < N; ++i){
		int a,b;
		cin >> a >> b;

		lst[i] = {min(a,b), max(a,b)};
	}

	cin >> D;

	sort(lst.begin(), lst.end(), cmp);

	int pos = MIN;
	int ret = 0;

	for(auto iter = lst.begin(); iter != lst.end(); ++iter){
		pq.push(iter->first);

		pos = iter->second - D;

		while(!pq.empty()){
			if(pq.top() >= pos)
				break;

			pq.pop();
		}

		int count = pq.size();

		ret = ret > count ? ret : count;
	}

	cout << ret << endl;


	return 0;
}
