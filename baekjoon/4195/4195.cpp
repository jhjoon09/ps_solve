#include <iostream>
#include <map>

#define MAX 200000
#define endl '\n'

using namespace std;

int group[MAX][2];

int find_parent(int n){
	if(group[n][0] == n)
		return n;
	
	int p = find_parent(group[n][0]);
	group[n][0] = p;

	return p;
}

int make_union(int n1, int n2){
	int p1 = find_parent(n1);
	int p2 = find_parent(n2);

	if(p1 == p2)
		return group[p1][1];

	group[p2][0] = p1;
	group[p1][1] += group[p2][1];

	return group[p1][1];
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T,F;
	cin >> T;
	
	while(--T>=0){
		cin >> F;
		map<string, int> f_map;
		int count = 0;
		for(int i = 0; i < F; ++i){
			int ret = 0;
			int n1,n2;
			string s1,s2;

			cin >> s1 >> s2;
			
			if(f_map.find(s1) == f_map.end()){
				group[count][0] = count;
				group[count][1] = 1;
				f_map.insert(make_pair(s1,count++));
			}

			if(f_map.find(s2) == f_map.end()){
				group[count][0] = count;
				group[count][1] = 1;
				f_map.insert(make_pair(s2,count++));
			}

			n1 = f_map.find(s1)->second;
			n2 = f_map.find(s2)->second;

			ret = make_union(n1,n2);

			cout << ret << endl;
		}
	}	

	return 0;
}
