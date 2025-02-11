#include <iostream>

using namespace std;

int N,M;
int count[1001];

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long ret = 0;
	int sum = 0;
	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		int t;
		cin >> t;

		sum += t;
		sum %= M;
	
		if(sum == 0)
			++ret;
	
		ret += count[sum]++;
	}

	cout << ret << endl;

	return 0;
}
