#include <iostream>
#include <climits>

#define endl '\n'

using namespace std;

struct SegTree{
	int start, end;
	pair<int,int> val;
	SegTree* left;
	SegTree* right;

	int set(int pos, int data){
		if(pos < start || end < pos)
			return 0;

		if(start == end){
			val = {start, data};
			return 1;
		}

		int mid = (start + end)/2;

		if(pos <= mid){
			if(left == NULL)
				left = new SegTree{start, mid, {INT_MAX, INT_MAX}, NULL, NULL};

			left->set(pos,data);
		}else{
			if(right == NULL)
				right = new SegTree{mid+1, end, {INT_MAX, INT_MAX}, NULL, NULL};

			right->set(pos,data);
		}

		pair<int,int> ret = {INT_MAX, INT_MAX};

		if(right != NULL){
			pair<int,int> a = right->val;
			if(a.second <= ret.second)
				ret = a;
		}

		if(left != NULL){
			pair<int,int> a = left->val;
			if(a.second <= ret.second)
				ret = a;
		}

		val = ret;

		return 1;
	}

	pair<int,int> get(int s, int e){
		if(e < start || end < s)
			return {INT_MAX, INT_MAX};

		if(s <= start && end <= e)
			return val;

		if(start == end)
			return val;

		pair<int,int> ret = {INT_MAX, INT_MAX};

		if(right != NULL){
			pair<int,int> a = right->get(s,e);
			if(a.second <= ret.second)
				ret = a;
		}

		if(left != NULL){
			pair<int,int> a = left->get(s,e);

			if(a.second <= ret.second)
				ret = a;
		}

		return ret;
	}

	void print(void){
		cout << "start : " << start << " end : " << end << " val : {" << val.first << "," << val.second << "}\n";

		if(left != NULL)
			left->print();

		if(right != NULL)
			right->print();

		return;
	}
};

int main(void){
	int N,M;
	SegTree seg;
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	seg = {1, N, {INT_MAX, INT_MAX}, NULL, NULL};

	for(int i = 1; i <= N; ++i){
		int t;
		cin >> t;
		seg.set(i, t);
	}

	cin >> M;

	for(int i = 0; i < M; ++i){
		int a,b,c;

		cin >> a >> b >> c;

		if(a == 1)
			seg.set(b,c);
		else
			cout << seg.get(b,c).first << endl;
	}

	return 0;
}
