#include <stdio.h>
#include <string.h>

int main(void)
{
	int m;
	char oper[10];
	int input;
	int set[20] = {0 ,};

	scanf("%d", &m);

	for(int i = 0; i < m; ++i)
	{
		scanf("%s", oper);

		if(strcmp(oper, "add") == 0)
		{
			scanf("%d", &input);
			if(set[input-1] == 0)
				set[input-1] = 1;
		}
		else if(strcmp(oper, "remove") == 0)
		{
			scanf("%d", &input);
			if(set[input-1] != 0)
				set[input-1] = 0;
		}
		else if(strcmp(oper, "check") == 0)
		{
			scanf("%d", &input);

			if(set[input-1] != 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if(strcmp(oper, "toggle") == 0)
		{
			scanf("%d", &input); 
			if(set[input-1] != 0)
				set[input-1] = 0;
			else
				set[input-1] = 1;
		}
		else if(strcmp(oper, "all") == 0)
		{
			for(int i = 0; i < 20; ++i)
				set[i] = 1;
		}
		else
		{
			for(int i = 0; i < 20; ++i)
				set[i] = 0;
		}

	}

	return 0;
}
