#include <stdio.h>
#include <string.h>

char sent[1000002];
int que[1000000];
char bomb[37];
int s_length, b_length;

int next_char(int, int);

int main(void)
{
	scanf("%s", sent);
	scanf("%s", bomb);

	s_length = strlen(sent);
	b_length = strlen(bomb);


	for (int i = 0; i < s_length; ++i)
	{

		if(sent[i] == bomb[0])
		{
			if (next_char(i + 1, 1) == 1)
			{
				sent[i] = ' ';
			}
		}
	}

	int	flag = 0;

	for (int i = 0; i < s_length; ++i)
	{
		if (sent[i] != ' ')
		{
			printf("%c", sent[i]);
			flag = 1;
		}
	}

	if (flag == 0)
		printf("FRULA");

	printf("\n");

	return 0;
}

int next_char(int s_pos, int b_pos)
{
	if (b_pos == b_length)
		return 1;

	while (sent[s_pos] == ' ' && s_pos <= s_length)
		++s_pos;

	if (s_pos == s_length)
		return -1;

	if (sent[s_pos] != bomb[b_pos])
	{
		if(sent[s_pos] == bomb[0])
		{
			if(next_char(s_pos, 0) == 1)
			{
				sent[s_pos] = ' ';

				if(next_char(s_pos+1, b_pos) == 1)
					return 1;
			}
		}
		return -1;
	}

	if (sent[s_pos] == bomb[b_pos])
	{
		if (next_char(s_pos + 1, b_pos + 1) == 1)
		{
			sent[s_pos] = ' ';
			return 1;
		}
	}

	return -1;
}
