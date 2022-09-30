#include <stdio.h>
#include <string.h>
#define DIV 1000000

int main(void)
{
	char passwd[5001] = {0, };
	int count[5001] = {0 ,};
	scanf("%s", passwd);

	if(passwd[0] == '0')
	{
		printf("0\n");
		return 0;
	}

	int length = strlen(passwd);

	if(passwd[length-1] != '0')
		count[length-1] = 1;
	else
		count[length-1] = 0;

	count[length] = 1;

	for(int i = length-2; i >= 0; --i)
	{
		if(passwd[i] == '0')
		{
			count[i] = 0;
		}
		else if(passwd[i] == '1')
		{
			count[i] = (count[i+1] + count[i+2]) % DIV;
		}
		else if(passwd[i] == '2')
		{
			if(passwd[i+1] >= '0' && passwd[i+1] <= '6')
				count[i] = (count[i+1] + count[i+2]) % DIV;
			else
				count[i] = count[i+1];
		}
		else
		{
			count[i] = count[i+1];
		}
	}

	printf("%d\n", count[0]);

	return 0;
}
