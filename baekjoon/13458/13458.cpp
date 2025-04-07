#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> lst;
int B,C;

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for(int i = 0; i < N; ++i){
		int t;
		cin >> t;
		lst.push_back(t);
	}
	cin >> B >> C;

	long long ret = N;

	for(int i = 0; i < N; ++i){
		int t = lst[i] - B;

		if(t < 0)
			continue;

		ret += t / C;
		if(t % C != 0)
			++ret;
	}

	cout << ret << endl;

	return 0;
}
