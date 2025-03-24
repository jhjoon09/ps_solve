#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int N;
int lst[1000];

int solve(void){
	int end = 0;

	sort(lst, lst+N);

	for(int i = 0; i < N; ++i){
		if(end+1 < lst[i]){
			break;
		}

		end += lst[i];
	}

	return end+1;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> lst[i];

	cout << solve() << endl;

	return 0;
}
