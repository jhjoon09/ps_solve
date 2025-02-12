#include <iostream>


#define INF 987654321

using namespace std;

int N;
int page[500];
int sum[500];
int dp[500][500];

int solve(int start, int end){
	int min = INF;
	int file = sum[end] - sum[start] + page[start];

	if(dp[start][end] != 0)
		return dp[start][end];

	if(start == end)
		return 0;

	for(int i = start; i < end; ++i){
		int temp = solve(start, i) + solve(i+1, end) + file;

		min = min < temp ? min : temp;
	}	
	
	dp[start][end] = min;

	return min;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;

	while(--T >= 0){
		cin >> N;

		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j)
				dp[i][j] = 0;
		}

		for(int i = 0; i < N; ++i){
			cin >> page[i];
			sum[i] = page[i];

			if(i >= 1)
				sum[i] += sum[i-1];
		}
		cout << solve(0, N-1) << endl;
	}

	return 0;
}
