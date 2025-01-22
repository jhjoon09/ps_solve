#include <iostream>

using namespace std;

int main(void){
	int N;
	int temp;
	long long count[21] = {0 ,};

	cin >> N;
	cin >> temp;

	count[temp] = 1;

	while(--N > 1){
		long long t_count[21] = {0 ,};
		cin >> temp;

		for(int i = 0; i <= 20-temp; ++i){
			if(count[i] == 0)
				continue;


			t_count[i+temp] = count[i];
		}

		for(int i = temp; i <= 20; ++i){
			if(count[i] == 0)
				continue;

			t_count[i-temp] += count[i];
		}
		

		for(int i = 0; i <= 20; ++i)
			count[i] = t_count[i];
	}

	cin >> temp;

	cout << count[temp] << endl;

	return 0;
}
