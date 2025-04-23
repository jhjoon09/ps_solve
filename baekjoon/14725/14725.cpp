#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<vector<string>> lst;

/*
struct cmp{
	bool operator()(vector<string> a, vector<string> b){
		int len = min(a.size(), b.size());

		for(int i = 0; i < len; ++i){
			if(a[i] == b[i])
				continue;

			return a[i] > b[i];
		}

		if(a.size() > b.size())
			return true;

		return false;
	}
};
*/

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	while(--N >= 0){
		int a;
		vector<string> b;
		cin >> a;

		while(--a >= 0){
			string t;
			cin >> t;

			b.push_back(t);
		}

		lst.push_back(b);
	}

	sort(lst.begin(), lst.end());

	for(int i = 0; i < lst[0].size(); ++i){
		for(int j = 0; j < i; ++j)
			cout << "--";

		cout << lst[0][i] << endl;
	}

	for(int i = 1; i < lst.size(); ++i){
		int count = 0;
		int len = min(lst[i-1].size(), lst[i].size());
		for(;count < len; ++count){
			if(lst[i-1][count] != lst[i][count])
				break;
		}

		for(; count < lst[i].size(); ++count){
			for(int j = 0; j < count; ++j)
				cout << "--";

			cout << lst[i][count] << endl;
		}
	}

	return 0;
}
