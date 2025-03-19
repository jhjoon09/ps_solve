#include <iostream>
#include <climits>
#include <cmath>

#define endl '\n'

using namespace std;

int N,M;
int* lst;
pair<int,int>* tree;

pair<int,int> make_tree(int pos, int start, int end){
	if(start == end){
		tree[pos].first = lst[start];
		tree[pos].second = lst[start];
	}else{
		int mid = (start + end) / 2;
		pair<int,int> a = make_tree(pos*2, start, mid);
		pair<int,int> b = make_tree(pos*2+1, mid+1, end);
		tree[pos].first = a.first > b.first ? a.first : b.first;
		tree[pos].second = a.second > b.second ? b.second : a.second;
	}
	return tree[pos];
}

pair<int,int> find(int pos, int start, int end, int left, int right){
	if(left > end || right < start)
		return make_pair(0, INT_MAX);

	if(left <= start && right >= end)
		return tree[pos];

	int mid = (start+end)/2;

	pair<int,int> l = find(pos*2, start, mid, left, right);
	pair<int,int> r = find(pos*2+1, mid+1, end, left, right);
	pair<int,int> ret;
	ret.first = l.first > r.first ? l.first : r.first;
	ret.second = l.second > r.second ? r.second : l.second;
	return ret;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	lst = new int[N];

	int h = ceil(log2(N));
	int size = 1 << (h+1);
	tree = new pair<int,int>[size];

	for(int i = 0; i < N; ++i){
		cin >> lst[i];
	}

	make_tree(1,0,N-1);

	for(int i = 0; i < M; ++i){
		int a,b;
		cin >> a >> b;
		pair<int,int> ret = find(1,0,N-1,a-1,b-1);
		cout << ret.second << " " << ret.first << endl;
	}

	delete(lst);
	delete(tree);
	return 0;
}
