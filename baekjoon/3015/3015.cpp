#include <iostream>
#include <stack>

using namespace std;

int N;

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<pair<int,int>> st;
	long long ret = 0;

	cin >> N;

	for(int i = 0; i < N; ++i){
		int temp;

		cin >> temp;

		while(!st.empty()){
			if(st.top().first >= temp)
				break;

			ret += st.top().second;
			st.pop();
		}

		if(st.empty()){
			st.push({temp,1});
			continue;
		}


		if(st.top().first == temp){
			ret += st.top().second;
			if(st.size() > 1)
				ret++;

			st.top().second++;
		}
		else{
			ret++;
			st.push({temp,1});
		}

	}

	cout << ret << endl;

	return 0;
}
