#include<iostream>
#include <vector>

using namespace std;

int N;
vector<int> high;
vector<int> max_high;
int dx[] = {-2, -1, 1, 2};

int input(void){
	high.clear();
	max_high.clear();
	cin >> N;

	for(int i = 0; i < N; ++i){
		int temp;
		cin >> temp;
		high.push_back(temp);
	}

	return 0;
}

int cal(void){
	int ret = 0;

	max_high.push_back(0);
	max_high.push_back(0);

	for(int i = 2; i < N-2; ++i){
		int max = -1;

		for(int j = 0; j < 4; ++j){
			max = max > high[i + dx[j]] ? max : high[i + dx[j]];
		}

		max_high.push_back(max);
	}

	for(int i = 2; i < N-2; ++i){

		if(max_high[i] > high[i])
			continue;

		ret += high[i] - max_high[i];
	}
	
	return ret;	
}

int solve(void){
	input();
	return cal();
}

int main(int argc, char** argv)
{
	int test_case;
	//freopen("input.txt", "r", stdin);
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		cout << "#" << test_case << " " << solve() << endl;
	}
	return 0;
}
