#include <stdio.h>              
#define MAX 100000
#define IND 100

int visit[MAX+1];
int c_index[IND+1];

int main(void)
{
	int G, P;

	scanf("%d %d", &G, &P);

	for(int i = 0; i < IND; ++i)
		c_index[i] = MAX/IND;

	c_index[IND] = 1;

	--c_index[0];

	for(int i = 0; i < P; ++i)
	{
		int gi;
		scanf("%d", &gi);

		while(visit[gi] != 0 && gi%1000 != 0)
			--gi;

		if(visit[gi] != 0)
		{
			--gi;

			while(c_index[gi/1000] == 0)
			{
				gi -= 1000;

				if(gi <= 0)
					break;
			}

			while(visit[gi] != 0 && gi > 0)
				--gi;
		}


		if(gi <= 0)
		{
			printf("%d\n", i);

			return 0;
		}
		else
			visit[gi] = 1;

		--c_index[gi/1000];
	}

	printf("%d\n", P);

	return 0;
}  
