#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

int main(void)
{
	cin.tie(NULL);

	int N, M;

	scanf("%d %d", &N, &M);

	map<int, string> name_pocket;
	unordered_map<string, int> num_pocket;

	for (int i = 1; i <= N; ++i)
	{
		string name;
		cin >> name;

		name_pocket.insert(pair<int, string>(i, name));
		num_pocket.insert(make_pair(name, i));
	}

	for (int i = 0; i < M; ++i)
	{
		string name;

		cin >> name;

		if (isdigit(name[0]) == 1)
		{
			int key = stoi(name);

			cout << name_pocket.find(key)->second << '\n';
		}
		else
		{
			cout << num_pocket[name] << '\n';
		}
	}

	return 0;
}
