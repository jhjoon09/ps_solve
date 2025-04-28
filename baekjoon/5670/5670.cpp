#include <iostream>
#include <vector>
#include <unordered_map>

#define endl '\n'

using namespace std;

struct Tree{
	bool is_end;
	unordered_map<char, Tree*> child;

	void insert(string st){
		Tree* temp = this;

		for(int i = 0; i < st.size(); ++i){
			if(temp->child[st[i]] == nullptr)
				temp->child[st[i]] = new Tree{false, {}};

			temp = temp->child[st[i]];
		}

		temp->is_end = true;

		return;
	}

	int get_count(int num){
		int ret = 0;

		if(is_end){
			ret += num;
		}
		if(child.size() > 1 || is_end)
			++num;

		if(num == 0)
			num = 1;

		for(auto c : child){
			ret += c.second->get_count(num);
		}

		return ret;
	}
};

int N;
vector<string> lst;

int solve(void){
	Tree t = {false, {}};

	for(auto st : lst){
		t.insert(st);
	}

	return t.get_count(0);
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while(cin >> N){
		lst.clear();
		lst.resize(N);

		for(int i = 0; i < N; ++i)
			cin >> lst[i];

		int count = solve();
		cout << fixed;
		cout.precision(2);
		cout << (double)count / N << endl;
	}

	return 0;
}
