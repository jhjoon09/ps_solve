#include <iostream>
#include <queue>

using namespace std;

int N,K;
int dp[200001];

int cal(void){
	queue<pair<int,int>> q;
	q.push(make_pair(K,1));

	while(true){
		int pos = q.front().first;
		int count = q.front().second;
		q.pop();
		
		if(dp[pos] != 0)
			continue;

		dp[pos] = count;

		if(pos == N)
			break;

		if(pos < 0 || pos >= 200000)
			continue;

		q.push(make_pair(pos-1, count+1));
		q.push(make_pair(pos+1, count+1));

		if(pos%2 == 0)
			q.push(make_pair(pos/2, count+1));
	}
	
	return 0;	
}

int solve(){
	cal();
	cout << dp[N] -1 << endl;

	int pos = N;
	int count = dp[N];

	while(pos != K){
		cout << pos << " ";
		if(pos * 2 <= 200000){
			if(dp[pos*2] == count-1){
				pos *= 2;
				--count;

				continue;
			}
		}

		if(pos -1 >= 0){
			if(dp[pos-1] == count-1){
				--pos;
				--count;
		
				continue;
			}
		}

		if(pos+1 <= 200000){
			if(dp[pos+1] == count-1){
				++pos;
				--count;

				continue;
			}
		}
	}

	cout << K << endl;

	return 0;
}

int main(void){
	cin >> N >> K;

	solve();

	return 0;
}
