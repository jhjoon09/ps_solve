#include <stdio.h>

char board[100][101];
int key[26];

int h,w;

void init(void);
void init_board(void);
void init_key(void);

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t > 0)
	{
		--t;
		scanf("%d %d", &h, &w);

		init();
	}

	return 0;
}

void init(void)
{
	init_board();
	init_key();
}

void init_board(void)
{
	for(int i = 0; i < h; ++i)
		scanf("%s", board[i]);
}

void init_key(void)
{
	char k_input[27];
	scanf("%s", k_input);

	for(int i = 0; i < 26; ++i)
		key[i] = 0;

	int pos = 0;

	while(k_input[pos] != '\0')
	{
		key[k_input[pos]-'a'] = 1;
		++pos;
	}
}
