#include <iostream>
#include <vector>

using namespace std;

int N,K,W;
vector<int> cost;
vector<int> graph[1000];
int dp[1000];

int get_cost(int num){
	if(dp[num] != -1)
		return dp[num];

	int ret = 0;

	for(vector<int>::iterator i = graph[num].begin(); i != graph[num].end(); ++i){
		int temp = get_cost(*i);

		ret = ret > temp ? ret : temp;
	}
	dp[num] = ret + cost[num];
	return dp[num];
}

int solve(void){
	cin >> N >> K;

	cost.clear();
	for(int i = 0; i < N; ++i){
		dp[i] = -1;
		graph[i].clear();

		int t;
		cin >> t;
		cost.push_back(t);
	}

	for(int i = 0; i < K; ++i){
		int a,b;
		cin >> a >> b;
		--a;
		--b;

		graph[b].push_back(a);
	}
	

	cin >> W;
	--W;
	return get_cost(W);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while(--T >= 0){
		cout << solve() << endl;
	}

	return 0;
}
