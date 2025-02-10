#include <iostream>
#include <algorithm>

using namespace std;

int N;
int lst[50];
int dp[50];

int cal(int pos){
	if(pos == N-1)
		return lst[pos];
	
	if(pos >= N)
		return 0;

	if(dp[pos] != 0)
		return dp[pos];

	int a = lst[pos] + cal(pos+1);
	int b = (lst[pos] * lst[pos+1]) + cal(pos+2);

	dp[pos] = a>b ? a : b;

	return dp[pos];
}

int solve(void){
	sort(lst, lst+N);
	return cal(0);
}

int main(void){
	cin >> N;

	for(int i = 0; i < N; ++i)
		cin >> lst[i];

	cout << solve() << endl;

	return 0;
}
