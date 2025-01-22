#include <iostream>

using namespace std;

int dp[3][10001];

int calNum(int temp){
	if(temp == 1){
		dp[0][1] = 1;
		return 0;
	}

	if(temp == 2){
		dp[0][2] = 1;
		dp[1][2] = 1;

		return 0;
	}

	if(temp == 3){
		dp[0][3] = 1;
		dp[1][3] = 1;
		dp[2][3] = 1;
	
		return 0;
	}

	if(dp[0][temp] != 0)
		return 0;

	calNum(temp-3);
	calNum(temp-2);
	calNum(temp-1);
	
	dp[0][temp] = 1;
	dp[1][temp] = dp[0][temp-2] + dp[1][temp-2];
	dp[2][temp] = dp[0][temp-3] + dp[1][temp-3] + dp[2][temp-3];
	
	return 0;
}

int main(void){
	int T;
	cin >> T;

	while(--T >= 0){
		int temp;

		cin >> temp;

		calNum(temp);

		cout << (dp[0][temp] + dp[1][temp] + dp[2][temp]) << endl;
	}

	return 0;
}
