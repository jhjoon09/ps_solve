#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int N;
pair<double, double> pos[100];
double dst[100][100];
int visit[100];
priority_queue<pair<double, int>, vector<pair<double,int>>, greater<pair<double,int>>> q;

int main(void){
	double ret = 0;
	cin >> N;

	for(int i = 0; i < N; ++i)
		cin >> pos[i].first >> pos[i].second;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			double a = pos[i].first - pos[j].first;
			double b = pos[i].second - pos[j].second;

			dst[i][j] = a*a + b*b;
		}
	}

	visit[0] = 1;
	for(int i = 0; i < N; ++i){
		q.push(make_pair(dst[0][i], i));
	}

	while(!q.empty()){
		double temp = q.top().first;
		int to = q.top().second;
		q.pop();

		if(visit[to] != 0)
			continue;

		visit[to] = 1;	
		ret += sqrt(temp);

		for(int i = 0; i < N; ++i)
			q.push(make_pair(dst[to][i], i));
	}
	cout << fixed;
	cout.precision(2);

	cout << ret << endl;

	return 0;
}
