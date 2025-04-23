#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 500000

using namespace std;

struct SegTree{
	int start,end;
	int count;
	SegTree* left;
	SegTree* right;

	int add(int n){
		if(n < start || end < n)
			return 0;

		++count;

		if(start == end)
			return 1;

		int mid = (start + end)/2;

		if(n <= mid){
			if(left == NULL)
				left = new SegTree({start, mid, 0, NULL, NULL});

			left->add(n);
		}else{
			if(right == NULL)
				right = new SegTree({mid+1, end, 0, NULL, NULL});

			right->add(n);
		}

		return 0;
	}

	int get(int n){
		if(n <= start)
			return count;

		if(end < n)
			return 0;

		if(start == end)
			return count;

		int ret = 0;

		if(left != NULL)
			ret += left->get(n);

		if(right != NULL)
			ret += right->get(n);

		return ret;
	}
};

int N;
vector<int> lst;
vector<pair<int,int>> m;

int b_search(int val){
	int start = 0;
	int end = m.size()-1;

	while(start < end){
		int mid = (start+end)/2;

		if(m[mid].first == val)
			return m[mid].second;

		if(m[mid].first < val){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}

	return m[end].second;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	SegTree seg = {0, MAX, 0, NULL, NULL};
	cin >> N;

	for(int i = 0; i < N; ++i){
		int t;
		cin >> t;
		m.push_back({t,i});
	}

	sort(m.begin(), m.end());

	for(int i = 0; i < N; ++i){
		int t;
		cin >> t;
		int r = b_search(t);
		lst.push_back(r);
	}

	long long ret = 0;

	for(int i = 0; i < N; ++i){
		ret += seg.get(lst[i]);
		seg.add(lst[i]);
	}

	cout << ret << endl;

	return 0;
}
