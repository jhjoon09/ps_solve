#include <stdio.h>
#include <string.h>

char sent[1000001];
char bomb[40];

int compare(int, int);

int main(void)
{
	scanf("%s", sent);
	scanf("%s", bomb);

	int b_length = strlen(bomb);

	int pos = b_length - 1;
	int temp = b_length - 1;

	while (sent[pos] != '\0')
	{
		sent[temp] = sent[pos];

		if (temp >= b_length - 1)
		{
			if (compare(temp - (b_length - 1), b_length) == 1)
			{
				temp -= b_length;
			}
		}

		++pos;
		++temp;
	}


	sent[temp] = '\0';

	if (sent[0] == '\0')
		printf("FRULA\n");
	else
		printf("%s\n", sent);

	return 0;
}

int compare(int pos, int length)
{
	for (int i = 0; i < length; ++i)
	{
		if (sent[pos + i] != bomb[i])
			return 0;
	}

	return 1;
}
