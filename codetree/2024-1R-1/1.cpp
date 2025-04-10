#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

struct Trip{
	int id;
	int revenue;
	int dest;
	int benefit;

	bool operator<(const Trip t) const{
		if(this->benefit  == t.benefit)
			return this->id > t.id;

		return (this->benefit < t.benefit);
	}
};


priority_queue<Trip> pq;
int cost[2000][2000];
int lst[30001];
int N,M;
int S;

struct cmp{
	bool operator()(pair<int,int> a, pair<int,int> b){
		if(a.second == b.second)
			return a.second > b.second;

		return a.second > b.second;
	}
};

int cal_cost(int s){
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
	int visit[2000] = {0, };
	visit[s] = 1;

	for(int i = 0; i < N; ++i){
		if(i == s)
			continue;
		if(cost[s][i] == INF)
			continue;

		pq.push({i, cost[s][i]});
	}

	while(!pq.empty()){
		pair<int,int> temp = pq.top();
		pq.pop();

		if(visit[temp.first] == 1)
			continue;

		visit[temp.first] = 1;

		for(int i = 0; i < N; ++i){
			if(visit[i] != 0)
				continue;

			if(cost[s][i] < temp.second + cost[temp.first][i])
				continue;

			cost[s][i] = temp.second + cost[temp.first][i];

			pq.push({i, cost[s][i]});
		}
	}

	return 0;
}

int make_trip(void){
	Trip t;
	cin >> t.id >> t.revenue >> t.dest;

	lst[t.id] = 1;
	t.benefit = t.revenue - cost[S][t.dest];

	pq.push(t);

	return 0;
}

int cancel_trip(void){
	int id;
	cin >> id;
	lst[id] = 0;
	return 0;
}

int sell_trip(void){
	if(pq.empty())
		return -1;

	int id = -1;

	while(!pq.empty()){
		if(pq.top().benefit < 0)
			break;

		if(lst[pq.top().id] == 0){
			pq.pop();
			continue;
		}

		id = pq.top().id;
		pq.pop();

		break;
	}

	return id;
}

int change_trip(void){
	priority_queue<Trip> nq;
	cin >> S;
	cal_cost(S);
	swap(nq, pq);

	while(!nq.empty()){
		Trip t = nq.top();
		nq.pop();
		
		if(lst[t.id] == 0)
			continue;
	
		t.benefit = t.revenue - cost[S][t.dest];
		pq.push(t);
	}

	return 0;
}

int main(void){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int Q;
	int op;
	cin >> Q;
	cin >> op >> N >> M;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(i == j)
				continue;
			cost[i][j] = INF;
		}
	}

	for(int i = 0; i < M; ++i){
		int u,v,w;

		cin >> u >> v >> w;

		if(cost[u][v] <= w)
			continue;

		cost[u][v] = w;
		cost[v][u] = w;
	}

	cal_cost(0);

	while(--Q > 0){
		cin >> op;
		switch(op/100){
			case 2:
				make_trip();
				break;
			case 3:
				cancel_trip();
				break;
			case 4:
				cout << sell_trip() << endl;
				break;
			case 5:
				change_trip();
				break;
		}
	}

	return 0;
}
