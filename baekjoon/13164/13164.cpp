#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int N,K;
	int temp;
	vector<int> list;

	cin >> N >> K;
	cin >> temp;
	for(int i = 1; i < N; ++i){
		int t;
		cin >> t;
		
		list.push_back(t-temp);
		temp = t;
	}

	sort(list.begin(), list.end());

	int ret = 0;

	for(int i = 0; i < N - K; ++i)
		ret += list[i];

	cout << ret << endl;

	return 0;
}
