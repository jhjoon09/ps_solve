#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
int W;
vector<pair<int,int>> lst;

int dp[1002][1002];

int cal_length(int n1, int n2){
	pair<int,int> p1 = lst[n1];
	pair<int,int> p2 = lst[n2];

	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int cal_move(int pos, int p1, int p2){
	if(pos >= W)
		return 0;

	if(dp[p1][p2] != 0)
		return dp[p1][p2];
	
	int r1 = cal_move(pos+1, pos, p2) + cal_length(p1, pos);
	int r2 = cal_move(pos+1, p1, pos) + cal_length(p2, pos);

	dp[p1][p2] = r1 > r2 ? r2 : r1;

	return dp[p1][p2];
}

int trace_dp(int val){
	int p1 = W;
	int p2 = W+1;
	int pos = 0;

	while(pos < W){
		if(dp[p1][p2] == dp[pos][p2] + cal_length(p1, pos)){
			cout << "1\n";
			p1 = pos;
		}else{
			cout <<"2\n";
			p2 = pos;
		}

		++pos;
	}

	return 0;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> W;
	lst.resize(W);

	for(int i = 0; i < W; ++i)
		cin >> lst[i].first >> lst[i].second;

	lst.push_back({1,1});
	lst.push_back({N,N});

	int ret = cal_move(0, W, W+1);

	cout << ret << endl;

	trace_dp(ret);	

	return 0;
}
