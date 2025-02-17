#include <iostream>
#include <vector>

using namespace std;

int N;
int cost[500];
int dp[500];
vector<int> graph[500];

int solve(int pos){
	if(dp[pos] != 0)
		return dp[pos];

	int max = 0;

	for(int i = 0; i < graph[pos].size(); ++i){
		int temp = solve(graph[pos][i]);

		max = max > temp ? max : temp;
	}

	dp[pos] = cost[pos] + max;

	return dp[pos];
}

int main(void){
	cin >> N;
	
	for(int i = 0; i < N; ++i){
		cin >> cost[i];

		int temp;
		cin >> temp;
		while(temp != -1){
			graph[i].push_back(temp-1);
			cin >> temp;
		}	
	}

	for(int i = 0; i < N; ++i)
		cout << solve(i) << endl;

	return 0;
}
