#include <iostream>
#include <cmath>

#define endl '\n'

using namespace std;

int N,Q;
long long* lst;
long long* tree;

long long make_tree(int pos, int start, int end){
	if(start == end){
		tree[pos] = lst[start];
	}else{
		int mid = (start + end) / 2;
		tree[pos] = make_tree(pos*2, start, mid) + make_tree(pos*2+1, mid+1, end);
	}

	return tree[pos];
}

long long find(int pos, int start, int end, int left, int right){
	if(left > end || right < start)
		return 0;

	if(left <= start && right >= end)
		return tree[pos];

	int mid = (start + end) / 2;
	
	return find(pos*2, start, mid, left, right) + find(pos*2+1, mid+1, end, left, right);

}

int update(int pos, int start, int end, int idx, long long diff){
	if(idx < start || idx > end)
		return 0;

	tree[pos] += diff;

	if(start == end)
		return 0;

	int mid = (start + end) / 2;
	update(pos*2, start, mid, idx, diff);
	update(pos*2 + 1, mid+1, end, idx, diff);

	return 0;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> Q;

	lst = new long long[N];
	int h = ceil(log2(N));
	int size = 1 << (h+1);
	tree = new long long[size];

	for(int i = 0; i < N; ++i)
		cin >> lst[i];

	make_tree(1, 0, N-1);

	for(int i = 0; i < Q; ++i){
		int x,y,a,b;
		long long ret;
		cin >> x >> y >> a >> b;
		
		if(x > y)
			ret = find(1, 0, N-1, y-1, x-1);
		else
			ret = find(1, 0, N-1, x-1, y-1);
	
		cout << ret  << endl;
		long long diff = b - lst[a-1];
		lst[a-1] = b;
		update(1, 0, N-1, a-1, diff);
	}

	delete(lst);
	delete(tree);

	return 0;
}
