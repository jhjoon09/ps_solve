#include <iostream>
#include <cmath>

#define endl '\n'
#define DIV 1000000007
using namespace std;

long long* lst;
long long* tree;

long long build_tree(int pos, int start, int end){
	if(start == end){
		tree[pos] = lst[start];
	}else{
		int mid = (start + end) / 2;
		long long t1 = build_tree(pos*2, start, mid);
		long long t2 = build_tree(pos*2+1, mid+1, end);

		tree[pos] = t1 * t2 % DIV;
	}

	return tree[pos];
}

long long update(int pos, int start, int end, int idx, int n){
	if(idx < start || end < idx)
		return tree[pos];
	

	if(start == end){
		tree[pos] = n;
		return tree[pos];
	}

	int mid = (start + end) / 2;

	long long t1 = update(pos*2, start, mid, idx, n);
	long long t2 = update(pos*2+1, mid+1, end, idx, n);

	tree[pos] = t1 * t2 % DIV;
	return tree[pos];
}

long long mul(int pos, int start, int end, int left, int right){
	if(right < start || end < left)
		return 1;

	if(left <= start && end <= right)
		return tree[pos];

	int mid = (start + end)/2;

	long long t1 = mul(pos*2, start, mid, left, right);
	long long t2 = mul(pos*2+1, mid+1, end, left, right);

	return t1 * t2 % DIV;
}

int main(void){
	int N,M,K;

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;

	lst = new long long[N];
	int h = ceil(log2(N));
	int size = 1 << (h+1);
	tree = new long long[size];

	for(int i = 0; i < N; ++i)
		cin >> lst[i];

	build_tree(1, 0, N-1);

	for(int i = 0; i < M+K; ++i){
		int a,b,c;

		cin >> a >> b >> c;
		
		if(a == 1){
			update(1, 0, N-1, b-1, c);
			lst[b-1] = c;
		}else{
			cout << mul(1, 0, N-1, b-1,c-1) << endl;
		}
	}

	delete(lst);
	delete(tree);

	return 0;
}
