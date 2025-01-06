#include <stdio.h>

int main(void)
{
	int n;
	int heal[20];
	int happ[20];
	int most[100] = {0, };

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", heal + i);

	for(int i = 0; i < n; ++i)
		scanf("%d", happ + i);

	for(int i = 0; i < n; ++i)
	{

		if(heal[i] >= 100)
			continue;

		for(int j = 99; j >= 0; --j)
		{
			if(j + heal[i] >= 100)
				continue;

			if(most[j] + happ[i] > most[ j + heal[i]])
				most[j + heal[i] ] = most[j] + happ[i];
		}

		if(most[ heal[i] ] < happ[i] )
			most[heal[i]] = happ[i];
	}

	int result = 0;

	for(int i = 0; i <= 99; ++i)
	{
		if(result < most[i])
			result = most[i];
	}

	printf("%d\n", result);

	return 0;
}
