#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> dp;
vector<int> lst;
vector<stack<int>> t;

int b_search(int val){
	int start = 0;
	int end = t.size()-1;
	int mid;

	while(start < end){
		mid = (start+end) / 2;

		if(t[mid].top() < val)
			start = mid+1;
		else
			end = mid;
	}

	return end;
}

int make_dp(void){
	stack<int> st;
	st.push(lst[0]);
	t.push_back(st);

	dp.push_back(0);
	for(int i = 1; i < lst.size(); ++i){
		int idx = 0;

		if(t.back().top() < lst[i]){
			idx = t.size();
			stack<int> st1;
			st1.push(lst[i]);
			t.push_back(st1);
		}else{
			idx = b_search(lst[i]);
			t[idx].push(lst[i]);
		}

		dp.push_back(idx);
	}

	return 0;
}

int add(void){
	int h;
	int idx = 0;
	cin >> h;

	if(t.back().top() < h){
		idx = t.size();
		stack<int> st;
		st.push(h);
		t.push_back(st);
	}else{
		idx = b_search(h);
		t[idx].push(h);
	}

	lst.push_back(h);
	dp.push_back(idx);

	return 0;
}

int remove(void){
	int idx = dp.back();
	t[idx].pop();
	if(t[idx].empty())
		t.pop_back();

	lst.pop_back();
	dp.pop_back();

	return 0;
}

long long simulate(void){
	long long ret = 0;
	int m_index;
	cin >> m_index;

	int max = t.size();
	stack<int> st = t.back();
	int max_h = st.top();

	while(!st.empty()){
		max_h = max_h > st.top() ? max_h : st.top();
		st.pop();
	}

	ret += (dp[m_index-1] + max);
	ret *= 1000000;
	ret += max_h;

	return ret;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Q;
	int op;
	cin >> Q;

	cin >> op >> n;

	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		lst.push_back(temp);
	}

	make_dp();

	while(--Q > 0){
		cin >> op;

		switch(op){
			case 200:
				add();
				break;
			case 300:
				remove();
				break;
			case 400:
				cout << simulate() << endl;
				break;
		}

	}

	return 0;
}

