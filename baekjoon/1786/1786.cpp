#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

vector<int> get_lst(string T){
	vector<int> ret;

	int count = 0;
	ret.push_back(0);

	for(int i = 1; i < T.size(); ++i){
		while(T[i] != T[count] && count > 0){
			count = ret[count-1];
		}

		if(T[i] == T[count])
			++count;
		else
			count = 0;
		
		ret.push_back(count);
	}

	return ret;
}

vector<int> solve(string P, string T){
	vector<int> ret;
	vector<int> lst = get_lst(T);

	int count = 0;

	for(int i = 0; i < P.size(); ++i){
		while(P[i] != T[count] && count > 0)
			count = lst[count-1];

		if(P[i] == T[count])
			++count;

		if(count == T.size()){
			ret.push_back(i - count + 2);
			count = lst[count-1];
		}
	}

	return ret;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string P;
	string T;

	getline(cin, P);
	getline(cin, T);

	vector<int> answer = solve(P,T);

	cout << answer.size() << endl;

	for(auto i : answer)
		cout << i << " ";

	cout << endl;

	return 0;
}
