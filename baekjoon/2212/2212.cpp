#include <iostream>
#include <algorithm>

using namespace std;

int N,K;
int POS[10000];

int solve(void){
	sort(POS,POS+N);

	for(int i = 0; i < N-1; ++i)
		POS[i] = POS[i+1] - POS[i];

	sort(POS, POS+N-1);

	int ret = 0;

	for(int i = 0; i < N-K; ++i)
		ret += POS[i];

	return ret;
}

int main(void){
	cin >> N >> K;

	for(int i = 0; i < N; ++i){
		cin >> POS[i];
	}

	cout << solve() << endl;

	return 0;
}
