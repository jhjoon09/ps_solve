#include <iostream>

#define endl '\n'
#define MAX 100000

using namespace std;

int tree[MAX * 8];
int lst[MAX];

int sum(int start, int end, int node, int left, int right){
	if(left <= start && end <= right)
		return tree[node];

	if(end < left || right < start)
		return 0;

	if(start == end)
		return tree[node];

	int mid = (start + end)/2;

	return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

int update(int start, int end, int node, int idx, int val){
	if(idx < start || end < idx)
		return 0;
	
	int mid = (start + end)/2;
	int ret = 0;

	tree[node] += val;

	if(start == end)
		return 0;
	
	update(start, mid, node*2, idx, val);
	update(mid+1, end, node*2+1, idx, val);

	return 0;
}

int init(int start, int end, int node, int N, int M){
	if(start == end){
		if(start < N)
			tree[node] = 1;
		else
			tree[node] = 0;

		return tree[node];
	}
	
	int mid = (start+end) / 2;

	int ret = init(start, mid, node*2, N,M);
	ret += init(mid+1, end, node*2+1, N, M);

	tree[node] = ret;
	return ret;
}

void print_tree(int start, int end, int node){
	cout << "start : " << start << " end : " << end << " val : " << tree[node] << endl;

	if(start == end)
		return;

	int mid = (start + end)/2;

	print_tree(start, mid, node*2);
	print_tree(mid+1, end, node*2+1);

	return;
}

void solve(void){
	int N,M;

	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		lst[i] = N-i-1;
	}

	init(0, N+M, 1, N,M);

	for(int i = 0; i < M; ++i){
		int val;
		cin >> val;
		--val;

		int ret = sum(0, N+M, 1, lst[val], N+M);

		update(0, N+M, 1, lst[val], -1);
		update(0, N+M, 1, N+i, 1);

		lst[val] = N+i;

		cout << ret-1 << " ";
	}

	cout << endl;
	return;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while(--T >= 0){
		solve();
	}

	return 0;
}
