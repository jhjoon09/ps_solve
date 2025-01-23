#include <iostream>
#include <algorithm>

using namespace std;

int N;
int input[2000];

int solve(){
	int count = 0;

	sort(input, input+N);

	for(int i = 0; i < N; ++i){
		int start = 0;
		int end = N-1;

		while(start < end){
			if(start == i){
				++start;
				continue;
			}

			if(end == i){
				--end;
				continue;
			}

			if(input[start] + input[end] == input[i]){
				++count;
				break;
			}

			if(input[start] + input[end] < input[i])
				++start;
			else
				--end;
		}
	}
	
	return count;
}

int main(void){
	cin >> N;

	for(int i = 0; i < N; ++i)
		cin >> input[i];

	cout << solve() << endl;

	return 0;
}
