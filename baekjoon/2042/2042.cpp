#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N,M,K;
vector<long long> tree;
vector<long long> lst;

long long make_tree(int pos, int s, int e){
	if(s == e){
		tree[pos] = lst[s];
		return tree[pos];
	}

	int mid = (s+e) / 2;

	long long temp = make_tree(pos*2, s, mid) + make_tree(pos*2+1,mid+1, e);

	tree[pos] = temp;

	return temp;
}

int replace(int pos, int start, int end, int index, long long diff){
	if(index < start || index > end)
		return 0;

	tree[pos] += diff;

	if(start != end){
		int mid = (start + end)/2;
		replace(pos*2, start, mid, index, diff);
		replace(pos*2+1, mid+1, end, index, diff);
	}

	return 0;
}

long long sum(int pos, int start, int end, int left, int right){
	if(left > end || right < start)
		return 0;

	if(left <= start && end <= right)
		return tree[pos];

	int mid = (start + end) / 2;

	return sum(pos*2, start, mid, left, right) + sum(pos*2+1, mid+1, end, left, right);
}

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;

	for(int i = 0; i < N; ++i){
		long long temp;
		cin >> temp;
		lst.push_back(temp);
	}

	int h = ceil(log2(N));
	int size = 1 << (h+1);

	tree.resize(size);
	make_tree(1, 0, N-1);

	for(int i = 0; i < M + K; ++i){
		int a,b;
		long long c;

		cin >> a >> b >> c;

		if(a == 1){
			long long diff = c - lst[b-1];
			lst[b-1] = c;
			replace(1, 0, N-1, b-1, diff );
		}else{
			cout << sum(1, 0, N-1, b-1,c-1) << endl;
		}
	}

	return 0;
}
