#include <iostream>
#include <queue>
#include <array>

#define MAX 100000

using namespace std;

struct cmp{

	bool operator()(const array<int,3> a, const array<int,3> b){
		if(a[2] == b[2]){
			if(a[0] == b[0]){
				return a[1] > b[1];
			}

			return a[0] > b[0];
		}

		return a[2] > b[2];
	}
};

int N,M;
priority_queue<array<int,3>, vector<array<int,3>>, cmp> pq;
int group[MAX];

int find_parent(int a){
	if(group[a] == a)
		return a;

	int p = find_parent(group[a]);

	group[a] = p;

	return p;
}

int make_union(int a, int b){
	int p1 = find_parent(a);
	int p2 = find_parent(b);

	if(p1 == p2)
		return 0;
	
	group[p1] = p2;

	return 1;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count;
	int sum = 0;
	cin >> N >> M;
	count = N;

	for(int i = 0; i < N; ++i)
		group[i] = i;

	for(int i = 0; i < M; ++i){
		int a,b,c;
		cin >> a >> b >> c;
		
		pq.push({a-1,b-1,c});
	}

	while(count > 2){
		array<int,3> t = pq.top();
		pq.pop();

		int ret = make_union(t[0], t[1]);
		count -= ret;
		sum += (ret * t[2]);
	}

	cout << sum << endl;

	return 0;
}
